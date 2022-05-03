#include "MatrixCalculator.h"

template<class T>
void MatrixCalculator<T>::Home(Matrix<T> &mat1) {

    cout << "Welcome to FCI Matrix Calculator\n";
    int choice;
    Matrix<int> mat2;
    bool flag = true;
    while (flag) {
        cout << "--------------------------------\n";
        cout << "1- Perform Matrix Addition\n"
             << "2- Perform Matrix Subtraction\n"
             << "3- Perform Matrix Multiplication\n"
             << "4- Matrix Transpose\n"
             << "5- Exit\n";
        cin >> choice;
        if (choice == 1) {
            cout << "Matrix 1\n";
            cin >> mat1;

            cout << "Matrix 2\n";

            cin >> mat2;

            if (mat1.GetRows() == mat2.GetRows() && mat1.GetCol() == mat2.GetCol()) {

                cout <<  mat1 + mat2;
            } else {
                cout << "Error...rows and columns not matched\n";
            }
        } else if (choice == 2) {
            cout << "Matrix 1\n";

            cin >> mat1;

            cout << "Matrix 2\n";
            cin >> mat2;

            if (mat1.GetRows() == mat2.GetRows() && mat1.GetCol() == mat2.GetCol()) {
                cout <<  mat1 - mat2;
            } else {
                cout << "Error...rows and columns not matched\n";
            }

        } else if (choice == 3) {
            cout << "Matrix 1\n";
            cin >> mat1;

            cout << "Matrix 2\n";
            cin >> mat2;

            if (mat1.GetCol() == mat2.GetRows()) {

                cout << mat1 * mat2;
            } else {
                cout << "Error...rows and columns not matched\n";
            }

        } else if (choice == 4) {
            cout << "Matrix\n";
            cin >> mat1;
            cout << transpose(mat1);
        } else if (choice == 5) {
            cout << "===========Thanks to visit us==========\n";
            flag = false;
        } else {
            cout << "please Enter Exist choice\n";
        }
    }
}
