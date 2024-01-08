#ifndef UTIL_H
#define UTIL_H

#include "../header/Circle.h"
struct Translation {
    double tx;
    double ty;
};



double randDouble(double min , double max);
int randInt(int min , int max);
std::string randColor();
void display_tabCircle(std::vector<Circle> tab);
double distanceCenter(Circle A , Circle B);
Translation translate(Circle &A , Circle &B);
double calc_distance_center(double x1 , double y1 , double x2 , double y2);
double  isOverlap(Circle A , Circle B);
#endif