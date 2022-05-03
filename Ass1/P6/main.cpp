#include <iostream>
#include "StudentName.h"

using namespace std;

int main() {

    cout << "Test cases\n";
    StudentName stud1("Ahmed Khalil Mostafa Fathy");

    if (stud1.replace(4, 2)) {
        cout<<"True\n";
        stud1.print();
    } else {
        cout<<"False\n";
        stud1.print();
    }
    StudentName stud2("Ahmed mohamed mansour");
    if (stud2.replace(4, 1)) {
        cout<<"True\n";
        stud2.print();
    } else {
        cout<<"False\n";
        stud2.print();
    }

    StudentName stud3("mohamed khalid");
    if (stud3.replace(2, 1)) {
        cout<<"True\n";
        stud3.print();
    } else {

        cout<<"False\n";
        stud3.print();
    }

    StudentName stud4("Tarek");
    if (stud4.replace(1, 2)) {
        cout<<"True\n";
        stud4.print();
    } else {

        cout<<"False\n";
        stud4.print();
    }

    StudentName stud5("Osama");
    if (stud5.replace(1, 4)) {
        cout<<"True\n";
        stud5.print();
    } else {
        cout<<"False\n";
        stud5.print();
    }

    string name;
    int i, j, choice = 1;
    //User Test
    while (choice == 1) {
        cout << "===========================================\n";
        cout << "Input:\n";
        getline(cin, name);
        StudentName stud(name);
        cin >> i >> j;
        if (stud.replace(i, j)) {
            cout << "True\n";
            stud.print();

        } else {
            cout << "False\n";
            stud.print();

        }

        cout << "DO you want to continue\n"
             << "Press 1 if Yes or any number for No\n";
        cin >> choice;
        cin.ignore();

    }

    return 0;
}