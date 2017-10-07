#ifndef _COLABORATOR_H
#define _COLABORATOR_H

using namespace std;

typedef struct contributor
{
	char * name;
	char * specialty;
	char * category;
	int salary;
}contributor;

void allocMemory(contributor * person, char * name, char * specialty, char * category, int salary);
contributor * inputData(contributor * person, int number_of_persons);

void modifyData(contributor * person, int number_of_persons);

void dataSorting(contributor * person, int number_of_persons);

void outputData(contributor * person, int number_of_persons);

void freeMem(contributor * person, int number_of_persons);

#endif