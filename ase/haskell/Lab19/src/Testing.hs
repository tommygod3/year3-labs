module Testing where

import Test.QuickCheck

prop_reverseLength :: [Int] -> Bool
prop_reverseLength xs = 
    length xs == length (reverse xs)


qsort :: [Int] -> [Int]
qsort [] = []
qsort (x:xs) =
    let smaller = filter (< x) xs
        bigger  = filter (>= x) xs
    in qsort smaller ++ [x] ++ qsort bigger

prop_qsortReverseLength :: [Int] -> Bool
prop_qsortReverseLength xs = 
    length xs == length (reverse (qsort xs))

prop_qsortHeadSmallest :: Int -> [Int] -> Bool
prop_qsortHeadSmallest x xs =
    head (qsort (x:xs)) == minimum (x:xs)

-- prop_qsortAscending :: Int -> [Int] -> Bool




