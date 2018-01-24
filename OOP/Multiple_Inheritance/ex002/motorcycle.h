#ifndef MOTORCYCLE_H_
#define MOTORCYCLE_H_

#include <iostream>

using namespace std;

class Motorcycle : virtual public Transport
{
protected:
	int model_year;

public:
	Motorcycle();
	Motorcycle(int);
	Motorcycle(Motorcycle&);

	virtual istream& read(istream&);
	virtual ostream& print(ostream&);

	void change_model_year(int);

	friend istream& operator >> (istream&, Motorcycle&);
	friend ostream& operator << (ostream&, Motorcycle&); 
};

#endif