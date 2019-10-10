#include <iostream>
#include <vector>
#include <iterator> 

#include "Coordinate.h"

int recursiveFactorial(int i)
{
    if (i < 2)
    {
        return 1;
    }
    else
    {
        return i * recursiveFactorial(i-1);
    }
}

void swapCoordinates(Coordinate* & first, Coordinate* & second)
{
    Coordinate* swap = first;
    first = second;
    second = swap;
}

std::ostream & operator<<(std::ostream & os, const std::vector<int> & vec)
{
    os << '[';
    
    int size = vec.size();
    for (int i = 0; i != size; i++)
    {
        if (i == size -1)
        {
            os << vec[i];
        }
        else
        {
            os << vec[i] << ',';
        }
        
    }

    os << ']';

    return os;
}

int main ()
{
    // Recursive function
    std::cout << recursiveFactorial(5) << std::endl;

    // Struct
    Coordinate myLocation = Coordinate(10, 89);
    Coordinate yourLocation(200, -10);

    yourLocation.y = 49;

    myLocation.display();
    yourLocation.display();

    // Pointers
    Coordinate* pointerLocation = new Coordinate(200, 49);
    pointerLocation->display();
    
    if (Coordinate::isEqual(*pointerLocation, yourLocation))
    {
        std::cout << "Same coordinate"  << std::endl;
    }
    else
    {
        std::cout << "Different coordinate"  << std::endl;
    }

    Coordinate* specialLocation = new Coordinate(50, 150);

    swapCoordinates(pointerLocation, specialLocation);
    pointerLocation->display();
    specialLocation->display();

    Coordinate summedLocation = *pointerLocation + *specialLocation;
    summedLocation.display();
    
    
    Coordinate fromPointer = *specialLocation;
    Coordinate* fromVariable = &myLocation;

    fromPointer.display();
    fromVariable->display();

    delete pointerLocation;
    delete specialLocation;
    // Do not need to delete fromVariable as it the data is not allocated with new




    // Overloading Stream Insertion
    std::vector<int> vec = {1, 2, 3};
    std::cout << vec << std::endl;

    return 0;
}
