//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_GAYBAR_H
#define SEMWORK_GAYBAR_H

#include "GayObject.h"

class GayBar: public GayObject{
public:
    GayBar(double x,double y): GayObject(){}
    char getChar() override{
        return '=';
    }
};
#endif //SEMWORK_GAYBAR_H
