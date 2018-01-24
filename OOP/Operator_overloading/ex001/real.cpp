#include <iostream>
#include "real.h"

using namespace std;

Real::Real():nr(0.0)
{   }

Real::Real(double _nr) : nr(_nr)
{   }

Real Real::operator + (const Real& other)
{
    return(Real(nr + other.nr));
}

Real Real::operator + (double _nr)
{
    return Real(_nr + nr);
}

Real& Real::operator ++ ()
{
    nr++;
    return *this;
}

Real Real::operator ++ (int)
{
    return Real(++ nr);
}

Real operator - (const Real& first, const Real& sec)
{
    return Real(first.nr - sec.nr);
}

Real operator - (const Real& self, double _nr)
{
    return Real(self.nr - _nr);
}

Real operator - (double _nr, const Real& self)
{
    return Real(_nr - self.nr);
}

 Real& operator -- (Real& self)
 {
     -- self.nr;
     return self;
 }

 Real operator -- (Real& self, int)
 {
     return Real(self.nr--);
 }

 ostream& operator << (ostream &out, const Real self)
 {
     out << self.nr;
     return out;
 }
