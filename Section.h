//
// Created by ramir on 24.12.2022.
//

#ifndef SEMWORK_SECTION_H
#define SEMWORK_SECTION_H

#include <algorithm>
#include <vector>
#include "Point.h"
#include <stdio.h>
#include <cfloat>
#define PI 3.14159265
#define EPS 0.000000001
inline double area (Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1 (double a, double b, double c, double d) {
    if (a > b)  std::swap (a, b);
    if (c > d)  std::swap (c, d);
    return std::max(a,c) <= std::min(b,d);
}

class Section{
    bool intersectb (Point a, Point b, Point c, Point d) {
        return intersect_1 (a.x, b.x, c.x, d.x)
               && intersect_1 (a.y, b.y, c.y, d.y)
               && ((std::signbit(area(a,b,c)) ? -1: 1) * (std::signbit(area(a,b,d)) ? -1: 1) < 0 ||
                   std::abs(area(a,b,c) * area(a,b,d))<=DBL_EPSILON)
               && ((std::signbit(area(c,d,a)) ? -1: 1) * (std::signbit(area(c,d,b))? -1: 1) < 0||
                   std::abs(area(c,d,a) * area(c,d,b))<=DBL_EPSILON);
    }
    double norm(double a){
        if(a<0)
            return norm(a+360);
        return std::fmod(a,360);
    }
public:
    Point p,q;
    Section(Point p1,Point p2):p(p1),q(p2){}
    std::pair<Point,double> intersection(Section &s){
        Point A=p;
        Point B=q;
        Point C=s.p;
        Point D=s.q;
        if(!intersectb(A,B,C,D))
            return {NoPoint(),0};

        // Line AB represented as a1x + b1y = c1
        double a1 = B.y - A.y;
        double b1 = A.x - B.x;
        double c1 = a1*(A.x) + b1*(A.y);

        // Line CD represented as a2x + b2y = c2
        double a2 = D.y - C.y;
        double b2 = C.x - D.x;
        double c2 = a2*(C.x)+ b2*(C.y);

        double determinant = a1*b2 - a2*b1;

        if (determinant == 0)
        {
            // The lines are parallel. This is simplified
            // by returning a pair of FLT_MAX
            return {NoPoint(),0};
        }
        else
        {
            double x = (b2*c1 - b1*c2)/determinant;
            double y = (a1*c2 - a2*c1)/determinant;
            double dx1=B.x-A.x;
            double dy1=B.y-A.y;
            double dx2=D.x-C.x;
            double dy2=D.y-C.y;
            double ang1= dy1==0? 90: atan(dx1/dy1)*180/PI;
            double ang2= dy2==0? 90: atan(dx2/dy2)*180/PI;
            if(sin(ang1*PI/180)*dx1<0)
                ang1=norm(ang1+180);
            if(sin(ang2*PI/180)*dx2<0)
                ang2=norm(ang2+180);
            return {Point(x, y),norm(2*ang2-ang1)};
        }
    }

};
#endif //SEMWORK_SECTION_H
