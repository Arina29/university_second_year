#include <iostream>
#include <string>
#include <iomanip>

#include "Colaborator.h"

using namespace std;

int main()
{
	int number_of_persons;
	bool change = true;
	
	cout << "Enter the number of people:";
	cin >> number_of_persons;

	contributor * person = new contributor[number_of_persons];

	inputData(person, number_of_persons);
	outputData(person, number_of_persons);

	while (1)
	{
		cout << "Do you want to modify some data? (1-Yes/0-No) " << endl;
		cin >> change;
		if (change)
			modifyData(person, number_of_persons);
		else
			break;
	}

	while (1)
	{
		cout << "Do you want to sort data?(1/0)" << endl;
		cin >> (change);
		if (change)
			dataSorting(person, number_of_persons);
		else
			break;
	}
	outputData(person, number_of_persons);
	freeMem(person, number_of_persons);
	return 0;
}