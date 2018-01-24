#include <iostream>
#include <cstdlib>

#include "vector.h"

using namespace std;

void display_menu()
{
	cout << "----------Menu------------" << endl;
	cout << "1 - Evaluate addition" << endl;
	cout << "2 - Evaluate substraction" << endl;
	cout << "3 - Evaluate == operator" << endl;
	cout << "4 - Evaluate != operator" << endl;
	cout << "5 - Evaluate < operator" << endl;
	cout << "6 - Evaluate > operator" <<endl;
}

int main()

{
	Vector vec1(3);
	Vector vec2(3);
	Vector vec3(3);
	cout << "Enter the first vector's values: " << endl;
	cin >> vec1;
	cout << "Enter the second vector's value: " << endl; 
	cin >> vec2;
	system ("clear");

	display_menu();
	bool answer;

	while(1)
	{

		cout << "Do you want to verify something?" << endl;
		cin >> answer;
		if(answer == false)
			break;
		

		else
		{
			int option;

			cout <<"Enter your option!" << endl;
			cin >> option;
			
			switch(option)
			{
				case 1:
					cout << "First: " << vec1 << endl;
					cout << "Second: " << vec2 << endl;
					cout <<"----------------" << endl;
					vec3 = vec1 + vec2;
					cout << "Sum: " << vec3 << endl;
					break;

				case 2:
					cout << "First: " << vec1 << endl;
					cout << "Second: " << vec2 << endl;
					cout <<"----------------" << endl;
					vec3 = vec1 - vec2;
					cout << "Difference: " << vec3 << endl;
					break;

				case 3:
					if(vec2 == vec1)
						cout << "Vectors are equal " << endl;
					else
						cout << "Vectors are not equal" << endl;
					break;

				case 4:
					if(vec2 != vec1)
						cout << "Vectors are not equal" << endl;
					else
						cout << "Vectors are equal" << endl;
					break;

				case 5:
					if(vec1 > vec2)
						cout << "First is bigger" << endl;
					else
						cout << "Second is bigger" << endl;
					break;

				case 6: 
					if(vec1 < vec2)
						cout << "Second is bigger" << endl;
					else 
						cout <<"First is bigger" << endl;
					break;
			}
		}
	}
return 0;

}


