//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_ARKANOID_H
#define SEMWORK_ARKANOID_H
#include <chrono>
#include <termios.h>
#include <unistd.h>
#include <thread>
#include <vector>
#include <array>
#include <string>
#include "GayObject.h"
#include "Wall.h"
#include "Ball.h"
#include "GayBar.h"
#include <random>
#include <time.h>


class Arkanoid{
    std::vector<GayObject *> objects;
    int h,w;
    GayBar *bar;
    bool working=true;
public:
    Arkanoid(int h,int w,double ang):h(h),w(w){
        objects.push_back(new Ball(w/2,h/2,ang,0.6));
        for (int i = 1; i < w-1; ++i) {
            objects.push_back(new Wall(i,0));
            objects.push_back(new Wall(i,h-2));
        }
        for (int i = 1; i < h; ++i) {
            objects.push_back(new Wall(0,i));
            objects.push_back(new Wall(w-1,i));
        }
        std::uniform_real_distribution<double> unif(0,360);
        std::default_random_engine re;
        double a = std::fmod(time(nullptr),360);
        //bar=new GayBar(w/2,h-1);
        //objects.push_back(bar);
    }
    ~Arkanoid(){
        for(auto o:objects)
            delete o;
    }
    void stop(){
        working=false;
    }
    void run(){
        while(working){
            std::this_thread::sleep_for(std::chrono::milliseconds(40));
            for(int i=0;i<objects.size();++i){
                double min = std::numeric_limits<double>::max();
                Point p=NoPoint();
                GayObject *obj= nullptr;
                Point op=objects[i]->point;
                Point np=objects[i]->nextPos();
                Section s={op,np};
                for(int j=0;j<objects.size();++j){
                    if(i!=j){
                        if(objects[j]->intersection(s).distance(op)<min){
                            min=objects[j]->intersection(s).distance(op);
                            p=objects[j]->intersection(s);
                            obj=objects[j];
                        }
                    }
                }
                if(!p.isNop()) {
                    objects[i]->setPoint(p);
                    objects[i]->Collide(*obj);
                    obj->Collide(*objects[i]);
                }
                else
                    objects[i]->setPoint(objects[i]->nextPos());

            }
        }
    }
    void print(){
        while(working) {
            //std::cout.clear();
            auto count = std::vector<std::vector<GayObject *>>();
            for (int i = 0; i < h * w; ++i)
                count.push_back({});
            for (auto o: objects) {
                int i = int(o->point.y) * w + int(o->point.x);
                count[i].push_back(o);
            }
            for (int i = 0; i < h * w; ++i) {
                if (!(i % w))
                    printf("\n\r");
                if (count[i].size() > 1)
                    printf("Ж");
                else if (count[i].size() == 1)
                    printf("%s", std::string(1, count[i][0]->getChar()).c_str());
                else
                    printf(" ");
            }
            printf("\n\r");
            std::this_thread::sleep_for(std::chrono::milliseconds(80));

            //printf("\x1B[2J\x1B[H\n");
            for (int i = 0; i <= h; ++i)
                printf("\033[1A\r");
        }
        printf("\x1B[2J\x1B[H\n");
    }
    void control(){
        termios oldt;
        tcgetattr(STDIN_FILENO, &oldt);
        termios newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        while(working){
            char c=getchar();
            printf("\r\b\33[K");
            double x = 0;
            switch (c) {
                case 'q':
                    stop();
                    break;
                case 'a':
                    //x = bar->getX();
                    //if (x - 1 > 0)
                        //bar->setX(x - 1);
                    break;
                case 'd':
                    //x = bar->getX();
                    //if (x+2 < w)
                        //bar->setX(x + 1);
                    break;
            }
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
};
#endif //SEMWORK_ARKANOID_H
