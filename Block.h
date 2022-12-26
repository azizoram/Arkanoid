//
// Created by ramir on 24.12.2022.
//

#ifndef SEMWORK_BLOCK_H
#define SEMWORK_BLOCK_H
#include "Section.h"
#include "GayObject.h"
class Block: public GayObject {
    Section s1,s2,s3,s4;
public:
    Block(int x,int y): GayObject(x,y), s1({x,y},{x+1,y}),s2({x,y},{x,y+1}),s3({x+1,y},{x+1,y+1}),s4({x+1,y+1},{x,y+1}){}
    Point intersection(Section &s) {
        double min = std::numeric_limits<double>::max();
        Point p=NoPoint();
        Point ps[4]={s1.intersection(s),s2.intersection(s),s3.intersection(s),s4.intersection(s)};
        for (int i = 0; i < 4; ++i) {
            if(ps[i].distance(s.p)<min){
                min=ps[i].distance(s.p);
                p=ps[i];
            }
        }
        return p;
    }
};


#endif //SEMWORK_BLOCK_H
