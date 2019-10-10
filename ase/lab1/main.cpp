#include <iostream>

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
    
    delete pointerLocation;


    return 0;
}
