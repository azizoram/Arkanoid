//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_GAMEOBJECT_H
#define SEMWORK_GAMEOBJECT_H

#include <utility>
#include "ViewField.h"
class Point;
class Section;
/**
 * @class GameObject abstract class that represents game objects
 */
class GameObject{
public:
    /**< All objects are represented as composite object, so @atribut parent is parent of whole game object >**/
    GameObject *parent= nullptr;
    /**< @atribut prev is the last object interacted with >**/
    GameObject *prev= nullptr;
    virtual ~GameObject(){};
    /**< @returns true if this sections intersects with object or false if not >**/
    virtual bool intersects(const Section& s){return false;}
    /**< Returns pointer of the nearest section which is part of this object and intersects with given section
     * if exists>**/
    virtual Section *nearest_intersected(Section &s){return nullptr;};
    /**< Update state of game object and map >**/
    virtual void Update(GameObject *map){};
    /**< The method that is called when objects collide >**/
    virtual void Collide(GameObject* gameObject){
        if(parent)parent->Collide(gameObject);
    };
    /**< Method which implements the graphical representation of the object >**/
    virtual void show(ViewField &field){};
    /**< @return true if this object is deadly to ball >**/
    virtual bool deadly(){return false;}
};
#endif //SEMWORK_GAMEOBJECT_H
