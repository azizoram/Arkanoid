//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_GAYOBJECT_H
#define SEMWORK_GAYOBJECT_H

#include "Point.h"
#include "Section.h"
#include "ViewField.h"
class GayObject{
public:
    GayObject *prev=this;
    GayObject(){}
    virtual ~GayObject(){ }
    virtual std::pair<Point,double> intersection(Section &s){return {NoPoint(),0};}
    virtual void Update(){}
    virtual Point nextPos() {return NoPoint(); }
    virtual Point curPos() {return NoPoint(); }
    virtual void setPos(Point p) { }
    virtual void setAng(double a) { }
    virtual void Collide(GayObject* gay){}
    virtual char getChar(){return ' ';}
    virtual void show(ViewField &field){}
};
#endif //SEMWORK_GAYOBJECT_H
