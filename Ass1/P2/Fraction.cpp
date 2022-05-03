
#include "Fraction.h"

//default constructor make the fraction equal 0
Fraction::Fraction() {
num=0;
dem=1;
}
//parametrize constructor

Fraction::Fraction(int num, int dem) {
    this->num = num;
    this->dem = dem;
    this->simple();
}

//get greatest common divisor of two numbers
int Fraction::findGCD(int a, int b) {
    if (a % b == 0) {
        return b;
    }
    return findGCD(b, a % b);
}

//check if there is exist simplification on the division
void Fraction::simple() {
    int common;
    dem > num ? common = findGCD(dem, num) : common = findGCD(num, dem);

    num /= common;
    dem /= common;
}


Fraction Fraction::operator+(Fraction &obj) //adding operator
{
    Fraction fra;

    fra.num = (num * obj.dem) + (obj.num * dem);
    fra.dem = obj.dem * dem;
    fra.simple();
    return fra;
}

Fraction Fraction::operator-(Fraction &obj) //subtraction operator
{
    Fraction fra;

    fra.num = (num * obj.dem) - (obj.num * dem);
    fra.dem = obj.dem * dem;
    fra.simple();
    return fra;
}

Fraction Fraction::operator*(Fraction &obj) // multiplication operator
{
    Fraction fra;

    fra.num = num * obj.num;
    fra.dem = obj.dem * dem;
    fra.simple();
    return fra;
}

Fraction Fraction::operator/(Fraction &obj) // division operator
{
    Fraction fra;
    fra.num = num * obj.dem;
    fra.dem = obj.num * dem;
    fra.simple();
    return fra;
}

bool Fraction::operator>(const Fraction &obj) // greater than operator
{
    if ((float) num / (float) dem > (float) obj.num / (float) obj.dem)
        return true;
    else
        return false;
}

bool Fraction::operator<(const Fraction &obj) // less than operator
{
    if ((float) num / (float) dem < (float) obj.num / (float) obj.dem)
        return true;
    else
        return false;
}

bool Fraction::operator>=(const Fraction &obj) // greater than operator
{
    if ((float) num / (float) dem >= (float) obj.num / (float) obj.dem)
        return true;
    else
        return false;
}

bool Fraction::operator<=(const Fraction &obj) // less than operator
{
    if ((float) num / (float) dem <= (float) obj.num / (float) obj.dem)
        return true;
    else
        return false;
}


bool Fraction::operator==(const Fraction &obj) // equal operator
{
    if ((float) num / (float) dem == (float) obj.num / (float) obj.dem)
        return true;
    else
        return false;
}


istream &operator>>(istream &input, Fraction &obj) {
    char ch;
    input >> obj.num;
    cin >> ch;
    input >> obj.dem;

    if (obj.dem == 0)     //to check if there is logical error (dividing by 0)
    {
        cout << "Logical Error\n";
        exit(1);
    }
    obj.simple();
    return input;
}

ostream &operator<<(ostream &output, Fraction &obj) {


        output << obj.num << " / " << obj.dem;

    return output;
}


