#!/usr/bin/env escript
%% echo server

main(_Args) ->
    hs:start(8080, "/home/liu/Code/Learn/react").
