//
// Created by ramir on 24.12.2022.
//

#ifndef SEMWORK_POINT_H
#define SEMWORK_POINT_H


#include <cmath>
#include "GameObject.h"

/** \class Point represents euclidean point **/
class Point: public GameObject {
public:
    /**
     *
     * @param x - x coordinate
     * @param y - y coordinate
     */
    Point(double x,double y):x(x),y(y){}
    Point(int x,int y):x(x),y(y){}
    double x;
    double y;
    /**
     *
     * @return true if point is not exist or doesn't make sense
     */
    bool isNop(){
        return std::isnan(x)||std::isnan(y);
    }
    /**
     *
     * @param p - point
     * @return euclidean distance between two point
     */
    double distance(Point &p){
        if (isNop()||p.isNop())
            return std::nan("");
        double dx=p.x-x;
        double dy=p.y-y;
        return sqrt(dx*dx+dy*dy);
    }

    virtual void Update(GameObject *map) {};
    /**
     *
     * @return current position
     * By default point doesn't move
     */
    virtual Point nextPos(){return curPos();}
    virtual Point curPos(){return *this;}

    virtual void Collide(GameObject* gay){}
    virtual void show(ViewField &field){}
};

struct NoPoint: public Point{
    NoPoint(): Point(std::nan(""),std::nan("")){}
};

#endif //SEMWORK_POINT_H
