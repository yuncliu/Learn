-module(add).
-export([main/0]).
main() ->
    Mya = get_input(),
    Myb = get_input(),
    add(Mya, Myb).

get_input()->
    Myv = io:get_line("input:"),
    case string:to_integer(Myv) of
        {error, Reason} ->
            {error, Reason};
        {Int, _} ->
            {ok, Int}
    end.

add({ok, Inta}, {ok, Intb}) ->
    io:format("~p~n", [Inta + Intb]);
add(_, _) ->
    io:format("error~n").
