module Pythagoras where

sqr :: Double -> Double
sqr x = x * x

pythagoras :: Double -> Double -> Double
pythagoras a b = sqrt(sqr a + sqr b)

prompt :: String -> IO Double
prompt message = do
    putStr message
    readLn

main :: IO ()
main = do
    a <- prompt "Enter base: "
    b <- prompt "Enter side: "
    putStr "Hypotenuse "
    print(pythagoras a b)
