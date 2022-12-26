//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_GAYOBJECT_H
#define SEMWORK_GAYOBJECT_H

#include "Point.h"
#include "Section.h"

class GayObject{
public:
    Point point;
    GayObject(double x,double y):point(x,y){}
    virtual ~GayObject(){ }
    virtual Point intersection(Section &s){return NoPoint();}
    virtual void Update(){}
    virtual Point nextPos(){return point;}
    virtual void Collide(GayObject& gay){}
    virtual char getChar(){return ' ';}
    void setPoint(Point p){point=p;}
};
#endif //SEMWORK_GAYOBJECT_H
