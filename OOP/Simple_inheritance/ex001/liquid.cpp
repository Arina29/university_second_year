#include <iostream>
#include <cstring>
#include <string>
#include "liquid.h"

using namespace std;

//--------------------------liquid class--------------------------------

liquid::liquid() : name(new char[strlen("No_Name") + 1]), density(0.0)
{
	strcpy(name, "No_Name");
}

liquid::liquid(char * new_name) : density(0.0)
{
	name = new char[strlen(new_name) + 1];
	strcpy(name, new_name);	
}

liquid::liquid(float newDensity) : name(new char[strlen("No_Name") + 1]), density(newDensity)
{
	strcpy(name, "No_Name");
}

liquid::liquid(char * _name, float _density)
{	
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	density = _density;
}

liquid::liquid(liquid &other)
{
	name = new char[strlen(other.name)];
	strcpy(name, other.name);
	density = other.density;	
}

liquid::~liquid()
{
	if(name)
		delete[] name;
	density = 0;
}

istream& liquid::read(istream& in)
{
	if(name)
	{
		delete[] name;
	}
	char* newName = new char[100];
	cout << "Name: ";
	in >> newName;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
	delete[] newName;

	cout << "Density: ";
	in >> density;
	return (in);

}

istream & operator >> (istream &in, liquid &object)
{
	return object.read(in);
}

ostream& liquid::print(ostream& out) const
{	
	cout << "Name: ";
	out << name;
	
	out << endl;
	out << "Density: " << density << endl;
	return out;
}

ostream& operator << (ostream& out, liquid& obj)
{
	return obj.print(out);
}

//-----------------------------------alcohol class------------------------------------------

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


void alcohol::change_density(float newDensity)
{
	density = newDensity;
}

void alcohol::change_ABV(float newABV)
{
	ABV = newABV;
}

std::ostream& operator << (std::ostream& out, alcohol& obj)
{
	obj.print(out);
	out << "ABV: " << obj.ABV << endl;
	return out;
}

istream& operator >> (istream& in, alcohol& obj)
{
	obj.read(in);
	cout << "ABV: ";
	in >> obj.ABV;
	return in;
}
