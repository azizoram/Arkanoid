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
    Point point;

public:
    Ball(double x,double y,double a,double s): point(x,y), a(a), s(s){}
    //void Update() override;
    void Collide(GayObject *gay) override ;
    char getChar() override{
        return '*';
    }

    Point nextPos() override;
    Point curPos() override;
    void setPos(Point p) override;
    void setAng(double ang) override{a=ang;};
    void show(ViewField &f) override{
        f.Set(int(point.x),int(point.y),'*');
    }
};


#endif //SEMWORK_BALL_H
