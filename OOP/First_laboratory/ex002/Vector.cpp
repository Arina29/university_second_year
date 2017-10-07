#include <iostream>
#include <iomanip>
#include <stdio.h>

#include "Vector.h"

using namespace std;

void initVec(vector * self, int number_of_elem)
{
	self->number_of_elements = number_of_elem;
	self->vectorValues = new long[self->number_of_elements];
}

vector * setData(vector * self, int num_of_elem)
{
	if (num_of_elem > VECTOR_INIT_CAPACITY)
		num_of_elem = 4;

	initVec(self, num_of_elem);
	cout << "Enter the vector's values:\n" << endl;
	for (int i = 0; i < num_of_elem; i++)
	{
		cout << "Enter the value: " << i + 1 << endl;
		cin >> self->vectorValues[i];
	}
	return self;
}

void freeMemory(vector * self)
{
	for (int i = 0; i < self->number_of_elements; i++)
	{
		self->vectorValues[i] = 0;
	}
	self->number_of_elements = 0;
	delete[] self;
}


void vectorResize(vector * self, int num_of_elem)
{
	cout << "Resize the vector from: " << self->number_of_elements << " to " << num_of_elem << endl;
	freeMemory(self);
	setData(self, num_of_elem);
}



vector * vectorAddition(vector * vec1, vector * vec2, vector * result)
{
	int num_of_elem = 0;

	num_of_elem = vec2->number_of_elements;
	initVec(result, num_of_elem);

	for (int i = 0; i < num_of_elem; i++)
	{
		result->vectorValues[i] = vec1->vectorValues[i] + vec2->vectorValues[i];
	}
	return result;
}


int getVectorSize(vector * self)
{
	return self->number_of_elements;
}

void changeVectorValue(vector * self, int index, int value)
{
	int temp;
	for (int i = 0; i < index; i++)
	{
		if ((i + 1) == index)
		{
			temp = self->vectorValues[i];
			self->vectorValues[i] = value;
		}
	}
}

void printVector(vector * self)
{
	for (int i = 0; i < self->number_of_elements; i++)
		cout << setw(5) << self->vectorValues[i];
	cout << "\n";
}