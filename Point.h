//
// Created by ramir on 24.12.2022.
//

#ifndef SEMWORK_POINT_H
#define SEMWORK_POINT_H


#include <cmath>

struct Point {
    Point(double x,double y):x(x),y(y){}
    Point(int x,int y):x(x),y(y){}
    double x;
    double y;
    bool isNop(){return std::isnan(x)||std::isnan(y);}
    double distance(Point &p){
        if (isNop()||p.isNop())
            return std::nan("");
        double dx=p.x-x;
        double dy=p.y-y;
        return std::sqrt(dx*dx+dy*dy);
    }
};

struct NoPoint: public Point{
    NoPoint(): Point(std::nan(""),std::nan("")){}
};

#endif //SEMWORK_POINT_H
