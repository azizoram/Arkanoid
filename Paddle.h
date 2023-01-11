//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_PADDLE_H
#define SEMWORK_PADDLE_H

#include "GameObject.h"
#include "Point.h"

class Paddle: public Section{
public:
    double w;
    Paddle(double x, double y, double w):  w(w),
                                          Section({x-w,y},{x+w,y}){}
    void show(ViewField &f) override{
        for (int x = ceil(p.x); x < floor(q.x); ++x) {
                f.Set(x,int(p.y),'=');
        }
    }
    void move(double d){
        p.x += d;
        q.x += d;
    }

    double ReflectedAngle(Point point,double a) override{
        double ang= 90;
        double dx=(point.x-(p.x+w));
        double da=dx*40/w;
        ang-=da;
        return norm(2*ang-a);
    }
};
#endif //SEMWORK_PADDLE_H
