//
// Created by ramir on 29.12.22.
//

#ifndef SEMWORK_COMPLEXOBJECT_H
#define SEMWORK_COMPLEXOBJECT_H
#include <utility>
#include <vector>
#include <limits>
#include "GameObject.h"
#include "Section.h"
class ComplexObject: public GameObject {
public:
    std::vector<GameObject *> objects;
    ComplexObject(std::vector<GameObject *> s): objects(std::move(s)){
        for(auto o:objects)
            o->parent=this;
    }
    ~ComplexObject(){
        for(auto s:objects)
            delete s;
    }
    bool intersects(const Section& s) override{
        for(auto section:objects)
            if(section->intersects(s))
                return true;
        return false;
    }
    virtual Point intersection(Section &s){

        double min = std::numeric_limits<double>::max();
        Point r= NoPoint();
        for(auto object:objects){
            auto point=object->nearest_intersected(s)->intersection(s);
            if(min>point.distance(s.p)){
                min=s.p.distance(point);
                r=point;
            }
        }
        return r;
    }
    Section *nearest_intersected(Section &s) override{
        if(!intersects(s))
            return nullptr;
        double min = std::numeric_limits<double>::max();
        Section *sec= nullptr;
        for(auto object:objects) {
            if (object->intersects(s)&&s.prev!=object){
                auto ni=object->nearest_intersected(s);
                if (ni) {
                    Point p = ni->intersection(s);
                    if (p.distance(s.p) < min) {
                        sec = object->nearest_intersected(s);
                        min = p.distance(s.p);
                    }
                }
            }
        }
        return sec;
    }
    virtual void Update(GameObject *map) {};

    virtual void Collide(GameObject* gay){}
    virtual void show(ViewField &field){
        for(auto obj:objects)
            obj->show(field);
    }
};


#endif //SEMWORK_COMPLEXOBJECT_H
