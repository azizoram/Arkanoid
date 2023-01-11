//
// Created by ramir on 30.12.22.
//

#ifndef SEMWORK_MAP_H
#define SEMWORK_MAP_H


#include <iostream>
#include <string>
#include "ComplexObject.h"
#include "Brick.h"
#include "Bottom.h"
#include "Paddle.h"

class Map: public ComplexObject {
public:
    int w=-1;
    int h=0;
    Paddle *bar= nullptr;
    Map(std::istream& is): ComplexObject({}){
        std::string line;
        while(true){
            std::getline(is,line,'\n');
            if(!line.size())
                break;

            if(w==-1)
                w=line.size();
            if(line.size()!=w)
                throw 0;

            for(int i=0;i<w;++i){
                char ch=line[i];
                if(ch>='0'&&ch<='9')
                    objects.push_back(new Brick(i,h,ch-'0'));
            }
            ++h;
        }
        objects.push_back(new Section({0,h},{0,0}));
        objects.push_back(new Section({0,0},{w,0}));
        objects.push_back(new Section({w,0},{w,h}));
        objects.push_back(new Bottom({w,h},{0,h}));
        bar=new Paddle(w / 2 + 1, h - 1, w / 4);
        objects.push_back(bar);
    }
};


#endif //SEMWORK_MAP_H
