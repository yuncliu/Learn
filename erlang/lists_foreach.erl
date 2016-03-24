#!/usr/bin/env escript
%% echo server

main(_Args) ->
    Mylist = [1,2,3],
    lists:foreach (
      fun(MyElement) ->
          io:format("~p~n", [MyElement])
      end,
      Mylist
    ).
