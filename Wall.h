//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_WALL_H
#define SEMWORK_WALL_H

#include "GayObject.h"
#include "Fourangle.h"

class Wall: public Fourangle{
    double xmin,ymin,xmax,ymax;
public:
    Wall(double x1,double y1,double x2,double y2):xmin(std::min(x1,x2)),ymin(std::min(y1,y2)),xmax(std::max(x1,x2)+1),ymax(std::max(y1,y2)+1),
    Fourangle(std::min(x1,x2), std::min(y1,y2),std::max(x1,x2)+1,std::max(y1,y2)+1){    }
    void Update() override{};
    void Collide(GayObject *gay) override{};
    char getChar() override{
        return '#';
    }
    void show(ViewField &f) override{
        for (int x = int(xmin); x < int(xmax); ++x) {
            for (int y = int(ymin); y < int(ymax); ++y) {
                f.Set(int(x),int(y),'#');
            }
        }
    }
};

#endif //SEMWORK_WALL_H
