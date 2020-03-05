data Day = Mon | Tue | Wed | Thu | Fri | Sat | Sun
           deriving (Show, Read)


showDay :: Day -> String
showDay Mon = "Monday"
showDay Tue = "Tuesday"
showDay Wed = "Wednesday"
showDay Thu = "Thursday"
showDay Fri = "Friday"
showDay Sat = "Saturday"
showDay Sun = "Sunday"

-- instance Show Day where
--     show = showDay

data StudentID = ID Char Int

instance Show StudentID where
    show (ID ty num) = ty : show num

data Coordinate2D = Co Int Int

instance Show Coordinate2D where
    show (Co x y) = "(" ++ show x ++ "," ++ show y ++ ")"

-- print :: Show a => a -> IO()
-- print x = putStrLn (show x)

-- class Read a where
--     read :: String -> a

--  Operators:
-- class Eq a where
--     (==) :: a -> a -> Bool

instance Eq Coordinate2D where
    (Co x1 y1) == (Co x2 y2) = (x1 == x2) && (y1 == y2)

-- class Ord a where
--     (<) :: a -> a -> Bool

-- (>) :: Ord a => a -> a -> Bool
-- x > y = y < x


-- class Num a where
--     (+) :: a -> a -> a


