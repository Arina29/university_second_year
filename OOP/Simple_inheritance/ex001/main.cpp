#include <iostream>
#include <cstdlib>
#include "liquid.h"

using namespace std;

int main()
{
	alcohol a("Wine", 30, 40);
	alcohol b;

	cout << "Enter the object's values: " << endl;
	cin >>	b;
	system("clear");
	cout << b;
	cout << "----------With changed density and ABV-----------" << endl;
	b.change_density(35);
	b.change_ABV(20);
	cout << b;

	return 0;	
}