#ifndef WATER_MOTORCYCLE_H_
#define WATER_MOTORCYCLE_H_

#include <iostream>
using namespace std;

class water_motorcycle : public boat, public motorcycle
{
	double price;

public:
	water_motorcycle();
	water_motorcycle(int);
	water_motorcycle(int, float);
	water_motorcycle(double);
	water_motorcycle(int, float, int, double);

	friend istream& operator >> (istream&, water_motorcycle&);
	friend ostream& operator << (ostream&, water_motorcycle&);
};

#endif
