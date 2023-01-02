//
// Created by ramir on 24.12.2022.
//

#ifndef SEMWORK_FOURANGLE_H
#define SEMWORK_FOURANGLE_H

#include <limits>
#include "Section.h"
#include "GayObject.h"
class Fourangle: public GayObject {

protected:
    Section s1,s2,s3,s4;
public:
    Fourangle(double x1, double y1,double x2,double y2):
    s1({x1, y1}, {x2, y1}),
    s2({x2, y1}, {x2, y2}),
    s3({x2, y2}, {x1, y2}),
    s4({x1, y2}, {x1, y1}){}
    std::pair<Point,double> intersection(Section &s) {
        double min = std::numeric_limits<double>::max();
        std::pair<Point,double> r= {NoPoint(),0};
        std::pair<Point,double> ps[4]={s.intersection(s1),s.intersection(s2),s.intersection(s3),s.intersection(s4)};
        for (int i = 0; i < 4; ++i) {
            if(min>ps[i].first.distance(s.p)){
                min=ps[i].first.distance(s.p);
                r=ps[i];
            }
        }
        return r;
    }
};


#endif //SEMWORK_FOURANGLE_H
