//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_WALL_H
#define SEMWORK_WALL_H

#include "GameObject.h"
#include "Rectangle.h"

class Wall: public Rectangle{
    double xmin,ymin,xmax,ymax;
public:
    Wall(double x1,double y1,double x2,double y2): xmin(std::min(x1,x2)), ymin(std::min(y1,y2)), xmax(std::max(x1,x2)+1), ymax(std::max(y1,y2)+1),
                                                   Rectangle(std::min(x1, x2), std::min(y1, y2), std::max(x1, x2) + 1, std::max(y1, y2) + 1){    }
    void Update(GameObject *map) override{};
    void Collide(GameObject *gay) override{};
    void show(ViewField &f) override{
        for (int x = int(xmin); x < int(xmax); ++x) {
            for (int y = int(ymin); y < int(ymax); ++y) {
                f.Set(int(x),int(y),'#');
            }
        }
    }
};

#endif //SEMWORK_WALL_H
