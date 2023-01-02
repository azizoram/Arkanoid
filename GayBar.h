//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_GAYBAR_H
#define SEMWORK_GAYBAR_H

#include "GayObject.h"
#include "Point.h"

class GayBar: public Fourangle{
public:
    Point p;
    double w;
    GayBar(double x,double y,double w): p(x,y),w(w), Fourangle(x,y,x+w+1,y+1){}
    void show(ViewField &f) override{
        for (int x = ceil(p.x); x < floor(p.x+w); ++x) {
                f.Set(x,int(p.y),'=');
        }
    }
    void move(double d){
        s1.p.x+=d;
        s1.q.x+=d;
        s2.p.x+=d;
        s2.q.x+=d;
        s3.p.x+=d;
        s3.q.x+=d;
        s4.p.x+=d;
        s4.q.x+=d;
        p.x+=d;
    }
};
#endif //SEMWORK_GAYBAR_H
