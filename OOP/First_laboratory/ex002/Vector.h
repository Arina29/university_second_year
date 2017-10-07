#ifndef _VECTOR_H
#define _VECTOR_H

#define VECTOR_INIT_CAPACITY 4

typedef struct vector
{
	long * vectorValues;
	int number_of_elements;
}vector;

vector * setData(vector * self, int num_of_elem);
vector * vectorAddition(vector * vec1, vector * vec2, vector * result);
void printVector(vector * self);
int getVectorSize(vector * self);
void vectorResize(vector * self, int num_of_elem);
void changeVectorValue(vector * self, int index, int value);

#endif