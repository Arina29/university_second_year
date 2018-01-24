#ifndef _REAL_H_
#define _REAL_H_

#include <iostream>

using namespace std;

class Real
{
  double nr;

public:
    Real();
    Real(double);

    Real operator + (const Real&);
    Real operator + (double);
    Real& operator ++ ();
    Real operator ++ (int);


    friend Real operator -(const Real&, const Real&);
    friend Real operator - (const Real&, double);
    friend Real operator - (double, const Real&);
    friend Real& operator --(Real&);
    friend Real operator -- (Real&, int);
    friend ostream& operator << (ostream &out, const Real self);
};

#endif
