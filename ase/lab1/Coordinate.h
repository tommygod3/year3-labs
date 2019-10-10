#include <iostream>

struct Coordinate
{
    // Data 
    int x;
    int y;

    // Constructor
    Coordinate(int x_coordinate, int y_coordinate);

    // Member function
    void display();

    // Static member function
    static bool isEqual(Coordinate, Coordinate);
};
