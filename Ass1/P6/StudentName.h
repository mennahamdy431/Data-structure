
#ifndef UNTITLED12_STUDENTNAME_H
#define UNTITLED12_STUDENTNAME_H
#include <iostream>
using namespace std;

class StudentName {
private:
    string name;
public:
    //constructor
    StudentName(string);
    //Function that print the Details of the name
    void print();
    //get the Name
    string getName()const;

    //Function that make a replace between two names in the whole name
    bool replace(int,int);
};


#endif //UNTITLED12_STUDENTNAME_H
