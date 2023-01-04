//
// Created by ramir on 24.12.2022.
//

#ifndef SEMWORK_FOURANGLE_H
#define SEMWORK_FOURANGLE_H

#include <limits>
#include "Figure.h"
#include "Section.h"
class Fourangle: public Figure {

public:
    Fourangle(double x1, double y1,double x2,double y2):
            Figure({new Section({x1, y1}, {x2, y1}),
                       new Section({x2, y1}, {x2, y2}),
                       new Section({x2, y2}, {x1, y2}),
                       new Section({x1, y2}, {x1, y1})}){}
};


#endif //SEMWORK_FOURANGLE_H
