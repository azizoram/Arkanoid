//
// Created by ramir on 24.12.2022.
//

#ifndef SEMWORK_SECTION_H
#define SEMWORK_SECTION_H

#include <algorithm>
#include "Point.h"
#include <stdio.h>
#define PI 3.14159265
#define EPS 0.000000001
#include "Rational.h"
class Section{
    double norm(double a){
        if(a<0)
            return norm(a+360);
        return std::fmod(a,360);
    }
public:
    Point p,q;
    Section(Point p1,Point p2):p(p1),q(p2){}
    std::pair<Point,double> intersection(Section &s){


        Rational dx1=p.x-q.x;
        Rational dx2=s.p.x-s.q.x;
        if(dx1==0){
            Rational dx2=s.p.x-s.q.x;
            Rational dy2=s.p.y-s.q.y;
            Rational a2=dy2/dx2;
            Rational b2=s.p.y-(a2*s.p.x);
            Rational y2=a2*s.p.x+b2;
            double ang1=0;
            double ang2=atan(dx2/dy2)*180/PI;
            if(y2>=std::min(p.y,q.y)&&y2<=std::max(p.y,q.y)&&
                    y2>=std::min(s.p.y,s.q.y)&&y2<=std::max(s.p.y,s.q.y)&&
                    p.x>=std::min(s.p.x,s.q.x)&&p.x<=std::max(s.p.x,s.q.x))
                return {{p.x, y2},norm(2*ang2-ang1)};
            else
                return {NoPoint(),0};
        }
        if(dx2==0){
            Rational dx1=p.x-q.x;
            Rational dy1=p.y-q.y;
            Rational a1=dy1/dx1;
            Rational b1=p.y-(a1*p.x);
            Rational y1=a1*p.x+b1;
            double ang1=atan(dx1/dy1)*180/PI;
            double ca=cos(ang1*PI/180);
            double sa=sin(ang1*PI/180);
            ang1=norm(ang1+180);
            if(ca*dy1<0)
                ang1=norm(ang1+180);
            double ang2=0;
            if(y1>=std::min(s.p.y,s.q.y)&&y1<=std::max(s.p.y,s.q.y)&&
                    y1>=std::min(p.y,q.y)&&y1<=std::max(p.y,q.y)&&
                    s.p.x>=std::min(p.x,q.x)&&s.p.x<=std::max(p.x,q.x))
                return {{s.p.x, y1},norm(2*ang2-ang1)};
            else
                return {NoPoint(),0};
        }
        Rational dy1=p.y-q.y;
        Rational a1=dy1/dx1;
        Rational b1=p.y-(a1*p.x);
        Rational dy2=s.p.y-s.q.y;
        Rational a2=dy2/dx2;
        Rational b2=s.p.y-(a2*s.p.x);
        Rational ix=(b1-b2)/(a2-a1);
        Rational iy=a1*ix+b1;
        double ang1=atan(dx1/dy1)*180/PI;
        double ca=cos(ang1*PI/180);
        double sa=sin(ang1*PI/180);
        ang1=norm(ang1+180);
        if(ca*dy1<0)
            ang1=norm(ang1+180);
        double ang2=atan(dx2/dy2)*180/PI;
        if(ix>=std::min(p.x,q.x)&&ix<=std::max(p.x,q.x)&&
           iy>=std::min(p.y,q.y)&&iy<=std::max(p.y,q.y)&&
           ix>=std::min(s.p.x,s.q.x)&&ix<=std::max(s.p.x,s.q.x)&&
           iy>=std::min(s.p.y,s.q.y)&&iy<=std::max(s.p.y,s.q.y)) {
            return {{ix, iy}, norm(2 * ang2 - ang1)};
        }
        else
            return {NoPoint(),0};
    }
};
#endif //SEMWORK_SECTION_H
