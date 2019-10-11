#include "Coordinate.h"

Coordinate::Coordinate(int x_coordinate, int y_coordinate)
{
    x = x_coordinate;
    y = y_coordinate;
}

void Coordinate::display()
{
    std::cout << '(' << x << ',' << y << ')' << std::endl;
}

bool Coordinate::isEqual(Coordinate first, Coordinate second)
{
    return (first.x == second.x) && (first.y == second.y);
}

Coordinate Coordinate::operator+(Coordinate otherCoordinate)
{
    int sumX = this->x + otherCoordinate.x;
    int sumY = this->y + otherCoordinate.y;
    return Coordinate(sumX, sumY);
}
