#!/usr/bin/env escript
%% record learn

-record(person, {name, phone, address = "Chengdu"}).


main(_Args) ->
    A = #person{phone=[0,8,2,3,4,3,1,2], name="Robert", address="Earth"},
    B= A#person{address="Mar"},
    C = #person{phone=[0,8,2,3,4,3,1,2], name="Robert"},
    print_person(A),
    print_person(B),
    print_person(hellow),
    print_person(C).

print_person(P) when is_record(P, person)->
    io:format("Name:~s~n Phone:~p~nAddress:~s~n", [P#person.name, P#person.phone, P#person.address]);
print_person(_)->
    io:format("Not a person~n").
