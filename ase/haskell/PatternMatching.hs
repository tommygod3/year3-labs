module PatternMatching where

fac :: Int -> Int
fac 0 = 1
fac i = i * fac(i - 1)

-- Pattern Matching:
lengthList [] = 0
lengthList (h : t) = 1 + lengthList t

-- Non Pattern Matching version
lengthList l = if null l
                   then 0
                   else 1 + lengthList (tail l)
