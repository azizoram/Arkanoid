//
// Created by ramir on 23.12.2022.
//

#ifndef SEMWORK_PADDLE_H
#define SEMWORK_PADDLE_H

#include "GameObject.h"
#include "Point.h"

/**
 * \class represents paddle
 */
class Paddle: public Section{
public:
    double w;
    /**
     *
     * @param x - x coordinate of paddle center
     * @param y - y coordinate of paddle center
     * @param w - half of paddle width
     */
    Paddle(double x, double y, double w):  w(w),
                                          Section({x-w,y},{x+w,y}){}
    void show(ViewField &f) override{
        for (int x = ceil(p.x); x < floor(q.x); ++x) {
                f.Set(x,int(p.y),'_');
        }
    }
    /**
     * moves by x axis
     * @param d distance to move
     */
    void move(double d){
        p.x += d;
        q.x += d;
    }


    double ReflectedAngle(Point point,double a) override{
        double ang= 90;
        double rang=norm(2*ang-a);
        double drang=1-(std::abs(rang-180)/180);
        double dx=(point.x-(p.x+w));
        double da=0;
        if(dx<0){
            da=dx*(270-rang)/w;
        }else{
            da=dx*(rang-90)/w;
        }
        return rang-da;
    }
};
#endif //SEMWORK_PADDLE_H
