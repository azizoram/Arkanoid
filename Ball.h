//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_BALL_H
#define SEMWORK_BALL_H

#include "Point.h"
#include <math.h>

#define PI 3.14159265

class Ball: public Point{
    double a,s;//x, y , angle, speed
public:
    bool dead=false;
    Ball(double x,double y,double a,double s): Point(x,y), a(a), s(s){}
    //void Update() override;
    void Collide(GameObject *gameObject) override ;

    Point nextPos() override;
    void setAng(double ang) override{
        a=ang;
    };
    void show(ViewField &f) override{
        if(!dead)f.Set(int(x),int(y),'*');
    }


};


#endif //SEMWORK_BALL_H
