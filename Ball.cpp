//
// Created by ramir on 23.12.2022.
//

#include "Ball.h"

Point Ball::nextPos(){
    if(!dead) {
        double angle = a * PI / 180;
        return {x + (sin(angle) * s), y + (cos(angle) * s)};
    }
    return NoPoint();
}
void Ball::Collide(GameObject *gameObject) {
    prev=gameObject;
    if(gameObject->deadly()) {
        dead = true;
        x = NoPoint().x;
        y = NoPoint().y;
        a = 0;
        s = 0;
    }

}
