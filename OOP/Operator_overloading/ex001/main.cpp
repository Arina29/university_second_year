#include <iostream>
#include "real.h"

using namespace std;

int main()
{
    Real nr1(2);
    Real nr2(3);
    Real nr3;
   
    cout <<"1 - Adding two objects;" << endl;
    cout << "First object:" << nr1 << endl;
    cout << "Second object:" << nr2 << endl;
    cout <<"Result: " << nr1 + nr2 << endl ;
    cout <<"--------------------------------------" << endl;

    cout <<"2 - Adding an object with a double;" << endl;
    cout << "First object:" << nr2 << endl;
    cout << "Result after adding 5.0: " << nr2 + 5.0 << endl;
    cout <<"--------------------------------------" << endl;

    cout <<"3 - Prefix increment;" << endl;
    cout << "Object value:" << nr1 << endl;
    cout << "value ater prefix incrementing: " << ++ nr1 << endl;
    cout <<"--------------------------------------" << endl;
    
    cout <<"4 - Postfix increment;" << endl;
    cout << "Object value:" << nr1 << endl;
    cout << "value ater postfix incrementing: " << nr1++ << endl;
    cout <<"--------------------------------------" << endl;

    cout <<"4 - Postfix decrement;" << endl;
    cout << "Object value:" << nr1 << endl;
    cout << "value ater postfix decrementing: " << nr1-- << endl;
    cout << "Value of nr1: " <<nr1  << endl;
    cout <<"--------------------------------------" << endl;

    return 0;
}
