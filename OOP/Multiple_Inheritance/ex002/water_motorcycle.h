#ifndef WATER_MOTORCYCLE_H_
#define WATER_MOTORCYCLE_H_

#include <iostream>

using namespace std;

class Water_motorcycle : public Motorcycle, public Motor_boat
{
	float price;

public:
	Water_motorcycle();
	Water_motorcycle(float);
	Water_motorcycle(int, int, float);

	void change_price(float);
	void change();

	friend istream& operator >> (istream& in, Water_motorcycle& obj);
	friend ostream& operator << (ostream& out, Water_motorcycle& obj);
};

#endif