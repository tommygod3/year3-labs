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

    // Operator overloading
    Coordinate operator+(Coordinate);
    // why only 1 arg?
    // is this because it is a member function?
    // Should this be a member function?


};
