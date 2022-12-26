//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_BRICK_H
#define SEMWORK_BRICK_H
#include "GayObject.h"

class Brick: public GayObject{
    unsigned int h;//health
public:
    Brick(double x,double y,int h): GayObject(x,y), h(h){}
    void Collide(GayObject &obj) override {h--;};

    char getChar() override{
        return '0'+h;
    }
};
#endif //SEMWORK_BRICK_H
