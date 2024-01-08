#include "../header/Point.h"


Point::Point(/* args */)
{
}

Point::~Point()
{
}


double Point::getPositionX(){
    return _x;
}

double Point::getPositionY(){
    return _y;
}

void Point::setPositionX(double x){
    _x = x;
}
void Point::setPositionY(double y){
    _y = y;
}