#!/usr/bin/env escript
%% echo server

main(_Args) ->
    io:format("echo service by Erlang~n"),
    server(8080).

server(Port) ->
    io:format("port ~p ~n",[Port]),
    case gen_tcp:listen(Port, [binary, {packet, raw}, {active, true}, {reuseaddr, true}]) of
        {ok, ListenPort} ->
            loop(ListenPort);
        {error, Reason} ->
            {error, Reason}
    end.

loop(ListenPort) ->
    case gen_tcp:accept(ListenPort) of
        {ok, Socket}->
            Pid = spawn(fun() -> echo_loop(Socket) end),
            gen_tcp:controlling_process(Socket, Pid),
            loop(ListenPort);
        {error, Reason} ->
            io:format('accept failed due to ~w~n', [Reason]),
            loop(ListenPort)
    end.

echo_loop(Socket) ->
    receive
        {tcp, Socket, Data} ->
            Request = mylib:request(Data),
            dict:map(fun(Key, Value)-> io:format("key = [~s], value = [~s]~n", [Key, Value]) end, Request),
            Text = readfile("1.html"),
            Len = string:len(Text),
            Html = "HTTP/1.1 200 OK\r\nContent-Length: "++integer_to_list(Len)++ "\r\n\r\n" ++ Text,
            %Len = string:len(Html),
            %Ht = string:substr(Html, 1, Len-1),
            gen_tcp:send(Socket, Html),
            echo_loop(Socket);
        {tcp_closed, Socket} ->
            gen_tcp:close(Socket)
    end.

readfile(FileName) ->
    case file:open(FileName, [read]) of
        {ok, Device} ->
            get_all_lines(Device);
        {error, _} ->
            []
    end.

get_all_lines(Device) ->
    case io:get_line(Device, "") of
        eof  -> [];
        Line ->
            Line ++ get_all_lines(Device)
    end.
