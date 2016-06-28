print_array [] = putStrLn ""
print_array a = do
    putStr (show (head a))
    putStr "  "
    print_array (tail a)

print_matrix [] = putStr ""
print_matrix m = do
    print_array (head m)
    print_matrix (tail m)

main = do
    let x = [[1, 2, 3],[2, 3, 4],[3, 4, 5]]
    print_matrix x
    print_array (product 1 x)
