-module(mylib).
-export([request/1]).

get_header_kv([], Headers) ->
    Headers;
get_header_kv(Str, Headers) ->
    [Head| Tail] = Str,
    %%"Host: localhost:8080" this may have several :
    %% So there may be a list, Key is only the first element
    %% then join the last elements as Value
    [Key| Value_list] = string:tokens(Head, ":"),
    Value = string:join(Value_list, ":"),
    output(Tail, dict:append(Key, string:strip(Value), Headers)).

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
