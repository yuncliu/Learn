def ExecuteProc(p)
    @a = 10
    p.call
end
a = 100
p1 = Proc.new do
    puts a
end
ExecuteProc(p1)

def ExecuteBlock
    @aa = 10
    puts "start"
    yield
    puts "end"
end

ExecuteBlock do
    puts @aa
end

def Execute(p)
    @a = 10
    if p.class == String
        eval(p)
    end
end
code = ("puts @a")
Execute(code)
