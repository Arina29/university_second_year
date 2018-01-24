#ifndef _VECTOR_H
#define _VECTOR_H
#define VECTOR_INIT_CAPACITY 4

#include <iostream>

class Vector
{
    long * vectorValues;
    int number_of_elements;

    friend int vector_module(const Vector& self);
public:
    Vector();
    Vector(int);
    Vector(Vector&);
    Vector operator + (const Vector&);
    Vector operator - (const Vector&);
    Vector& operator = (const Vector&);



    friend bool operator == (const Vector& first, const Vector &second);
    friend bool operator != (const Vector& first, const Vector &second);
    friend bool operator < (const Vector& first, const Vector &second);
    friend bool operator > (const Vector& first, const Vector &second);

    friend std::ostream& operator << (std::ostream& out, Vector& self);
    friend std::istream& operator >> (std::istream& in, Vector& self);
};


#endif
