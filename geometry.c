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
    if ((p.x==a.x && p.y==a.y)|(p.x==b.x && p.y==b.y)){
        return 2;
    }
    if (p.x<=max_x && p.x>=min_x && min_y==max_y && p.y == min_y){
        return 2;
    }
    if (max_y == min_y){
        return 0;
    }
    int delta_y = a.y - b.y;
    int delta_x = a.x - b.x;
    double m;
    if (delta_x!=0){
        m = (double) delta_y/delta_x;
    }else{
        if (p.x<max_x && p.y<=max_y && p.y>min_y){
            return 1;
        }
        if (p.x==max_x && p.y<=max_y && p.y>=min_y){
            return 2;
        }
        return 0;
    }
    
    double yoyo = p.y - a.y;
    double xoxo = p.x - a.x;
    double dif = fabs(yoyo - (m*xoxo));

    point ray;
    ray.x=p.x + 2;
    ray.y=p.y;

    int ray_deltay= p.y-ray.y;
    int ray_deltax= p.x-ray.x;
    double ray_m = (double) ray_deltay/ray_deltax;
    double x_encontro;
    if (m!=0){
        x_encontro = ((p.y-a.y)/m)+a.x;   // y-y0 = m*x-m*x0 --> x= ((y-y0)+m*x0))/m
    }else{
        return 0;
    }
    
    if (fabs(ray_m-m)<0.000001){
        return 0;
    }
    
    if (p.y==min_y && p.x!=min_x && p.x!=max_x){
        return 0;
    }

    

    // int position = (b.x - a.x) * (p.y - a.y) - (b.y - a.y) * (p.x - a.x); //determinante


    if (((dif<0.000001) && (p.x<=max_x) && (p.x >= min_x) && (p.y<=max_y) && (p.y>=min_y))){ //Falta adaptar double
        return 2;
    }
    
    if ((x_encontro>=p.x && p.y<=max_y && p.y>min_y) | (p.y==max_y && x_encontro>=p.x)){//Falta adaptar perturbacao ADD O maior que MIN 
        return 1;
    } 

    return 0;
}

int inside(point p, point poly[], int n) {
    return 0;
}