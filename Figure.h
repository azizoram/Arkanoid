//
// Created by user on 29.12.22.
//

#ifndef SEMWORK_FIGURE_H
#define SEMWORK_FIGURE_H
#include <vector>
#include <limits>
#include "GameObject.h"
#include "Section.h"
class Figure: public GameObject {
protected:
    std::vector<Section *> sections;
public:
    Figure(std::vector<Section *> s):sections(s){}
    ~Figure(){
        for(auto s:sections)
            delete s;
    }
    virtual std::pair<Point,double> intersection(Section &s){

        double min = std::numeric_limits<double>::max();
        std::pair<Point,double> r= {NoPoint(),0};
        for(auto section:sections){
            auto pair=section->intersection(s);
            if(min>pair.first.distance(s.p)){
                min=section->p.distance(s.p);
                r=pair;
            }
        }
        return r;
    }
    virtual void Update(){};
    virtual Point nextPos(){return sections[0]->nextPos();}
    virtual Point curPos(){return sections[0]->curPos();}
    virtual void setPos(const Point& p){ }
    virtual void setAng(double a){}
    virtual void Collide(GameObject* gay){}
    virtual void show(ViewField &field){}
};


#endif //SEMWORK_FIGURE_H
