data Person = Person { firstName :: String
                     , lastName :: String
                     , age :: Int
                     }

instance Eq Person where
    (Person a1 b1 c1) == (Person a2 b2 c2) = (a1, b1) == (a2, b2)

instance Show Person where
    show (Person x y z)= x ++ "," ++ y ++"["++show z ++ "]"

instance Ord Person where
    (Person a1 b1 c1) `compare` (Person a2 b2 c2) = c1 `compare` c2

main = do
    let a = Person "abc" "def" 26
    let b = Person "abc" "def" 25
    print(a == a)
    print(a)
    print(b)
    print(a > b)
