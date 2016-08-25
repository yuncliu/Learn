import Text.Read
import Data.Maybe

add a b = pure (+) <*> a <*> b

main = do
    a <- getLine
    b <- getLine
    let aa = readMaybe a :: Maybe Int
    let bb = readMaybe b :: Maybe Int
    let s = add aa bb
    case s of
        Nothing -> putStrLn "error"
        _ -> print $ fromJust s
