#include <bits/stdc++.h>
using namespace std;

template<class T>
class uniqueArr
{
    ///innerArr hold the dynamic array
    T* innerArr;
    ///nextFreeSpace is the next unused index in the array
    ///innerSize is the total size of the dynamic array
    int nextFreeSpace = 0, innerSize = 0;

public:

    ///parametrized constructor to initiate the size of the array
    uniqueArr(int sz){
        innerSize = sz;
        innerArr = new T[innerSize];
    }

    ///default constructor with default value 10
    uniqueArr(){
        innerSize = 10;
        innerArr = new T[innerSize];
    }

    ///this add method to deal with adding new items into the array without caring about anything
    void add(T item){
        ///return if the element already exist and do nothing
        for(int i=0;i<nextFreeSpace;i++){
            if(innerArr[i] == item){
                return;
            }
        }
        ///I used all the space of the array and I need to reallocate a new one and double its size
        if(nextFreeSpace >= innerSize){
            ///reallocate the new array and copy the items to it
            T* newInnerArr = new T[2*innerSize];
            for(int i=0;i<nextFreeSpace;i++){
                newInnerArr[i] = innerArr[i];
            }
            ///delete the old one with the small size
            delete[] innerArr;
            ///assign the new size
            innerSize *= 2;
            ///point to the new array with out pointer to not lose its reference
            innerArr = newInnerArr;
        }
        ///add the new item in the next free index on the array
        innerArr[nextFreeSpace++] = item;
    }

    ///safe function to deal with indexes with our array
    T get(int ind){
        try{
            ///ind must be exist and non negative
            if(ind < nextFreeSpace && ind >= 0){
                return innerArr[ind];
            }
            ///else throw exception to show what's wrong
            throw "Invalid Index";
        }catch(const char* msg){
            cout<<msg<<endl;
        }
        return nullptr;
    }

    ///return the length of the items in the array
    int length(){
        return nextFreeSpace;
    }

    ///return the actual capacity of the array = length + free space to add new items
    int capacity(){
        return innerSize;
    }

    ///free the occupied memory once calling the destructor
    ~uniqueArr(){
        delete[] innerArr;
    }

};

uniqueArr<string> uniquePerms;
void RecPermute(string soFar,string rest){
    if (rest == ""){
        uniquePerms.add(soFar);
    }else{
        for(int i=0;i<(int)rest.length();i++){
            string next = soFar + rest[i];
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }
    }
}

void ListPermutations(string s){
    RecPermute("",s);
}

int main()
{
    string input;
    cout<<"Input  : ";
    cin>>input;
    cout<<"Output : \n";
    ListPermutations(input);

    for(int i=0;i<uniquePerms.length();i++){
        cout<<">>"<<uniquePerms.get(i)<<endl;
    }

    return 0;
}
