#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include <iostream>

class Circle
{
    private:
        Point _center;
        double  _radius;
        std::string _color;
        int _id;

    public:
        Circle();
        ~Circle();

        Point getCenter();
        double getRadius();
        std::string getColor();
        int getId();

        void setCenter(Point center);
        void setRadius(double radius);
        void setColor(std::string color);
        void setId(int id);
};

#endif