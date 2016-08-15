class YesNo a where
    yesno :: a -> Bool

instance YesNo Int where
    yesno 0 = False
    yesno _ = True

instance YesNo [a] where
    yesno [] = False
    yesno _ = True

main = do
    print $ yesno (10 :: Int)
    print $ yesno [1,2,3]
    print $ yesno []
