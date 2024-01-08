#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <unistd.h>
#include <math.h>
#include "../header/Circle.h"
#include "../header/util.h"

int randInt(int min , int max){
    sleep(1);
    std::srand(std::time(0));
    return min + std::rand() % (max - min + 1); 
}

double randDouble(double min , double max){
    sleep(1);
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    double nbrBetween = static_cast<double>(std::rand()) / RAND_MAX;

    return nbrBetween * (max - min) + min;

}

std::string randColor(){
    std::vector<std::string> colors {"rouge" , "jaune" , "vert" , "bleue" , "violet" , "gris" , "noire"};
    return colors[randInt(0 , 6)];
}

void display_tabCircle(std::vector<Circle> tab){
    for(auto circle : tab){
        std::cout << "Circle " << circle.getId() << " color => " << circle.getColor() << " radius => " << circle.getRadius() << "center => ";
        std::cout << "x : " << circle.getCenter().getPositionX() << " y : " << circle.getCenter().getPositionY() << std::endl;
    }
}

double calc_distance_center(double x1 , double y1 , double x2 , double y2){
    double distance = 0.0;
    distance = sqrt(pow((x2 - x1) , 2) +  pow((y2 - y1) , 2));
    return distance;
}

Translation translate(Circle &A , Circle &B){
    
    double reste = isOverlap(A , B);
    double x1 = A.getCenter().getPositionX();
    double y1 = A.getCenter().getPositionY();
    double x2 = B.getCenter().getPositionX();
    double y2 = B.getCenter().getPositionY();
        
    Translation t{0 , 0};
    
    if(reste > 0){
        double angle = std::atan2(y2 - y1 , x2 - x1);
        t.tx = reste * std::cos(angle);
        t.ty = reste * std::sin(angle);
    }

    Point c = Point();
    c.setPositionX(x2 + t.tx);
    c.setPositionY(y2 + t.ty);

    B.setCenter(c);
    
    return t;
}

double distanceCenter(Circle A , Circle B){
    double x1 = A.getCenter().getPositionX();
    double y1 = A.getCenter().getPositionY();
    double x2 = B.getCenter().getPositionX();
    double y2 = B.getCenter().getPositionY();
    
    return calc_distance_center(x1 , x2 , y1 , y2);
}


double  isOverlap(Circle A , Circle B){
    double dist_centre = distanceCenter(A , B);
    double a = (A.getRadius() + B.getRadius()) - dist_centre;
    return a;
}
