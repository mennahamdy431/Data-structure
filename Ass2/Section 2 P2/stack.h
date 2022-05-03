
#ifndef UNTITLED12_STACK_H
#define UNTITLED12_STACK_H
#include "LinkedList.h"
template <class T>
class stack: private List<T>{
public:
    stack():List<T>(){}

    stack(T value, int intial_size):List<T>(value,intial_size){}

    T& top(){
        if (this->size()==0)
        {
            cout<<"The stack is empty\n";
            exit(1);
        }
        return this->head->iteam;
    }

    void pop(){
        this->deleteFirst();
    }

    void push(T value){
        this->InsertFirst(value);
    }

    int size()const{ return this->length;}

    ~stack(){

    }
};

#endif //UNTITLED12_STACK_H
