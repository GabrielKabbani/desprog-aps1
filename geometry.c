#include <math.h>

#include "geometry.h"

int verify(point p, point a, point b) {
    


    int max_x;
    int max_y;
    int min_x;
    int min_y;
    if (a.x>b.x){
        max_x=a.x;
        min_x=b.x;
    }else{
        max_x=b.x;
        min_x=a.x;
    }
    if (a.y>b.y){
        max_y=a.y;
        min_y=b.y;
    }else{
        max_y=b.y;
        min_y=a.y;
    }

    int delta_y = a.y - b.y;
    int delta_x = a.x - b.x;
    double m = (double) delta_y/ (double) delta_x;
    double yoyo = p.y - a.y;
    double xoxo = p.x - a.x;
    double dif = abs(yoyo - m*xoxo);
    

    if ((dif>0.000001) && (p.x<=max_x) && (p.x >= min_x) && (p.y<=max_y) && (p.y>=min_y)){ //Falta adaptar double
        return 2;
    }
    
    if ((p.y<=max_y) && (p.y>= min_y) && (p.x<max_x)){//Falta adaptar perturbacao
        return 1;
    } 

    return 0;
}

int inside(point p, point poly[], int n) {
    return 0;
}
