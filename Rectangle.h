//
// Created by ramir on 24.12.2022.
//

#ifndef SEMWORK_RECTANGLE_H
#define SEMWORK_RECTANGLE_H

#include <limits>
#include "ComplexObject.h"
#include "Section.h"
class Rectangle: public ComplexObject {

public:
    Rectangle(double x1, double y1, double x2, double y2):
            ComplexObject({new Section({x1, y1}, {x2, y1}),
                           new Section({x2, y1}, {x2, y2}),
                           new Section({x2, y2}, {x1, y2}),
                           new Section({x1, y2}, {x1, y1})}){}
};


#endif //SEMWORK_RECTANGLE_H
