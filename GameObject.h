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
    GameObject *parent= nullptr;
    GameObject *prev= nullptr;
    virtual ~GameObject(){};
    virtual bool intersects(const Section& s){return false;}
    virtual Section *nearest_intersected(Section &s){return nullptr;};
    virtual void Update(GameObject *map){};
    virtual void Collide(GameObject* gay){
        if(parent)parent->Collide(gay);
    };
    virtual void show(ViewField &field){};
    virtual bool deadly(){return false;}
};
#endif //SEMWORK_GAMEOBJECT_H
