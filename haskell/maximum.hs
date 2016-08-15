mymaximum [] = error "empy list"
mymaximum [x] = x
mymaximum (x:xs) =
    if x > y then x else y
    where y = mymaximum(xs)

main = print(mymaximum [1,4,2,5,2])
