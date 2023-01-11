//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_BRICK_H
#define SEMWORK_BRICK_H
#include "Rectangle.h"

class Brick: public Rectangle{
    //health
protected:
    unsigned int h;
    unsigned int x;
    unsigned int y;
public:
    Brick(double x,double y,int h): x(x), y(y), Rectangle(x, y, x + 1, y + 1), h(h){}
    void Collide(GameObject *obj) override {h--;if(h < 0)h=0;};
    bool intersects(const Section &s) override{
        if(h>0)
            return Rectangle::intersects(s);
        return false;
    }
    Point intersection(Section &s) override{
        if(h>0)
            return Rectangle::intersection(s);
        return NoPoint();
    }
    void show(ViewField &f) override{
        if(h>0)
            f.Set(int(x),int(y),'0'+h);

    }
};
#endif //SEMWORK_BRICK_H
