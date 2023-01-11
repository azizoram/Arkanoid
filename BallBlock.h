//
// Created by ramir on 31.12.22.
//

#ifndef SEMWORK_BALLBLOCK_H
#define SEMWORK_BALLBLOCK_H

#include <random>
#include "Brick.h"
#include "Ball.h"
#include "Map.h"

class BallBlock : public Brick{
    Ball ball;
    double randomangle(){
        std::random_device rd;
        std::default_random_engine eng(rd());
        std::uniform_real_distribution<double> distr(0, 360);
        return distr(eng);
    }
public:
    BallBlock(double x, double y): Brick(x,y,1),ball(x+0.5,y+0.5, randomangle(),0.2){


    };
    void Collide(GameObject *obj) override {
        if(h>0)
            Brick::Collide(obj);
        else
            ball.Collide(obj);

    };

    void Update(GameObject *map) override{
        if(h>0)
            Brick::Update(map);
        else
            ball.Update(map);
    }
    void show(ViewField &f) override{
        if(h>0)
            f.Set(int(x),int(y),'!');
        else
            ball.show(f);
    }
};


#endif //SEMWORK_BALLBLOCK_H
