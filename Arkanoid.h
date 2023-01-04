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
#include "GameObject.h"
#include "Wall.h"
#include "Ball.h"
#include "GameBar.h"
#include "Bottom.h"
#include "Brick.h"
#include <random>
#include <time.h>


class Arkanoid{
    std::vector<GameObject *> objects;
    int h,w;
    GameBar *bar;
    Ball *ball= nullptr;
    int ballsn;
    bool working=true;
public:
    Arkanoid(int h,int w,int b):h(h),w(w),ballsn(b){
        //objects.push_back(new Ball(w/2,h/2,0,0.6));
        objects.push_back(new Section({0,h},{0,0}));
        objects.push_back(new Section({0,0},{w,0}));
        objects.push_back(new Section({w,0},{w,h}));
        objects.push_back(new Bottom({w,h},{0,h}));
        for (int i = 0; i < w; ++i) {

            objects.push_back(new Brick(i,1,5));
        }
      //  objects.push_back(new Wall(0,h-1,w-1,h-1));
        bar=new GameBar(w / 2 + 1, h - 1, 5.5);
        objects.push_back(bar);
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
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            if(ball&&ball->dead)
                ball= nullptr;
            for(int i=0;i<objects.size();++i){
                double min = std::numeric_limits<double>::max();
                std::pair<Point,double> p= {NoPoint(),0};
                GameObject *obj= nullptr;
                Point op=objects[i]->curPos();
                Point np=objects[i]->nextPos();
                Section s={op,np};
                for(int j=0;j<objects.size();++j){
                    if(i!=j&& objects[j]!=objects[i]->prev ){
                        if(min>objects[j]->intersection(s).first.distance(op)){
                            min=objects[j]->intersection(s).first.distance(op);
                            p=objects[j]->intersection(s);
                            obj=objects[j];
                        }
                    }
                }
                if(!p.first.isNop()) {
                    objects[i]->setPos(p.first);
                    objects[i]->setAng(p.second);
                    objects[i]->Collide(obj);
                    obj->Collide(objects[i]);
                }
                else objects[i]->setPos(objects[i]->nextPos());

            }
        }
    }
    void print(){
        while(working) {
            ViewField f(w,h);
            for(auto o:objects)
                o->show(f);
            f.print();
            printf("Balls left: %d\n\r",ballsn);
            printf("Control keys:\n\r");
            printf("q - quit\n\r");
            printf("a - move gamebar left\n\r");
            printf("d - move gamebar right\n\r");
            printf("space - use ball\n\r");
            std::this_thread::sleep_for(std::chrono::milliseconds(20));

            printf("\x1B[2J\x1B[H\n\r");
            //for (int i = 0; i < h+2; ++i)
            //    printf("\033[1A\r");
        }
        printf("\x1B[2J\x1B[H\n\r");
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
                    x = bar->p.x;
                    if (x  > bar->w+1)
                        bar->move(-1);
                    else
                        bar->move(-(x-bar->w));
                    break;
                case 'd':
                    x = bar->p.x;
                    if (x+bar->w < w)
                        bar->move(1);
                    else
                        bar->move((w-bar->w)-x);
                    break;
                case ' ':
                    if(!ball&&ballsn>0){
                        std::random_device rd;
                        std::default_random_engine eng(rd());
                        std::uniform_real_distribution<double> distr(100, 260);
                        ballsn--;
                        ball=new Ball(bar->p.x+(bar->w*0.5), bar->p.y-1, distr(eng), 0.2);
                        objects.push_back(ball);
                    }
                    break;
            }
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
};
#endif //SEMWORK_ARKANOID_H
