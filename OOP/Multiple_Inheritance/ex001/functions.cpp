#include <iostream>
#include "boat.h"
#include "motorcycle.h"
#include "water_motorcycle.h"

using namespace std;

//---------------------------------------boat class------------------------------------

boat::boat() : motor_power(0), tank_gasoline(0.0)
{	}

boat::boat(int power) : motor_power(power), tank_gasoline(0.0)
{	}

boat::boat(int power, float gasoline) : motor_power(power), tank_gasoline(gasoline)
{	}



ostream& boat::print(ostream &out)
{
	out << "Tank gasoline: ";
	out << tank_gasoline <<endl;

	out << "Motor power: ";
	out << motor_power << endl;

	return out;
}

istream& boat::read(istream &in)
{
	cout << "Enter tank_gasoline: " << endl;
	in >> tank_gasoline;

	cout << "Enter motor_power: " << endl;
	in >> motor_power;
	return(in);	
}

istream& operator >> (istream& in , boat& obj)
{
	return obj.read(in);
}

ostream& operator << (ostream& out, boat& obj)
{
	return obj.print(out);
}

//-------------------------------------motorcycle class--------------------------------

	motorcycle::motorcycle() : model_year(0)
	{	}

	motorcycle::motorcycle(int year) : model_year(year)
	{	}


	ostream& motorcycle::print(ostream& out)
	{
		out << "Model year: ";
		out << model_year << endl;
		return(out);
	}

	istream& motorcycle::read(istream& in)
	{
		cout << "Enter the model year: " << endl;
		in >> model_year;
		return(in);
	}

	istream& operator >> (istream& in, motorcycle& obj)
	{
		return obj.read(in);
	}

	ostream& operator << (ostream& out, motorcycle& obj)
	{
		return obj.print(out);
	}
//----------------------------------water motorcycle class-----------------------------
	water_motorcycle::water_motorcycle() : boat(), motorcycle(), price(0)
	{	}

	water_motorcycle::water_motorcycle(int year) : boat(), motorcycle(year), price(0)
	{	}

	water_motorcycle::water_motorcycle(int power, float gasoline) : boat(power, gasoline), motorcycle(), price(0)
	{	}

	water_motorcycle::water_motorcycle(double new_price) : boat(), motorcycle(), price(new_price)
	{	}

	water_motorcycle::water_motorcycle(int power, float gasoline, int year, double _price) : boat(power, gasoline), motorcycle(year), price(_price)
	{	}

	istream& operator >> (istream& in, water_motorcycle& obj)
	{
		obj.boat::read(in);
		obj.motorcycle::read(in);
		cout << "Enter the water motorcycle price: " << endl;
		in >> obj.price;
		return(in);
	}

	ostream& operator << (ostream& out, water_motorcycle& obj)
	{
		obj.boat::print(out);
		obj.motorcycle::print(out);
		cout << "Water motorcycle price: " << obj.price << endl;
		return(out);
	}