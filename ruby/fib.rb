#!/usr/bin/env ruby

def Fib(a)
    if a == 0 or a == 1
        1
    else
        Fib(a-1) + Fib(a-2)
    end
end
a = []

10.times do |i|
    a << Fib(i)
end
puts(a)
