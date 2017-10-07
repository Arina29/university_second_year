#ifndef MATRIX_H
#define MATRIX_H

#include <string>

class Matrix
{
private:
    int ** matrix;
    int columns;
    int rows;
    std::string errorMessage;

public:
    Matrix();
    Matrix (int);
    Matrix (int, int);
    void SetValue(int, int, int);
    int GetValue(int, int) const;
    Matrix& operator = (const Matrix&);
    Matrix operator + (const  Matrix&);
    Matrix operator - (const Matrix&);
    Matrix operator * (const Matrix&);
    Matrix operator * (const int&);
    void displayMatrix();
    ~Matrix();

};

#endif 
