#!/usr/bin/env ruby

a||=[]
10.times do |i|
    a<<i
end

for i in a
    puts i
end

a.each do |i|
    puts i
end

i=0
while i < a.length do
    puts a[i]
    i += 1
end
