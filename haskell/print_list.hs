xxx [] = return()
xxx x = do
    print (head x)
    xxx (tail x)

main = do
    xxx [1..10]
