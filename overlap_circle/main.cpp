#include  <iostream>
#include <vector>
#include "./header/util.h"
#include "./header/Circle.h"
#include "./header/Point.h"


int main(){
    //Nbr circle
    const int circle_min_nbr = 2;
    const int circle_max_nbr = 7;

    //Interval repere
    const double center_min_pos = 0.0;
    const double center_max_pox = 10.0;

    //interval radius
    const double radius_min = 1.0;
    const double radius_max = 5.0;


    //Generate a number of circles between 2 and 6
    int nbr_cercle = randInt(2 , 7);
    std::vector<Circle> tab_init {};
    std::vector<Circle> tab_circles {};
    
    for(int i {0} ; i < nbr_cercle ; i++){
        Circle circle = Circle();
        Point center = Point();
        center.setPositionX(randDouble(center_min_pos , center_max_pox));
        center.setPositionY(randDouble(center_min_pos , center_max_pox));
        circle.setCenter(center);
        circle.setRadius(randDouble(radius_min , radius_max));
        circle.setColor(randColor());
        circle.setId(i);
        tab_circles.push_back(circle);
    }
    
    tab_init  = tab_circles;

    display_tabCircle(tab_circles);

    //chevauchement
    std::cout << "Voici les cercles qui chevauchent  : \n";
    for(size_t i = 0 ; i < tab_circles.size() ; i++){   
        for(size_t j = i+1 ; j < tab_circles.size() ; j++){   
            if(isOverlap(tab_circles[i] , tab_circles[j]) > 0.0){
                std::cout << "Cercle C" << i << " et Cercle C" << j << " se chevauchent" << " avec une distance d = " << isOverlap(tab_circles[i] , tab_circles[j]) << std::endl ;
            }
        }
    }
    printf("\n\n");

    //decalage
    std::cout << "Voici les déplacements à effectués :\n";
    for (size_t i = 0; i < tab_circles.size(); i++) {
        for (size_t j = i + 1; j < tab_circles.size(); j++) {
            if (isOverlap(tab_circles[i], tab_circles[j]) > 0.0) {
                Translation t = translate(tab_circles[i], tab_circles[j]);
                std::cout << "Le cercle C" << j << " est deplacé avec le vecteur de translation u(" << t.tx << ", " << t.ty << " )" << std::endl;
            }
        }
    }

    printf("\n\n");
    printf("Cercles initiales : \n\n");
    display_tabCircle(tab_init);
    printf("Résultats finales : \n\n");
    display_tabCircle(tab_circles);

    return 0;
}