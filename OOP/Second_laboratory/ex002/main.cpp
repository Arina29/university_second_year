#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    Matrix mat1(2, 3);
    Matrix mat2 (3, 4);
    Matrix multresult(2, 4), scmultresult(2, 3);
    
    int elem;

    cout << "\nMatrix 1: " << endl;
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cout<< "Element for " << i + 1 << " row and " << j + 1 <<" column:" << endl;
            cin >> elem;
            mat1.SetValue(i, j, elem);
        }
    }

    cout << "\nMatrix 2:" << endl;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            cout<< "Element for " << i + 1 << " row and " << j + 1 <<" column:" << endl;
            cin >> elem;
            mat2.SetValue(i, j, elem);
        }
    }

    cout << "\nMatrix1: "<< endl;
    mat1.displayMatrix();
    cout << "\nMatrix2: "<< endl;
    mat2.displayMatrix();  

  /*  addresult = mat1 + mat2;
    cout << "\n Addition result" << endl;
    addresult.displayMatrix();

    subresult = mat1 - mat2;
    cout << "\n Substraction result" << endl;
    subresult.displayMatrix();*/

    multresult = mat1 * mat2;
    cout << "\n Multiplication result" << endl;
    multresult.displayMatrix();


    scmultresult = mat1 * 3;
    cout << "\n Scalar multiplication result" << endl;
    scmultresult.displayMatrix();

    return 0;
}