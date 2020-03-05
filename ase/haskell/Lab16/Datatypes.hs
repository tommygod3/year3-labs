module Datatypes where

-- Enum:
data Day = Mon | Tue | Wed | Thu | Fri | Sat | Sun

isWeekend :: Day -> Bool
isWeekend Sat = True
isWeekend Sun = True
isWeekend _ = False

data Move = Rock | Paper | Scissors

data Result = Lose | Draw | Win

-- play :: Move -> Move -> Result



-- Struct:
type StreetName = String
type CityName = String
type PostCode = String

--   (Type)    (Name of Constructor)  convention for them to be the same
data Address = AddressC Int StreetName CityName PostCode

getPostcode :: Address -> PostCode
getPostcode (AddressC num street city postcode) = postcode


-- Both:

type Radius = Double
type Width = Double
type Height = Double

data Shape = Circle Radius
            | Rectangle Width Height
            | Triangle Double Double Double

area :: Shape -> Double
area (Circle radius)            = pi * radius^2
area (Rectangle width height)   = width * height
area (Triangle a b c)           = let s = (a + b + c) / 2 in sqrt(s*(s-a)*(s-b)*(s-c))

perimeter :: Shape -> Double
perimeter (Circle radius)           = radius * 2 * pi
perimeter (Rectangle width height)  = (width + height) * 2
perimeter (Triangle a b c)          = a + b + c

sides :: Shape -> Int
sides (Circle radius)           = 1
sides (Rectangle width height)  = 4
sides (Triangle a b c)          = 3


-- Recursive

-- Standard Library list
-- EndOfList -> []
-- Node -> (:)
data List t = EndOfList
          | Node t (List t)

lengthOfList :: List t -> Int
lengthOfList EndOfList = 0
lengthOfList (Node _ l) = 1 + lengthOfList l


-- BST:
type Key = Int
type Item = String

-- Implementation of Maybe:
-- data Maybe t = Nothing | Just t

data BST = Leaf
         | InternalNode Key Item BST BST

-- Maybe Item returns Nothing or Just Item
-- Means you force function user to test for Nothing when relevant
lookupBST :: Key -> BST -> Maybe Item
lookupBST soughtKey Leaf = Nothing
lookupBST soughtKey (InternalNode k i leftChild rightChild) =
    if soughtKey < k then
        lookupBST soughtKey leftChild
    else if soughtKey > k then
        lookupBST soughtKey rightChild
    else
        Just i



