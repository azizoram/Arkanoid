//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_BALL_H
#define SEMWORK_BALL_H

#include "Point.h"
#include "Interactive.h"
#include "Section.h"
#include <math.h>

#define PI 3.14159265

class Ball: public Point{
    double a,s;//x, y , angle, speed
    bool dead=false;
    void die(){
        a=s=0;
        dead= true;
    }
public:
    Ball(double x,double y,double a,double s): Point(x,y), a(a), s(s){}
    void Update(GameObject *map) override;
    void Collide(GameObject *gay) override ;
    Point nextPos() override;;
    void show(ViewField &f) override{
        if(!dead)f.Set(int(x),int(y),'*');
    }

    virtual Point curPos(){return {x,y};}


};


#endif //SEMWORK_BALL_H
