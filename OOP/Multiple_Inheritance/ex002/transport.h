#ifndef TRANSPORT_H_
#define TRANSPORT_H_

#include <iostream>

using namespace std;

class Transport
{
protected:
	int velocity;

public:
	Transport();
	Transport(int);
	Transport(Transport& other);

	istream& read(istream& in);
	ostream& print(ostream& out);

	void change_velocity(int);

	friend istream& operator >> (istream&, Transport&);
	friend ostream& operator << (ostream&, Transport&); 

};

#endif