#include <iostream>
#include "transport.h"
#include "motorcycle.h"
#include "motor_boat.h"
#include "water_motorcycle.h"

using namespace std;

//-------------------------------Transport class----------------------------

Transport::Transport() : velocity(0)
{	}

Transport::Transport(int _velocity) : velocity(_velocity)
{	}

Transport::Transport(Transport& other) : velocity(other.velocity)
{	}

istream& Transport::read(istream& in)
{
	cout << "Enter velocity value: " << endl;
	in >> velocity;
	return(in);
}

ostream& Transport::print(ostream& out)
{
	out << "Transport velocity: " << velocity << endl;
	return (out);
}


void Transport::change_velocity(int new_velocity)
{
	velocity = new_velocity;
}

//-----------------------------Motorcycle class-------------------------------

Motorcycle::Motorcycle() : Transport(), model_year(0)
{	}

Motorcycle::Motorcycle(int year) : Transport(), model_year(year)
{	}

Motorcycle::Motorcycle(Motorcycle& other) :Transport(), model_year (other.model_year)
{	}

istream& Motorcycle::read(istream& in)
{
	cout << "Enter the motorcycle model year: " << endl;
	in >> model_year;
	return(in);
}

ostream& Motorcycle::print(ostream& out)
{
	out << "Model year: " << model_year << endl;
}

void Motorcycle::change_model_year(int new_year)
{
	model_year = new_year;
}

//-------------------------------------Motor_boat class-------------------------------------------

Motor_boat::Motor_boat() : Transport(), tank_gasoline(0)
{	}

Motor_boat::Motor_boat(int tank) : Transport(), tank_gasoline(tank)
{	}

Motor_boat::Motor_boat(Motor_boat& other) : Transport(), tank_gasoline(other.tank_gasoline)
{	}

istream& Motor_boat::read(istream& in)
{
	cout << "Enter tank gasoline:" << endl;
	in >> tank_gasoline;
	return(in);
}

ostream& Motor_boat::print(ostream& out)
{
	out << "Tank_gasoline: " << tank_gasoline << endl;
	return(out);
}

void Motor_boat::change_tank_gasoline(int new_tank_gasoline)
{
	tank_gasoline = new_tank_gasoline;
}

//-------------------------------------Water motorcycle-----------------------------------------


Water_motorcycle::Water_motorcycle() : Motorcycle(), Motor_boat(), price(0.0)
{	}

Water_motorcycle::Water_motorcycle(float _price) : Motorcycle(), Motor_boat(), price(_price)
{	}

Water_motorcycle::Water_motorcycle(int modelYear, int gasoline, float _price) : Motorcycle(modelYear), Motor_boat(gasoline), price(_price)
{	}

void Water_motorcycle::change_price(float _price)
{
	price = _price;
}

istream& operator >> (istream& in, Water_motorcycle& obj)
{
	obj.Transport::read(in);
	obj.Motorcycle::read(in);
	obj.Motor_boat::read(in);
	cout  << "Enter the water_motorcycle price: "  << endl;
	in >> obj.price;
	return(in);
}

ostream& operator << (ostream& out, Water_motorcycle& obj)
{
	obj.Transport::print(out);
	obj.Motorcycle::print(out);
	obj.Motor_boat::print(out);
	out << "Water motorcycle price: " << obj.price << endl;
}