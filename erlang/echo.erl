#!/usr/bin/env escript
%% echo server

main(_Args) ->
    io:format("echo service by Erlang~n"),
    server(9000).

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
            gen_tcp:send(Socket, Data),
            echo_loop(Socket);
        {tcp_closed, Socket} ->
            gen_tcp:close(Socket)
    end.
