#include <iostream>
#include <cstdlib>
#include "boat.h"
#include "motorcycle.h"
#include "water_motorcycle.h"

using namespace std;

int main()
{
	water_motorcycle a;	
	water_motorcycle b(2, 3, 4, 5);

	cin >> a;
	system("clear");
	cout << a;
	cout << b;

	return 0;
}