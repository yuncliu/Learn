-module(hs).
-export([start/2]).

start(Port, Path)->
    server(Port, Path).

server(Port, Path) ->
    io:format("port ~p ~n",[Port]),
    case gen_tcp:listen(Port, [binary, {packet, raw}, {active, true}, {reuseaddr, true}]) of
        {ok, ListenPort} ->
            loop(ListenPort, Path);
        {error, Reason} ->
            {error, Reason}
    end.

loop(ListenPort, Path) ->
    case gen_tcp:accept(ListenPort) of
        {ok, Socket}->
            Pid = spawn(fun() -> echo_loop(Socket, Path) end),
            gen_tcp:controlling_process(Socket, Pid),
            loop(ListenPort, Path);
        {error, Reason} ->
            io:format('accept failed due to ~w~n', [Reason]),
            loop(ListenPort, Path)
    end.

echo_loop(Socket, Path) ->
    receive
        {tcp, Socket, Data} ->
            Request = request(Data),
            Html = get_html(Request, Path),
            gen_tcp:send(Socket, Html),
            echo_loop(Socket, Path);
        {tcp_closed, Socket} ->
            gen_tcp:close(Socket)
    end.

get_header_kv([], Headers) ->
    Headers;
get_header_kv(Str, Headers) ->
    [Head| Tail] = Str,
    %%"Host: localhost:8080" this may have several :
    %% So there may be a list, Key is only the first element
    %% then join the last elements as Value
    [Key| Value_list] = string:tokens(Head, ":"),
    Value = string:join(Value_list, ":"),
    get_header_kv(Tail, dict:append(Key, string:strip(Value), Headers)).

request(Data)->
    Header = binary_to_list(Data),
    Tokens = string:tokens(Header, "\r\n"),
    [Head| Tail] = Tokens,
    Headers= dict:new(),
    %% first is like this "GET / HTTP/1.1"
    [Method, Path, Protocol] = string:tokens(Head, " "),
    Headers1 = dict:append("method", Method, Headers),
    Headers2 = dict:append("path", Path, Headers1),
    Headers3 = dict:append("protocol", Protocol, Headers2),
    get_header_kv(Tail, Headers3).

read_file(CurrentDirectory, Path) ->
    io:format("~s is a file~n", [Path]),
    case file:open(CurrentDirectory ++ Path, [read]) of
        {ok, Device} ->
            {"200", get_all_lines(Device)};
        {error, _} ->
            io:format("open failed~n"),
            {"404", "404"}
    end.

get_all_lines(Device) ->
    case io:get_line(Device, "") of
        eof  -> [];
        Line ->
            Line ++ get_all_lines(Device)
    end.


read_dir(Root, Path)->
    [PathOutOfList] = Path,
    io:format("~s is a file~n", [PathOutOfList]),
    HtmlPath = case PathOutOfList of
         "/" ->
           "";
         _ ->
           PathOutOfList
    end,
    List = case file:list_dir(Root ++ Path) of
         {ok, Filenames}->
            %HtmlPath = string:strip(Path, left, $/),
            string:join(["<li><a href="++HtmlPath ++"/"++XX++">"++XX++"</a></li>"|| XX<-Filenames], "\r\n");
         {error, Reason}->
            io:format("error ~s~n", [Reason]),
            {"404", "404"}
    end,
    {"200", "<html><head></head><body>"++"<ul>"++List++"</ul>"++"</body></html>"}.

read_path(Path, Root) ->
    AbsolutePath = Root ++ Path,
    case filelib:is_dir(AbsolutePath) of
        true ->
            read_dir(Root, Path);
        false ->
            read_file(Root, Path)
    end.

get_html(Request, Root)->
    {_, Path} = dict:find("path", Request),
    {Code, Text} = read_path(Path, Root),
    Len = string:len(Text),
    io:format("Path is ~s~n", [Path]),
    "HTTP/1.1 "++ Code ++" OK\r\nContent-Length: "++integer_to_list(Len)++ "\r\n\r\n" ++ Text.
