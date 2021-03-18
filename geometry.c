#include <math.h>
#include <stdlib.h>

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
    
    if((p.y==a.y) | (p.y==b.y)){ // rotaçao a esquerda (perturbacao)
        p.y*=0.90;
    }


    int position = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x);

    if (((dif<0.000001) && (p.x<=max_x) && (p.x >= min_x) && (p.y<=max_y) && (p.y>=min_y)) && position == 0){ //Falta adaptar double
        return 2;
    }
    
    if (((p.y<=max_y) && (p.y>= min_y) && (p.x<max_x)) && position <0){//Falta adaptar perturbacao ADD O maior que MIN 
        return 1;
    } 

    return 0;
}

int inside(point p, point poly[], int n) {
    return 0;
}
