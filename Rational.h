//
// Created by ramir on 26.12.2022.
//

#ifndef SEMWORK_RATIONAL_H
#define SEMWORK_RATIONAL_H

#include <cmath>

class Rational {
long int num,den;
    int gcd(long int a ,long int b)
    {
        if(b==0) return a;
        a%=b;
        return gcd(b,a);
    }
Rational& norm(){
        if(!num){
            den=1;
            return *this;
        }
        if(!den){
            num=den;
            return *this;
        }
        if(den<0){
            den*=-1;
            num*=-1;
        }
    int g= abs(gcd(den,num));
    if(g) {
        den /= g;
        num /= g;
    }
    return *this;
}
public:
    Rational(int n): Rational(n,1){}
    Rational(double a){
        // Fetch integral value of the decimal
        double intVal = floor(a);

        // Fetch fractional part of the decimal
        double fVal = a - intVal;

        // Consider precision value to
        // convert fractional part to
        // integral equivalent
        const long pVal = 1000000000;

        // Calculate GCD of integral
        // equivalent of fractional
        // part and precision value
        long long gcdVal
                = gcd(round(fVal * pVal), pVal);

        // Calculate num and deno
        den = pVal / gcdVal;
        num
                = (intVal * den) + round(fVal * pVal) / gcdVal;
        int d=0;
    }
    Rational(long int n,long int d):num(n),den(d){norm();}
    Rational& sum(const Rational &r){
        num=num * r.den + den * r.num;
        den=den * r.den;
        norm();
        return *this;
    }
    Rational& mul(const Rational &r){
        num=num * r.num;
        den=den * r.den;
        norm();
        return *this;
    }
    Rational& operator+ (const Rational r){return sum(r);}
    Rational& operator- (const Rational r){return sum(Rational(-1)*r);}
    Rational& operator* (const Rational r){return mul(r);}
    Rational& operator/ (const Rational r){return mul({r.den,r.num});}
    bool operator== (const Rational r) const{
        return num==r.num&&den==r.den;
    }
    bool operator== (int r) const{
        return *this == Rational(r);
    }
    bool operator< (const Rational r) const{
        return (double(num)/double(den))<(double(r.num)/double(r.den));
    }
    operator double() const{return double(num)/double(den);}
    Rational& sqrt(){
        num=std::sqrt(num);
        den=std::sqrt(den);
        norm();
        return *this;
    }
    bool isnan(){return !den;}
};


#endif //SEMWORK_RATIONAL_H
