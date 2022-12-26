//
// Created by ramir on 23.12.2022.
//

#include "Ball.h"

Point Ball::nextPos(){
    double angle= a*PI/180;
    return {point.x+Rational(sin(angle) * s),point.y+Rational(cos(angle) * s)};
}
Point Ball::curPos(){
    return point;
}
void Ball::Collide(GayObject *gay) {
    if(gay !=prev) {
        prev=gay;/*
        double t;
        double dx = std::modf(point.x, &t);
        double dy = std::modf(point.y, &t);
        if (dx >= dy) {
            a = 180 - a;
        } else {
            a = 360 - a;
        }*/
    }
}

void Ball::setPos(Point p) {
    point=p;
}
