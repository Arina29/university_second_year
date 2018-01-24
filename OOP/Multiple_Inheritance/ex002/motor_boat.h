#ifndef MOTOR_BOAT_H_
#define MOTOR_BOAT_H_

#include <iostream>

using namespace std;

class Motor_boat : virtual public Transport
{
	int tank_gasoline;

public:
	Motor_boat();
	Motor_boat(int);
	Motor_boat(Motor_boat& other);

	virtual istream& read(istream&);
	virtual ostream& print(ostream&);

	void change_tank_gasoline(int);
};

#endif