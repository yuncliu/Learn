-module(mylib).
-export([request/1, get_html/1]).

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

read_dir(CurrentDirectory, Path)->
    List = case file:list_dir(CurrentDirectory ++ Path) of
         {ok, Filenames}->
            string:join(["<li><a href="++Path++"/"++XX++">"++XX++"</a></li>"|| XX<-Filenames], "\r\n");
         {error, Reason}->
            io:format("error ~s~n", [Reason]),
            {"404", "404"}
    end,
    {"200", "<html><head></head><body>"++"<ul>"++List++"</ul>"++"</body></html>"}.

read_path(Path) ->
    {ok, CurrentDirectory} = file:get_cwd(),
    AbsolutePath = CurrentDirectory ++ Path,
    case filelib:is_dir(AbsolutePath) of
        true ->
            read_dir(CurrentDirectory, Path);
        false ->
            read_file(CurrentDirectory, Path)
    end.

get_html(Request)->
    {_, Path} = dict:find("path", Request),
    {Code, Text} = read_path(Path),
    io:format("read [~s]~n", [Text]),
    Len = string:len(Text),
    io:format("Path is ~s~n", [Path]),
    "HTTP/1.1 "++ Code ++" OK\r\nContent-Length: "++integer_to_list(Len)++ "\r\n\r\n" ++ Text.
