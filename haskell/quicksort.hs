quicksort [] = []
quicksort (x:xs) =
    let smallerSorted = quicksort [a | a <- xs, a < x]
        biggerSorted = quicksort [a | a <- xs, a > x]
    in smallerSorted ++ [x] ++ biggerSorted

main = print(quicksort [1,3,2,5,4,10,9,7,6])
