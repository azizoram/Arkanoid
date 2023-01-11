//
// Created by ramir on 24.12.2022.
//

#ifndef SEMWORK_FOURANGLE_H
#define SEMWORK_FOURANGLE_H

#include <limits>
#include "ComplexObject.h"
#include "Section.h"


/**
 * \class Fourange is set by two points
 */
class Fourangle: public ComplexObject {

public:
    /**
     *
     * @param x1 - x coordinate of first point
     * @param y1 - y coordinate of first point
     * @param x2 - x coordinate of second point
     * @param y2 - y coordinate of second poing
     */
    Fourangle(double x1, double y1,double x2,double y2):
            ComplexObject({new Section({x1, y1}, {x2, y1}),
                       new Section({x2, y1}, {x2, y2}),
                       new Section({x2, y2}, {x1, y2}),
                       new Section({x1, y2}, {x1, y1})}){}
};


#endif //SEMWORK_FOURANGLE_H
