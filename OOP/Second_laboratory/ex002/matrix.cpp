#include <iostream>
#include <assert.h>
#include "matrix.h"

using namespace std;

Matrix::Matrix(): columns(1), rows(1), errorMessage("ERROR in Matrix Creation")
{  
    matrix = new int*[rows];
    for(int i = 0; i < rows; i++)
        matrix[i] = new int [columns];
 }

Matrix::Matrix(int _rows) : columns(_rows), errorMessage("ERROR in Matrix Creation")
{
    rows = _rows;
    matrix = new int*[rows];
    for (int i = 0; i < _rows; i++)
           matrix[i] = new int [columns];
}

Matrix::Matrix(int _rows, int _columns) : errorMessage("ERROR in Matrix Creation")
{
    rows = _rows;
    columns = _columns;

    matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
            matrix[i] = new int [columns];
}

void Matrix::SetValue(int row_index, int column_index, int value)
{
    matrix[row_index][column_index] = value;
}

int Matrix::GetValue(int row_index, int column_index) const
{
    int temp = matrix[row_index][column_index];
    return temp;
}


Matrix Matrix::operator + (const Matrix &mat)
{
    int nr_rows = rows;
    int nr_columns = columns;

    assert(nr_rows == mat.rows);
    assert(nr_columns == mat.columns);

    Matrix temp(rows, columns);
    for(int i = 0; i < nr_rows; i++)
    {
        for(int j = 0; j < nr_columns; j++)
        {
            temp.matrix[i][j] = matrix[i][j] + mat.matrix[i][j];
        }
    }
    return temp;
}

Matrix& Matrix::operator = (const Matrix &mat)
{  
    assert(columns == mat.columns);
    assert(rows == mat.rows);

    for(int i = 0; i < rows; i++)
    {
      for(int j = 0; j < columns; j++)
          matrix[i][j] = mat.matrix[i][j];
    }
    return *this;
}

Matrix Matrix::operator - (const Matrix &mat)
{
    int nr_rows = rows;
    int nr_columns = columns;

    assert(nr_rows == mat.rows);
    assert(nr_columns == mat.columns);

    Matrix temp(rows, columns);
    for(int i = 0; i < nr_rows; i++)
    {
        for(int j = 0; j < nr_columns; j++)
            temp.matrix[i][j] = matrix[i][j] - mat.matrix[i][j];
    }
    return temp;
}

Matrix Matrix::operator * (const Matrix &mat)
{
    int nr_rows = rows;
    int nr_columns = columns;
    
    assert(columns == mat.rows);

    Matrix temp(rows, mat.columns);

    for(int i = 0; i < nr_rows; i++)
    {
        for(int j = 0; j < mat.columns; j++)
        {
        int sum = 0;
            for(int k = 0; k < nr_columns; k ++)
            {
                sum = sum + matrix[i][k] * mat.matrix[k][j];
            }
        temp.matrix[i][j] = sum;
        }
    }
    return temp;
}

Matrix Matrix:: operator * (const int &nr)
{
    Matrix temp(rows, columns);
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
            temp.matrix[i][j] = matrix[i][j] * nr;
    }
    return temp;
}

void Matrix::displayMatrix()
{
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            cout << matrix[i][j] << "    ";
        }
        cout <<"\n";
    }
}

Matrix::~Matrix()
{
    for(int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
    columns = 0;
    rows = 0;
}