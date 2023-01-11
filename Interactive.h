//
// Created by ramir on 30.12.22.
//

#ifndef SEMWORK_INTERACTIVE_H
#define SEMWORK_INTERACTIVE_H
#include "GameObject.h"

class Interactive: public GameObject{
public:
    ~Interactive()=0;
    virtual void interact(GameObject *obj);
};


#endif //SEMWORK_INTERACTIVE_H
