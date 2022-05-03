#include "FractionCalculator.h"
void screen() {

    Fraction obj1, obj2;
    int choice = 0;
    cout << "Welcome to FCI Fraction Calculator\n----------------------------------------\n";

    bool flag = false;
    while (true) {

        cout << "1- Perform Fraction Addition\n"
                "2 - Perform Fraction Subtraction\n"
                "3 - Perform Fraction Multiplication\n"
                "4 - Perform Fraction Division\n"
                "5 - Exit\n";
        cin >> choice;
        //Enter two numbers one time
        if (!flag && choice != 5) {
            cout << "Enter Two Fractions\n";
            cin >> obj1 >> obj2;
        }
        //when the flag will be true the user can input one fraction to continue operations on the result
        if (flag && choice != 5) {
            cout << "Enter the Fraction\n";
            cin >> obj1;
        }
        if (choice == 1) {
            obj2 = obj1 + obj2;
        } else if (choice == 2) {
            obj2 = obj2 - obj1;
        } else if (choice == 3) {
            obj2 = obj1 * obj2;
        } else if (choice == 4) {
            obj2 = obj2 / obj1;
        } else
            exit(0);

        cout << "Ans:" << obj2 << "\n";
        //make flag true to input one fraction to continue operations on the result
        flag = true;
    }
}
