//
// Created by ramir on 23.12.2022.
//

#include "Ball.h"

Point Ball::nextPos(){
    double angle= a*PI/180;
    return {point.x+(sin(angle) * s),point.y+(cos(angle) * s)};
}

double norm(double a){
    if(a<0)
        return norm(a+360);
    return std::fmod(a,360);
}

void Ball::Collide(GayObject &gay) {

}
