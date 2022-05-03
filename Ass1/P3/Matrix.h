#ifndef UNTITLED12_MATRIX_H
#define UNTITLED12_MATRIX_H

#include <iostream>

using namespace std;

template<class T>
class Matrix {
private:
    T **arr;
    int rows;
    int col;
public:
    //constructors
    Matrix();
    Matrix(int,int);
    Matrix(int , int, T data[]);
    Matrix(const Matrix<T> &);

    //function that fill specific place in matrix
    void fill(int , int , T );

    //input and output stream
    template<class T2>
    friend ostream &operator<<(ostream &, const Matrix<T2> &);
    template<class T2>
    friend istream &operator>>(istream &, Matrix<T2> &);
    //Arithmetic operations between the matrix
    Matrix<T> operator+(Matrix<T> &);
    Matrix<T> operator-(Matrix<T> &);
    Matrix<T> operator*(Matrix<T> &);

    //Function to transpose the matrix
    template<class T2>
    friend Matrix<T2> &transpose(Matrix<T2> &);
    //get number of rows
    int GetRows() const;
    //get number of columns
    int GetCol() const;

    //Destructor
    ~Matrix();

};

template<class T> //Default Constructor that set rows and columns equal zero
Matrix<T>::Matrix() {
    rows = 0;
    col = 0;
    arr = nullptr;
}

template<class T>//Parametrize constructor that take the number of rows and columns
Matrix<T>::Matrix(int r, int c) {
    rows = r;
    col = c;
    arr = new T *[rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new T[col];
}

template<class T> //Parametrize constructor that take rows and columns and matrix
Matrix<T>::Matrix(int r, int c, T data[]) {
    rows = r;
    col = c;
    arr = new T[r];
    for (int i = 0; i < r; ++i) {
        arr[i] = new T[c];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < col; ++j) {
            arr[i][j] = data[i * col + j];
        }
    }
}

template<class T> //function that fill specific place in matrix
void Matrix<T>::fill(int r, int c, T val) {
    if (r < rows && r >= 0 && c < col && c >= 0)
        arr[r][c] = val;
    else
        cout << "index Error\n";
}

template<class T> //copy constructor
Matrix<T>::Matrix(const Matrix<T> &old) {
    this->col = old.col;
    this->rows = old.rows;
    this->arr = new T *[rows];

    for (int i = 0; i < rows; i++)
        this->arr[i] = new T[col];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < col; j++)
            this->arr[i][j] = old.arr[i][j];
}


template<class T> //Destructor to destruct the 2D array
Matrix<T>::~Matrix() {
    for (int i = 0; i < rows; ++i) {
          delete[] arr[i];
      }
      delete[] arr;

}

template<class T2>  //output operator
ostream &operator<<(ostream &out, const Matrix<T2> &mat) {

    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.col; ++j) {
            out << mat.arr[i][j] << ' ';
        }
        out << '\n';
    }
    return out;
}

template<class T2> //input operator
istream &operator>>(istream &in, Matrix<T2> &mat) {

    cout << "Enter rows and columns\n";
    cin >> mat.rows >> mat.col;
    mat.arr = new T2 *[mat.rows];

    for (int i = 0; i < mat.rows; ++i) {
        mat.arr[i] = new T2[mat.col];
    }
    cout << "Enter Data\n";

    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.col; ++j) {
            in >> mat.arr[i][j];
        }
    }
    return in;
}


template<class T> //Addition operator between two matrix
Matrix<T> Matrix<T>::operator+(Matrix<T> &mat) {

    Matrix<T> matrix(rows, col);
    //make all matrix equal zero
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            matrix.arr[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < col; j++) {
            matrix.arr[i][j] = arr[i][j] + mat.arr[i][j];
        }
    }

    return matrix;
}

template<class T> //subtraction operator between two matrix
Matrix<T> Matrix<T>::operator-(Matrix<T> &mat) {
    Matrix<T> matrix(mat.rows, mat.col);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix.arr[i][j] = arr[i][j] - mat.arr[i][j];
        }
    }

    return matrix;
}

template<class T> //Multiplication operator between two matrix
Matrix<T> Matrix<T>::operator*(Matrix<T> &mat) {
    Matrix<T> matrix(rows, mat.col);
    //make all matrix equal zero
    for (int i = 0; i <rows ; ++i) {
        for (int j = 0; j <mat.rows ; ++j) {
            matrix.arr[i][j]=0;
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < mat.col; ++j) {
            for (int k = 0; k < col; ++k) {
                matrix.arr[i][j] += arr[i][k] * mat.arr[k][j];
            }
        }
    }
    return matrix;
}

template<class T> //Get number of rows
int Matrix<T>::GetRows() const {
    return rows;
}

template<class T> //Get number of columns
int Matrix<T>::GetCol() const {
    return col;
}



template<class T2>  //function that transpose the matrix
Matrix<T2> &transpose(Matrix<T2> &mat) {
    Matrix<T2> matrix( mat.col,mat.rows);
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.col; ++j) {
            matrix.arr[i][j] = mat.arr[j][i];
        }
    }
    for (int i = 0; i < mat.rows; ++i) {
        for (int j = 0; j < mat.col; ++j) {
            mat.arr[i][j] = matrix.arr[i][j];
        }
    }
    return mat;

}


#endif //UNTITLED12_MATRIX_H
