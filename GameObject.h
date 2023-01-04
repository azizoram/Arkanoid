//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_GAMEOBJECT_H
#define SEMWORK_GAMEOBJECT_H

#include <utility>
#include "ViewField.h"
class Point;
class Section;
class GameObject{
public:
    GameObject *prev= nullptr;
    virtual ~GameObject(){};
    virtual std::pair<Point,double> intersection(Section &s)=0;
    virtual void Update()=0;
    virtual Point nextPos()=0;
    virtual Point curPos()=0;
    virtual void setPos(const Point& p)=0;
    virtual void setAng(double a)=0;
    virtual void Collide(GameObject* gay)=0;
    virtual void show(ViewField &field)=0;
    virtual bool deadly(){return false;}
};
#endif //SEMWORK_GAMEOBJECT_H
