#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>

#include "Colaborator.h"

using namespace std;

void allocMemory(contributor * person, char * name, char * specialty, char * category, int salary)
{
	person->name = new char[strlen(name) + 1];
	strcpy(person->name, name);
	person->specialty = new char[strlen(specialty) + 1];
	strcpy(person->specialty, specialty);
	person->category = new char[strlen(category) + 1];
	strcpy(person->category, category);
	person->salary = salary;
}

contributor * inputData(contributor * person, int number_of_persons)
{
	char * newName = new char[100];
	char * newSpecialty = new char[100];
	char * newCategory = new char[100];
	int newSalary = 0;
	for (int i = 0; i < number_of_persons; i++)
	{
		cout << "Enter the name of the person: " << endl;
		cin >> newName;
		cout << "Enter the specialty: " << endl;
		cin >> newSpecialty;
		cout << "Enter the category: " << endl;
		cin >> newCategory;
		cout << "Enter the salary" << endl;
		cin >> newSalary;
		allocMemory(&person[i], newName, newSpecialty, newCategory, newSalary);

	}
	delete[] newName;
	delete[] newSpecialty;
	delete[] newCategory;
	return person;
}

//--------------------------------------------Sorting function-------------------------------------------------//
void changeName(contributor * person)
{
	char * newName = new char[100];
	cout << "Enter the new name: " << endl;
	cin >> newName;
	delete[] person->name;
	person->name = new char[strlen(newName) + 1];
	strcpy(person->name, newName);
}

void changeSpecialty(contributor * person)
{
	char * newSpecialty = new char[100];
	cout << "Enter the new specialty: " << endl;
	cin >> newSpecialty;
	delete[] person->specialty;
	person->specialty = new char[strlen(newSpecialty) + 1];
	strcpy(person->specialty, newSpecialty);
}

void changeCategory(contributor * person)
{
	char * newCategory = new char[100];
	cout << "Enter the new category: " << endl;
	cin >> newCategory;
	delete[] person->category;
	person->category = new char[strlen(newCategory) + 1];
	strcpy(person->category, newCategory);
}

void changeSalary(contributor * person)
{
	int newSalary = 0;
	cout << "Enter the new salary: " << endl;
	cin >> newSalary;
	person->salary = newSalary;
}

void modifyData(contributor * person, int number_of_persons)
{
	string name;
	string option;

	cout << "Enter the name of the person you want to modify: " << endl;
	cin >> name;

	for (int i = 0; i < number_of_persons; i++)
	{
		if (name == person[i].name)
		{
			cout << "What do you want to modify?(name/specialty/category/salary) " << endl;
			cin >> option;

			if (option == "name" || option == "Name")
				changeName(&person[i]);
			if (option == "specialty" || option == "Specialty")
				changeSpecialty(&person[i]);
			if (option == "category" || option == "Category")
				changeCategory(&person[i]);
			if (option == "salary" || option == "Salary")
				changeSalary(&person[i]);
		}
	}
}

//-----------------------------------------------------Sorting functions-----------------------------------------//
void nameSorting(contributor * person, int number_of_persons)
{
	contributor temp;

	for (int i = 1; i < number_of_persons ; i++)
	{
		if(strcmp(person[i - 1].name, person[i].name) > 0)
		{
			temp = person[i - 1];
			person[i - 1] = person[i];
			person[i] = temp;
		}
	}
}

void specialtySorting(contributor * person, int number_of_persons)
{
	contributor temp;

	for (int i = 1; i < number_of_persons; i++)
	{
		if (strcmp(person[i - 1].specialty, person[i].specialty) > 0)
		{
			temp = person[i - 1];
			person[i - 1] = person[i];
			person[i] = temp;
		}
	}
}
void categorySorting(contributor * person, int number_of_persons)
{
	contributor temp;

	for (int i = 1; i < number_of_persons; i++)
	{
		if (strcmp(person[i - 1].category, person[i].category) > 0)
		{
			temp = person[i - 1];
			person[i - 1] = person[i];
			person[i] = temp;
		}
	}
}

void heapify(contributor * person, int number_of_persons, int index)
{
	int largest = index;
	contributor temp;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < number_of_persons && person[left].salary > person[largest].salary)
		largest = left;
	if (right < number_of_persons && person[right].salary > person[largest].salary)
		largest = right;
	if (largest != index)
	{
		temp = person[index];
		person[index] = person[largest];
		person[largest] = temp;

		heapify(person, number_of_persons, largest);
	}

}

void salarySorting(contributor * person, int number_of_persons)
{
	contributor temp;

	for (int i = number_of_persons / 2 - 1; i >= 0; i--)
		heapify(person, number_of_persons, i);
	for (int i = number_of_persons - 1; i >= 0; i--)
	{
		temp = person[0];
		person[0] = person[i];
		person[i] = temp;

		heapify(person, i, 0);
	}
}

void dataSorting(contributor * person, int number_of_persons)
{
	string criteria;
	cout << "Enter the criteria of sorting:(Name/Specialty/Category/Salary) " << endl;
	cin >> criteria;
	if (criteria == "name" || criteria == "Name")
		nameSorting(person, number_of_persons);
	if (criteria == "specialty" || criteria == "Specialty")
		specialtySorting(person, number_of_persons);
	if (criteria == "category" || criteria == "Category")
		categorySorting(person, number_of_persons);
	if (criteria == "salary" || criteria == "Salary")
		salarySorting(person, number_of_persons);
}

void outputData(contributor * person, int number_of_persons)
{
	cout << "\n\n" << endl;
	for (int i = 0; i < number_of_persons; i++)
	{
		cout << setw(10) << person[i].name << setw(15) << person[i].specialty << setw(5) << person[i].category << setw(10) << person[i].salary << endl;
	}
	cout << "\n\n" << endl;
}

void freeMem(contributor * person, int number_of_persons)
{
	for (int i = 0; i < number_of_persons; i++)
	{
		if(person[i].name)
			delete[] person[i].name;
		if(person[i].specialty)
			delete[] person[i].specialty;
		if(person[i].category)
			delete[] person[i].category;
		person[i].salary = 0;
	}
}

