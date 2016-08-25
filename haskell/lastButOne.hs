lastButOne [] = error "empty list"
lastButOne [a] = error "only one element"
lastButOne [a, b] = a
lastButOne (x:xs) = lastButOne(xs)

main = print $ lastButOne [1,2,3]
