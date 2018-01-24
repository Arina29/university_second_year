#include <iostream>
#include <assert.h>
#include <cmath>
#include <stdio.h>
#include "vector.h"

using namespace std;

Vector::Vector() : number_of_elements(VECTOR_INIT_CAPACITY)
{
    vectorValues = new long [number_of_elements];
    for(int i = 0; i < number_of_elements; i++)
        vectorValues[i] = 0;
}

Vector::Vector(int nr_values) : number_of_elements(nr_values)
{
    vectorValues = new long [number_of_elements];
    for(int i = 0; i < number_of_elements; i++)
        vectorValues[i] = 0;
}

Vector::Vector(Vector &other)
{

    number_of_elements = other.number_of_elements;
    for(int i = 0; i < number_of_elements; i++)
        vectorValues[i] = other.vectorValues[i];
}

Vector Vector::operator + (const Vector& other)
{
    assert(number_of_elements == other.number_of_elements);

    Vector temp(number_of_elements);
    for(int i = 0; i < number_of_elements; i++)
    {
        temp.vectorValues[i] = vectorValues[i] + other.vectorValues[i];
    }
    return temp;
}

Vector Vector::operator - (const Vector& other)
{
    assert(number_of_elements == other.number_of_elements);

    Vector temp(number_of_elements);
    for(int i = 0; i < number_of_elements; i++)
    {
        temp.vectorValues[i] = vectorValues[i] - other.vectorValues[i];
    }
    return temp;
}

Vector& Vector::operator = (const Vector& other)
{   
    if(this == &other)
        return *this;
    if(vectorValues)
    {
        delete[] vectorValues;
    }

    vectorValue = new long(other.number_of_elements);

    for(int i = 0; i < other.number_of_elements; i++)
        vectorValues[i] = other.vectorValues[i];
    
    number_of_elements = other.number_of_elements;
}

ostream& operator << (ostream &out, Vector &self)
{

    for (int i = 0; i < self.number_of_elements; i++)
    {
        out << self.vectorValues[i] << "; ";
    }
    return out;
}

istream& operator >> (istream &in, Vector &self)
{
    for(int i = 0; i < self.number_of_elements; i++)
    {
        cout << "Enter value: ";
        in >> self.vectorValues[i];
    }
    return in;
}

bool operator == (const Vector &first, const Vector &second)
{
    assert(first.number_of_elements == second.number_of_elements);

    for(int i = 0; i < first.number_of_elements; i++)
    {
       if(first.vectorValues[i] != second.vectorValues[i])
        return false;
    }

    return true;
}

bool operator != (const Vector& first, const Vector &second)
{
    assert(first.number_of_elements == second.number_of_elements);

    for(int i = 0; i < first.number_of_elements; i++)
    {
       if(first.vectorValues[i] != second.vectorValues[i])
        return true;
    }

    return false;
}


int vector_module(const Vector& self)
{
    int sum = 0;

    for(int i = 0; i < self.number_of_elements; i++)
    {
        sum += pow(self.vectorValues[i], 2);
    }
    return sqrt(sum);
}

bool operator < (const Vector& first, const Vector &second)
{
    int vec1 = vector_module(first);
    int vec2 = vector_module(second);
    return (vec1 < vec2);
}

bool operator > (const Vector& first, const Vector &second)
{
    int vec1 = vector_module(first);
    int vec2 = vector_module(second);
    return (vec1 > vec2);
}





