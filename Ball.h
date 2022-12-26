//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_BALL_H
#define SEMWORK_BALL_H

#include "GayObject.h"
#include <math.h>

#define PI 3.14159265

class Ball: public GayObject{
    double a,s;//x, y , angle, speed
public:
    Ball(double x,double y,double a,double s): GayObject(x,y), a(a), s(s){}
    //void Update() override;
    void Collide(GayObject &gay) override ;
    char getChar() override{
        return '*';
    }

    Point nextPos() override;
};


#endif //SEMWORK_BALL_H
