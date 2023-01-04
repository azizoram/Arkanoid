//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_GAMEBAR_H
#define SEMWORK_GAMEBAR_H

#include "GameObject.h"
#include "Point.h"

class GameBar: public Figure{
public:
    Point p;
    double w;
    GameBar(double x, double y, double w): p(x, y), w(w),
                                           Figure({new Section({x, y},{x+w+1, y+1}),
                                                   new Section( {x-w-1, y+1},{x, y})}){}
    void show(ViewField &f) override{
        for (int x = ceil(p.x-w); x < floor(p.x+w); ++x) {
                f.Set(x,int(p.y),'=');
        }
    }
    void move(double d){
        for(auto s:sections) {
            s->p.x += d;
            s->q.x += d;
        }
        p.x+=d;
    }
};
#endif //SEMWORK_GAMEBAR_H
