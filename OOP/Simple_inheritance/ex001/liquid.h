#ifndef _LIQUID_H
#define _LIQUID_H

#include <iostream>
using namespace std;

class liquid
{
protected:
	char * name;
	float density;


public:
	liquid();
	liquid(char*);
	liquid(float);
	liquid(char*, float);
	liquid(liquid&);
	~liquid();

	virtual ostream& print(ostream& out) const;
	virtual istream& read(istream& in);

	friend istream& operator >> (istream& in, liquid& object);
	friend ostream& operator << (ostream&, liquid&);
	
};

class alcohol : public liquid
{
	int ABV;
public:
	alcohol();
	alcohol(char*);
	alcohol(float);
	alcohol(char*, float, float);

	void change_density(float);
	void change_ABV(float);

	friend istream& operator >> (istream&, alcohol&);
	friend ostream& operator << (ostream&, alcohol&);

};

//ABV means alcohol by value

#endif