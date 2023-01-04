//
// Created by user on 29.12.22.
//

#ifndef SEMWORK_BOTTOM_H
#define SEMWORK_BOTTOM_H


#include "Section.h"

class Bottom: public Section {
    int score=0;
public:
    Bottom(Point p1,Point p2): Section(p1,p2){}
    void Collide(GameObject *gay) {
        score++;
    }
    bool deadly() override{return true;}
};


#endif //SEMWORK_BOTTOM_H
