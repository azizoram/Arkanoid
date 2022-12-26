//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_WALL_H
#define SEMWORK_WALL_H

#include "GayObject.h"
#include "Block.h"

class Wall: public Block{
public:
    Wall(double x,double y): Block(x,y){}
    void Update() override{};
    void Collide(GayObject &gay) override{};
    char getChar() override{
        return '#';
    }
};

#endif //SEMWORK_WALL_H
