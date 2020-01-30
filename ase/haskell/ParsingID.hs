module ParsingID where

decomposeID :: String -> (Char, Int)
decomposeID str = (head str, read(tail str))

main :: IO()
main = do
    putStr "Enter ID: "
    str <- getLine
    let (letter, number) = decomposeID str
    putStr "Type: "
    putChar (letter)
    putStr "\nNumber: "
    print(number)
