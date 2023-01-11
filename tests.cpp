//
// Created by ramir on 11.01.2023.
//
#include <cassert>
#include <limits>
#include "Section.h"
#include "Ball.h"


double norm(double a){
    if(a<0)
        return norm(a+360);
    return std::fmod(a,360);
}
bool EqualPoints(Point a,Point b){
    return (a.isNop() && b.isNop())||
    ((a.x-b.x)<0.0001 &&(a.y-b.y)<0.0001);
}
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
void testDistance(){
    printf("Testing eulidean distances\n");
    for (int i = 0; i < 10; ++i) {
        double x= fRand(0,100);
        double y= fRand(0,100);
        double a= fRand(0,100);
        double d= fRand(0,100);
        Point p1(x,y);
        Point p2(x+(sin(a)*d),y+(cos(a)*d));
        double cd=p1.distance(p2);
        double dd= fabs(cd-d);
        bool r=dd<(std::numeric_limits<double>::epsilon()*200);
        assert(r);
    }
    printf("Success\n");
}
void testInvalidDistance(){
    printf("Testing invalid eulidean distances\n");
    Point p1(fRand(0,100),fRand(0,100));
    Point p2(std::nan("NaN"), fRand(0,100));
    assert(std::isnan(p1.distance(p2)));
    printf("Success\n");
}
void testIntersectionCommutativity(){
    printf("Testing intersection commutative\n");
    for (int i = 0; i < 10; ++i) {
        Point(fRand(0,100),fRand(0,100));
        Section s1(Point(fRand(0,100),fRand(0,100)),Point(fRand(0,100),fRand(0,100)));
        Section s2(Point(fRand(0,100),fRand(0,100)),Point(fRand(0,100),fRand(0,100)));
        Point p1=s1.intersection(s2);
        Point p2=s2.intersection(s1);
        assert(EqualPoints(s1.intersection(s2),s2.intersection(s1)));
    }
    printf("Success\n");
}
void testIntersection(){
    printf("Testing intersection\n");
    for (int i = 0; i < 10; ++i) {


        Point p(fRand(0, 100), fRand(0, 100));

        double a1 = fRand(0, 360);
        double d1 = fRand(0, 100);
        double a2 = fRand(0, 360);
        double d2 = fRand(0, 100);
        Section s1({p.x - (sin(a1) * d1), p.y - (cos(a1) * d1)}, {p.x + (sin(a1) * d1), p.y + (cos(a1) * d1)});
        Section s2({p.x - (sin(a2) * d2), p.y - (cos(a2) * d2)}, {p.x + (sin(a2) * d2), p.y + (cos(a2) * d2)});
        Point p2 = s1.intersection(s2);
        assert(EqualPoints(p, p2));
    }
    printf("Success\n");
}

void testBallAngle(){

    printf("Testing intersection\n");
    for (int i = 0; i < 10; ++i) {
        double a = fRand(0, 360);
        double s = fRand(0, 100);
        double x = fRand(0, 100);
        double y = fRand(0, 100);
        Ball b(x,y,a,s);
        Point p1=b.curPos();
        Point p2=b.nextPos();
        assert(fabs(p1.distance(p2)-s)<0.0001);
    }
    printf("Success\n");
}
int main(){
    testDistance();
    testInvalidDistance();
    testIntersectionCommutativity();
    testIntersection();
    testBallAngle();
}