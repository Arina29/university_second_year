#ifndef MOTORCYCLE_H_
#define MOTORCYCLE_H_

#include <iostream>

using namespace std;

class motorcycle
{
protected:
	int model_year;

public:
	motorcycle();
	motorcycle(int);

	virtual ostream& print(ostream& out);
	virtual istream& read(istream& in);

	friend istream& operator >> (istream&, motorcycle&);
	friend ostream& operator << (ostream&, motorcycle&);
};


#endif