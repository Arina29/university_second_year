#ifndef BOAT_H_
#define BOAT_H_

#include <iostream>

using namespace std;

class boat
{
protected:
	int motor_power;
	float tank_gasoline;

public:	

	boat();
	boat(int);
	boat(int, float);

	
	virtual ostream& print(ostream& out);
	virtual istream& read(istream& in);

	friend istream& operator >> (istream&, boat&);
	friend ostream& operator << (ostream&, boat&);

};

#endif