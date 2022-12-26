//
// Created by ramir on 24.12.2022.
//

#ifndef SEMWORK_POINT_H
#define SEMWORK_POINT_H


#include <cmath>
#include "Rational.h"
struct Point {
    Point(Rational x,Rational y):x(x),y(y){}
    Point(int x,int y):x(x),y(y){}
    Rational x;
    Rational y;
    bool isNop(){return x.isnan()||y.isnan();}
    Rational distance(Point &p){
        if (isNop()||p.isNop())
            return std::nan("");
        Rational dx=p.x-x;
        Rational dy=p.y-y;
        return (dx*dx+dy*dy).sqrt();
    }
};

struct NoPoint: public Point{
    NoPoint(): Point(std::nan(""),std::nan("")){}
};

#endif //SEMWORK_POINT_H
