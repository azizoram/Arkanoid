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
#include "Paddle.h"
#include "Bottom.h"
#include "Brick.h"
#include <random>
#include <time.h>
#include "Map.h"

class Arkanoid{
    Map *map;
    std::vector<GameObject *> interactive_objects;
    int ballsn=5;
    bool working=true;
public:
    Arkanoid(Map *m):map(m){
    }
    ~Arkanoid(){
        delete map;
    }
    void stop(){
        working=false;
    }
    void run(){
        while(working){
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            for(auto object:interactive_objects)
                object->Update(map);
        }
    }
    void print(){
        while(working) {
            ViewField f(map->w,map->h);
            map->show(f);
            f.print();
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
            double lx = map->bar->p.x;
            double rx=map->bar->q.x;
            switch (c) {
                case 'q':
                    stop();
                    break;
                case 'a':
                    if (lx  > 0)
                        map->bar->move(-1);
                    else
                        map->bar->move(-lx);
                    break;
                case 'd':
                    if (rx < map->w)
                        map->bar->move(1);
                    else
                        map->bar->move(map->w-rx);
                    break;
                case ' ':
                    if(ballsn>0){
                        std::random_device rd;
                        std::default_random_engine eng(rd());
                        std::uniform_real_distribution<double> distr(100, 260);
                        ballsn--;
                        Ball* ball=new Ball((lx+rx)/2, map->bar->p.y-1.5, distr(eng), 0.2);
                        map->objects.push_back(ball);
                        interactive_objects.push_back(ball);
                    }
                    break;
            }
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
};
#endif //SEMWORK_ARKANOID_H
