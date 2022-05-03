#ifndef BIGDECIMALINT_H_INCLUDED
#define BIGDECIMALINT_H_INCLUDED

#include <bits/stdc++.h>
using namespace std;

///Class Prototypes
class BigDecimalInt
{
private:
    int* number, currCapacity;
    bool sign;
public:
    BigDecimalInt(string);
    BigDecimalInt(int);
    BigDecimalInt(const BigDecimalInt&);
    BigDecimalInt operator+(BigDecimalInt);
    BigDecimalInt operator-(BigDecimalInt);
    BigDecimalInt& operator=(BigDecimalInt);
    bool operator>(const BigDecimalInt&);
    ~BigDecimalInt();
    int size();
    friend ostream& operator << (ostream&,const BigDecimalInt&);
};

#endif // BIGDECIMALINT_H_INCLUDED
