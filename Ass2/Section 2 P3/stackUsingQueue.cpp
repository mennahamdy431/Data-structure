#include <iostream>
#include "queue.h"
using namespace std;
class stack{
private:
    queue<int>q;
public:


    void push(int value){
        q.push(value);

        for (int i = 1; i <q.size() ; ++i) {
            q.push(q.Front());
            q.pop();
        }

    }

    void pop(){
        if (q.size()==0)
          return;
        q.pop();
    }
    int top(){
        if (q.size()==0)
            exit(1); //Exit because the stack is empty
        return q.Front();
    }
    int size()const{return q.size();}
};

int main() {
    stack s;
    for (int i = 0; i <5 ; ++i) {
        s.push(i+1);
    }

    for (int i = 0; i <5 ; ++i) {
        cout<<s.top()<<' ';
        s.pop();
    }


}
