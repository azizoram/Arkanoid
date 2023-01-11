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

void Ball::Update(GameObject *map) {

    Section path(curPos(), nextPos());
    path.prev = prev;
    Section *s = map->nearest_intersected(path);
    if (s) {
        auto pair = s->intersection(path);
        x = pair.x;
        y=pair.y;
        a = s->ReflectedAngle(pair,a);
        Collide(s);
        s->Collide(this);
    } else{
        auto p=nextPos();
        x=p.x;
        y=p.y;
    }
}
