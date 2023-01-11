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
#include "Ball.h"
#include "Paddle.h"
#include "Bottom.h"
#include "Brick.h"
#include <random>
#include <time.h>
#include "Map.h"
#include <mutex>

/**
 * Arkanoid wraps of game, stores map
 */
class Arkanoid{
    Map *map; /**< Object that represents game map ai all game objects >**/
    int ballsn=5; /**< Number of ball left >**/
    bool working=true; /**< Working status >**/
    std::mutex update_mtx;
public:
    Arkanoid(Map *m):map(m){
    }
    ~Arkanoid(){
        delete map;
    }
    void stop(){
        working=false;
    }
    /**
     * Run game
     */
    void run(){
        while(working){
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            update_mtx.lock();
            for(auto object:map->objects)
                object->Update(map);
            update_mtx.unlock();
        }
    }
    /**
     * Write out and update console
     */
    void print(){
        while(working) {
            ViewField f(map->w,map->h);
            map->show(f);
            f.print();
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            printf("\x1B[2J\x1B[H");
        }
        printf("\x1B[2J\x1B[H");
    }
    /**
     * Read from input and update internal state
     */
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
                    update_mtx.lock();
                    if (lx  > 0)
                        map->bar->move(-1);
                    else
                        map->bar->move(-lx);
                    update_mtx.unlock();
                    break;
                case 'd':
                    update_mtx.lock();
                    if (rx < map->w)
                        map->bar->move(1);
                    else
                        map->bar->move(map->w-rx);
                    update_mtx.unlock();
                    break;
                case ' ':
                    if(ballsn>0){
                        std::random_device rd;
                        std::default_random_engine eng(rd());
                        std::uniform_real_distribution<double> distr(100, 260);
                        ballsn--;
                        Ball* ball=new Ball((lx+rx)/2, map->bar->p.y-1.5, distr(eng), 0.2);
                        map->objects.push_back(ball);
                    }
                    break;
            }
        }
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    }
};
#endif //SEMWORK_ARKANOID_H
