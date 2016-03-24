import Text.Read
import Data.Maybe

main = do
    a <- getLine
    b <- getLine
    let aa = readMaybe a :: Maybe Int
    let bb = readMaybe b :: Maybe Int
    case aa of
        Nothing ->
            print "error"
        _ ->
            case bb of
                Nothing ->
                    print "error"
                _ ->
                    do
                        let aaa = fromJust aa
                        let bbb = fromJust bb
                        print (aaa + bbb)
