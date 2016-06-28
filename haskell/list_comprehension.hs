print_list [] = return()
print_list x = do
    print (head x)
    print_list (tail x)

main = do
    let a = [i | i <- [1..100], (mod i 5) == 0]
    print_list a
