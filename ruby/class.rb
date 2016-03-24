#!/usr/bin/env ruby

class Test
    def initialize
        @x = 0
    end

    def x()
        @x
    end

    def x=(a)
        if a > 0
            @x = a
        else
            @x = 0
        end
    end
end

a = Test.new
a.x = 100
puts(a.x)
a.x = -100
puts(a.x)
puts(a.x.class)
