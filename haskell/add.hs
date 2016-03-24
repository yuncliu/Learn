import Text.Read
import Data.Maybe

add Nothing Nothing = print("both arg error")
add Nothing b = print("first arg error")
add a Nothing = print("second arg error")
add a b= do
    let aa = fromJust a
    let bb = fromJust b
    print(aa + bb)

main = do
    a <- getLine
    b <- getLine
    let aa = readMaybe a :: Maybe Int
    let bb = readMaybe b :: Maybe Int
    add aa bb
