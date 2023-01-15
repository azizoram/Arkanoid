//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_BALL_H
#define SEMWORK_BALL_H

#include "Point.h"
#include "Section.h"
#include <math.h>

#define PI 3.14159265

/**
 * \class represents game ball
 */
class Ball: public Point{
    /** @atribut a is angle
     *  @atribut s is speed
     *  @atribut dead is true if the ball is dead
     */
    double a,s;
    bool dead=false;

public:
    /**
     *
     * @param x - x coordinate of ball
     * @param y - y coordinate of ball
     * @param a - angle of ball direction
     * @param s - speed of ball
     */
    Ball(double x,double y,double a,double s): Point(x,y), a(a), s(s){}
    void Update(GameObject *map) override;
    void Collide(GameObject *gameObject) override ;
    Point nextPos() override;
    void show(ViewField &f) override{
        if(!dead)f.Set(int(x),int(y),'*');
    }

    Point curPos() override{return {x,y};}
};


#endif //SEMWORK_BALL_H
