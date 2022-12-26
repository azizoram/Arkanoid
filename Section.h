//
// Created by ramir on 24.12.2022.
//

#ifndef SEMWORK_SECTION_H
#define SEMWORK_SECTION_H

#include <algorithm>
#include "Point.h"

class Section{
public:
    Point p,q;
    Section(Point p1,Point p2):p(p1),q(p2){}
    Point intersection(Section &s){


        double dx1=p.x-q.x;
        double dx2=s.p.x-s.q.x;
        if(dx1==0){
            double dx2=s.p.x-s.q.x;
            double dy2=s.p.y-s.q.y;
            double a2=dy2/dx2;
            double b2=s.p.y-(a2*s.p.x);
            double y2=a2*s.p.x+b2;
            if(y2>=std::min(p.y,q.y)&&y2<=std::max(p.y,q.y)&&
                    y2>=std::min(s.p.y,s.q.y)&&y2<=std::max(s.p.y,s.q.y)&&
                    p.x>=std::min(s.p.x,s.q.x)&&p.x<=std::max(s.p.x,s.q.x))
                return {p.x,y2};
            else
                return NoPoint();
        }
        if(dx2==0){
            double dx1=p.x-q.x;
            double dy1=p.y-q.y;
            double a1=dy1/dx1;
            double b1=p.y-(a1*p.x);
            double y1=a1*p.x+b1;
            if(y1>=std::min(s.p.y,s.q.y)&&y1<=std::max(s.p.y,s.q.y)&&
                    y1>=std::min(p.y,q.y)&&y1<=std::max(p.y,q.y)&&
                    s.p.x>=std::min(p.x,q.x)&&s.p.x<=std::max(p.x,q.x))
                return {s.p.x,y1};
            else
                return NoPoint();
        }
        double dy1=p.y-q.y;
        double a1=dy1/dx1;
        double b1=p.y-(a1*p.x);
        double dy2=s.p.y-s.q.y;
        double a2=dy2/dx2;
        double b2=s.p.y-(a2*s.p.x);
        double ix=(b1-b2)/(a2-a1);
        double iy=a1*ix+b1;
        if(ix>=std::min(p.x,q.x)&&ix<=std::max(p.x,q.x)&&
           iy>=std::min(p.y,q.y)&&iy<=std::max(p.y,q.y)&&
           ix>=std::min(s.p.x,s.q.x)&&ix<=std::max(s.p.x,s.q.x)&&
           iy>=std::min(s.p.y,s.q.y)&&iy<=std::max(s.p.y,s.q.y))
            return {ix, iy};
        else
            return NoPoint();
    }
};
#endif //SEMWORK_SECTION_H
