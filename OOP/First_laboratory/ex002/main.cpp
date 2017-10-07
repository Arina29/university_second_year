#include <iostream>

#include "Vector.h"

using namespace std;

int main()
{
	vector * vec1 = new vector[VECTOR_INIT_CAPACITY];
	vector * vec2 = new vector[VECTOR_INIT_CAPACITY];
	vector * result = new vector[VECTOR_INIT_CAPACITY];
	int number_of_elements;

	cout << "Enter the number of vector's elements between (maximum 4): " << endl;
	cin >> number_of_elements;
	int length;
	int newSize;

	setData(vec1, number_of_elements);
	setData(vec2, number_of_elements);


	result = vectorAddition(vec1, vec2, result);
	cout << "vector1: ";
	printVector(vec1);
	cout << "vector2: ";
	printVector(vec2);
	cout << "result: ";
	printVector(result);
	return 0;
}