
#ifndef UNTITLED12_QUEUE_H
#define UNTITLED12_QUEUE_H
#include "LinkedList.h"
template<class T>
class queue: private List<T>{
public:
    queue():List<T>(){}

    queue(T value, int intial_size):List<T>(value,intial_size){}

    void push(T data) {
        this->push_back(data);
    }

    T &Front() {
        if(this->size()==0)
        {   cout<<"The stack is empty\n";
            exit(1);
        }
        return this->head->iteam;
    }

    void pop() {
        this->deleteFirst();
    }

    int size() const {
        return this->length;
    }


    ~queue() {

    }

};


#endif //UNTITLED12_QUEUE_H
