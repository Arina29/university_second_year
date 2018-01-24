#include <iostream>
#include "liquid.cpp"

using namespace std;

alcohol::alcohol():liquid()
{	}

alcohol::alcohol(char* newName) : liquid(newName), ABV(0)
{	}

alcohol::alcohol(float new_density) : liquid (new_density), ABV(0)
{	}

alcohol::alcohol(char* _Name, float _density, float newABV) : liquid(_Name, _density)
{
	ABV = newABV;
}
/*
ostream& operator << (ostream &out, const alcohol &obj)
{

	out << static_cast<const liquid&>(obj);
	out << obj.ABV << endl;

	return out;
}
*/
