
#ifndef UNTITLED12_FRACTION_H
#define UNTITLED12_FRACTION_H
#include <iostream>
using namespace std;

class Fraction {

private:
    int num;
    int dem;
public:
    //constructors

    Fraction();
    Fraction(int, int);

    //get greatest common divisor of two numbers
    int findGCD(int num, int dem);

    //simplify the numenator and demorator by dividing them on GCD
    void simple();

    //input operator
    friend istream& operator >> (istream&,Fraction&);

    //output operator
    friend ostream& operator << (ostream&,  Fraction&);

    //Arthemitic operators(adding,subtracting, multiplying, dividing)
    Fraction operator +(Fraction&);
    Fraction operator -(Fraction&);
    Fraction operator *(Fraction&);
    Fraction operator /(Fraction&);

    //comparison operators
    bool operator==(const Fraction& );
    bool operator>(const Fraction&);
    bool operator<(const Fraction&);
    bool operator>=(const Fraction&);
    bool operator<=(const Fraction&);

};


#endif //UNTITLED12_FRACTION_H
