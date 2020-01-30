module Lab13 where

sumList :: [Int] -> Int
sumList [] = 0
sumList (h : t) = h + sumList t
