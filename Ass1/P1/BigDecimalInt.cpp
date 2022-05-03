#include "BigDecimalInt.h"

///constructor to initialize BigInt from string
BigDecimalInt::BigDecimalInt(string decStr)
{
    int len = decStr.size();
    this->sign = 1;
    if(decStr[0] == '-'){ this->sign = 0; }
    int start = 0;

    ///to skip the case of bad inputs like -         44444 or +         444444
    while(!(decStr[start] >= '0' && decStr[start] <= '9'))
    {
        start++;
    }

    len -= start;
    bool zeroArray = 1;

    for(int i=0;i<len;i++)
    {
        if(decStr[i] != '0')
        {
            zeroArray = 0;
            break;
        }
    }

    ///to handle the case if input "0000000000000"
    if(zeroArray)
    {
        this->number = new int[1];
        this->number[0] = 0;
        this->currCapacity = 1;

    }else
    {
        this->number = new int[len];
        decStr = decStr.substr(start);
        ///store digit by digit in our array we store in reverse order we subtract from '0'
        ///which has value 48 in ascii table to convert from char to int
        for(int i=1;i<=len;i++){ this->number[i-1] = decStr[len-i] - '0'; }
        this->currCapacity = len;
    }
}

///constructor to initialize from interger
BigDecimalInt::BigDecimalInt(int decInt)
{

    ///if this->sign = 0 the number is negative else it's positive
    this->sign = (decInt < 0) ? 0:1;
    if(!this->sign){ decInt*=-1; }
    int temp = decInt, len = 0;

    ///to get the length of the integer
    while(decInt)
    {
        len++;
        decInt/=10;
    }

    this->currCapacity = len;
    this->number = new int[len];

    ///store digit by digit in our array we store in reverse order
    for(int i=0;i<len;i++)
    {
        this->number[i] = temp%10;
        temp/=10;
    }
}

///apply copy constructor to avoid common isssues
BigDecimalInt::BigDecimalInt(const BigDecimalInt& anotherDec)
{
    this->currCapacity = anotherDec.currCapacity;
    this->number = new int[this->currCapacity];
    for(int i=0;i<this->currCapacity;i++){
        this->number[i] = anotherDec.number[i];
    }
    this->sign = anotherDec.sign;
}

///overload the greater than sign to help us subtraction or to help us decide which BigInt is bigger
bool BigDecimalInt::operator>(const BigDecimalInt& anotherDec)
{
    ///see the sign
    if(this->sign == 1 && anotherDec.sign == 0){ return true; }
    if(this->sign == 0 && anotherDec.sign == 1){ return false; }

    ///return true if this > another, false if this < another
    if(this->currCapacity > anotherDec.currCapacity){ return (this->sign == 1) ? true : false; }

    if(this->currCapacity < anotherDec.currCapacity){ return (this->sign == 0) ? true : false; }
    ///if same size compare digit to digit from back
    for(int i=this->currCapacity-1;i>-1;i--){
        if(this->number[i] > anotherDec.number[i]){
            return (this->sign == 1) ? true : false;
        }
        if(this->number[i] < anotherDec.number[i]){
            return (this->sign == 1) ? false : true;
        }
    }
    ///they are equal so return false
    return false;
}

///destructor to free up the reserved space
BigDecimalInt::~BigDecimalInt(){ delete[] number; }

///overload the plus operator to better dealing with BigInts
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec)
{
    if(this->sign != anotherDec.sign)
    {
        ///If the sign is not equal in both number then it's a subtraction case so we are just subtract in the right order
        ///using temp variables to avoid changing the sign in the original number
        BigDecimalInt temp1 = *this, temp2 = anotherDec;
        temp1.sign = 1, temp2.sign = 1;
        return (this->sign == 1) ? temp1 - temp2 : temp2 - temp1;
    }

    ///if we have a number with n digits and another one with m digits then the resulting number
    ///will not have a length more than max(n, m) + 1 in case of overflow
    int maxSize = max(this->currCapacity, anotherDec.currCapacity) + 1;

    ///store the result in a new dynamic array
    int* temp = new int[maxSize];
    for(int i=0;i<maxSize;i++){ temp[i] = 0; }
    int minSize = min(this->currCapacity, anotherDec.currCapacity);

    ///just add each digit on one number to the corresponding one on the other number
    for(int i=0;i<minSize;i++)
    {
        temp[i] = this->number[i] + anotherDec.number[i];
    }

    ///handle if a the numbers don't have the same size
    if(this->currCapacity > anotherDec.currCapacity)
    {
        for(int i=minSize;i<this->currCapacity;i++)
        {
            temp[i] = this->number[i];
        }
    }

    if(anotherDec.currCapacity > this->currCapacity)
    {
        for(int i=minSize;i<anotherDec.currCapacity;i++)
        {
            temp[i] = anotherDec.number[i];
        }
    }

    ///handle overflow case
    for(int i=0;i<maxSize-1;i++)
    {
        if(temp[i] >= 10)
        {
            ///overflow catched
            temp[i] -= 10;
            temp[i+1] += 1;
        }
    }

    ///now save the result in a string to call the constructor of BigInt using ascii table to convert from int to char
    string decStr = "";
    for(int i=maxSize-1;i>-1;i--)
    {
        decStr += temp[i] + '0';
    }

    ///initialize the new number
    BigDecimalInt toReturn(decStr);

    ///determine its sign
    if(this->sign == 0 && anotherDec.sign == 0) { toReturn.sign = 0; }

    ///free up the space for the temp array then return the result
    delete[] temp;
    return toReturn;
}

BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec)
{
    ///we are  here depend on that the number one right must be greater then the left one
    ///to get the sign of the new BigInt and if it is not the case then swap them and we flip the sign of the result
    bool newSign;
    BigDecimalInt tempBig = anotherDec;

    ///if both number positives then the result will be positive too
    ///if the are differ in the sign then it's a addition problem so call the addition method and let it do its work
    ///otherwise the sign will be negative
    if(this->sign == 1 && anotherDec.sign == 1){
        newSign = 1;
    }else if(this->sign == 1 && anotherDec.sign == 0){
        tempBig.sign = 1;
        return *this+tempBig;
    }else if(this->sign == 0 && anotherDec.sign == 1){
        tempBig.sign = 0;
        return *this+tempBig;
    }else{
        newSign = 0;
        tempBig.sign = 1;
    }

    BigDecimalInt test1 = *this, test2 = anotherDec;
    test1.sign = 1, test2.sign = 1;
    bool ans = test1 > test2;

    ///swap if the second greater than the first number
    ///we do that to handle the borrow case
    if(!ans)
    {
        BigDecimalInt tempPtr = anotherDec;
        anotherDec = *this;
        *this = tempPtr;
        newSign = (newSign == 1) ? 0:1;
    }

    ///same rule as addition one except if we have n digits number and m digits number
    ///the result will have a length not less than min(n, m)
    int maxSize = max(this->currCapacity, anotherDec.currCapacity), minSize = min(this->currCapacity, anotherDec.currCapacity);

    ///our temp to do the work like in addition case
    int* temp = new int[maxSize];
    for(int i=0;i<maxSize;i++)
    {
        temp[i] = 0;
    }

    ///initialize the cpy array to do the borrow method on it
    ///and to not change the current number
    int* cpy = new int[this->currCapacity];

    for(int i=0;i<this->currCapacity;i++)
    {
        cpy[i] = this->number[i];
    }

    /// if thisDec > anotherDec just do the borrow method
    for(int i=0;i<minSize;i++)
    {
        if(cpy[i] >= anotherDec.number[i])
        {
            temp[i] = cpy[i] - anotherDec.number[i];
        }
        else
        {
            int j = i+1;

            ///borrow from the first digit that is not Zero
            while(cpy[j] == 0)
            {
                j++;
            }

            ///apply the borrow logic
            while(j > i)
            {
                cpy[j]--;
                cpy[j-1] += 10;
                j--;
            }

            ///just subtract the number from the second one
            temp[i] = cpy[i] - anotherDec.number[i];
        }
    }

    ///handle if there are not same size(length)
    if(this->currCapacity > minSize)
    {
        for(int i=minSize;i<this->currCapacity;i++)
        {
            temp[i] = cpy[i];
        }
    }

    if(anotherDec.currCapacity > minSize)
    {
        for(int i=minSize;i<anotherDec.currCapacity;i++)
        {
            temp[i] = anotherDec.number[i];
        }
    }

    ///if we swap them at first after doing the calculations we must swap them again
    if(!ans)
    {
        BigDecimalInt tempPtr = anotherDec;
        anotherDec = *this;
        *this = tempPtr;
    }

    ///get the number in string to call the constructor
    string decStr = "";
    for(int i=maxSize-1;i>-1;i--)
    {
        decStr += temp[i] + '0';
    }

    BigDecimalInt toReturn(decStr);
    toReturn.sign = newSign;

    ///free the reserved space then return the result
    delete[] cpy;
    delete[] temp;

    return toReturn;
}

///overload the assignment operator to avoid shallow copy scenario
BigDecimalInt& BigDecimalInt::operator=(BigDecimalInt anotherDec)
{
    delete[] this->number;
    this->currCapacity = anotherDec.currCapacity;
    this->number = new int[this->currCapacity];

    ///copying the number
    for(int i=0;i<this->currCapacity;i++)
    {
        this->number[i] = anotherDec.number[i];
    }

    this->sign = anotherDec.sign;
    return *this;
}


///return the length of the number
int BigDecimalInt::size(){ return this->currCapacity; }

///overloading ostream
ostream& operator<<(ostream& out, const BigDecimalInt& b)
{
    ///handle the case if the array if all Zeros like 00000000000000000
    bool zeroArr = 1;
    for(int i=0;i<b.currCapacity;i++)
    {
        if(b.number[i] != 0)
        {
            zeroArr = 0;
            break;
        }
    }

    if(zeroArr){ out<<0; return out; }
    if(b.sign == 0){ out<<'-'; }
    int start = b.currCapacity-1;

    ///handle the case of -       44444444 or +     44444444
    while(b.number[start] == 0)
    {
        start--;
    }

    for(int i=start;i>-1;i--)
    {
        out<<b.number[i];
    }

    return out;
}

