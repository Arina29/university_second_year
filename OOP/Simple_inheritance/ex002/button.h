#ifndef _BUTTON_H_
#define _BUTTON_H_

#include <iostream>

using namespace std;

class Button
{
protected:
	char* text;

public:
	Button();
	Button(char *);
	Button(const Button &other);

	virtual char* getButtonText();
	
	virtual istream& read(istream& in);
	friend istream& operator >> (istream& in, Button& obj);
};

class Window
{	
protected:
	Button button;
	double x;
	double y;

public:
	Window();
	Window(char*);
	Window(char*, double, double);
	Window(Window&);
	char* getButtonText();
	virtual istream& read(istream& in);
	virtual ostream& print(ostream& out);

	friend istream& operator >> (istream& in, Window& obj);
	~Window();
};


class Window_with_Button : public Window
{
	char* message;

public:
	Window_with_Button();
	Window_with_Button(char*, double, double, char*);

	friend ostream& operator << (ostream& out, Window_with_Button& obj);
	friend istream& operator >> (istream& in, Window_with_Button& obj);
};


#endif