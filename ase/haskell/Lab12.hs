module Lab12 where
import Data.Char(digitToInt)

luhnDouble :: Int -> Int
luhnDouble n = if n * 2 > 9
                   then n * 2 - 9
                   else n * 2

luhn :: [Int] -> Bool
luhn l = mod (sum (luhnDoubleList l)) 10 == 0

luhnDoubleList :: [Int] -> [Int]
luhnDoubleList xs = fst $ foldr (\x (acc, bool) ->
                                  ((if bool then luhnDouble x else x) : acc,
                                   not bool)) ([], False) xs

luhnString :: String -> Bool
luhnString s = luhn (map digitToInt s)

main :: IO()
main = do
    putStr "Card number: "
    str <- getLine
    print(luhnString str)
