#include <bits/stdc++.h>
#include "BigDecimalInt.h"
using namespace std;

int main()
{
    ///TEST CASES
    cout<<"=======  TEST CASES  =========\n";
    BigDecimalInt x = 45628, y = 8785355;
    cout<<"x = "<<x<<" and y = "<<y<<endl;
    cout<<"x + y = ";
    cout<<x+y<<endl;
    cout<<"x - y = ";
    cout<<x-y<<endl;
    x = -4857, y = 4857;
    cout<<"x = "<<x<<" and y = "<<y<<endl;
    cout<<"x + y = ";
    cout<<x+y<<endl;
    cout<<"x - y = ";
    cout<<x-y<<endl;
    x = -8000, y = 1;
    cout<<"x = "<<x<<" and y = "<<y<<endl;
    cout<<"x + y = ";
    cout<<x+y<<endl;
    cout<<"x - y = ";
    cout<<x-y<<endl;
    x = 20, y = 5;
    cout<<"x = "<<x<<" and y = "<<y<<endl;
    cout<<"x + y = ";
    cout<<x+y<<endl;
    cout<<"x - y = ";
    cout<<x-y<<endl;
    x = -20, y = (string)"456789456789565656444466446";
    cout<<"x = "<<x<<" and y = "<<y<<endl;
    cout<<"x + y = ";
    cout<<x+y<<endl;
    cout<<"x - y = ";
    cout<<x-y<<endl;
    x = (string)"123456789123456789123456789", y = (string)"789456145678945612345677891423456789";
    cout<<"x = "<<x<<" and y = "<<y<<endl;
    cout<<"x + y = ";
    cout<<x+y<<endl;
    cout<<"x - y = ";
    cout<<x-y<<endl;
    cout<<"===============================\n\n";

    ///current state of the program
    bool state = 1;
    while(state)
    {
        cout<<"Welcome to FCI Calculator\n";
        cout<<"-------------------------\n";
        cout<<"1 - Perform Addition\n";
        cout<<"2 - Perform Subtraction\n";
        cout<<"3 - Exit\n";
        cout<<">>";
        int choice;cin>>choice;
        string a, b;
        switch(choice)
        {
            case 1:
            case 2:
            {
                cin.ignore();
                cout<<">>";
                getline(cin, a);
                BigDecimalInt first(a);
                cout<<"num1 = "<<first<<endl<<">>";
                getline(cin, b);
                BigDecimalInt second(b);
                cout<<"num2 = "<<second<<endl;
                BigDecimalInt result = (choice == 1) ? first+second:first-second;
                cout<<"num1 "<<((choice == 1) ? '+':'-')<<" num2 = "<<result<<endl;
                break;
            }
            case 3:
                state = 0;
                break;
        }

    }

    return 0;
}
