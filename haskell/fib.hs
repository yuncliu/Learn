print_list [] = return()
print_list x = do
    print (head x)
    print_list (tail x)

fibs a =
    fib a []

fib len [] =
    fib len [1]
fib len [1] =
    fib len [1, 1]
fib len l = do
    let a = last l
    let b = last (init l)
    let newl = l ++ [a + b]
    if length newl > len then
        newl
    else
        fib len newl

main = do
    let a = fibs 10
    print_list a
