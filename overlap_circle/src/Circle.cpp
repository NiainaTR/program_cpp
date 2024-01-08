#include "../header/Circle.h"
#include <iostream>

Circle::Circle()
{
}

Circle::~Circle()
{
}

Point Circle::getCenter(){
    return _center;
}

double Circle::getRadius(){
    return _radius;
}

std::string Circle::getColor(){
    return _color;
}
int Circle::getId(){
    return _id;
}


void Circle::setCenter(Point center){
    _center = center;
}

void Circle::setRadius(double radius){
    _radius = radius;
}
void Circle::setColor(std::string color){
    _color = color;   
}

void Circle::setId(int id){
    _id = id;
}