#ifndef POINT_H
#define POINT_H

class Point
{
    private:
        double _x;
        double _y;
    
    public:
        Point();
        ~Point();  

    double getPositionX();
    double getPositionY();

    void setPositionX(double x);
    void setPositionY(double y);

};
#endif