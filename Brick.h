//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_BRICK_H
#define SEMWORK_BRICK_H
#include "Fourangle.h"

class Brick: public Fourangle{
    unsigned int x,y,h;//health
public:
    Brick(double x,double y,int h):x(x),y(y), Fourangle(x, y,x+1,y+1), h(h){}
    void Collide(GayObject *obj) override {h--;};

    char getChar() override{
        return '0'+h;
    }

    Point intersection(Section &s) {
        if(h<=0)
            return NoPoint();
        else
            return Fourangle::intersection(s);
    }
    void show(ViewField &f) override{
        if(h>0)
            f.Set(int(x),int(y),'0'+h);
    }
};
#endif //SEMWORK_BRICK_H
