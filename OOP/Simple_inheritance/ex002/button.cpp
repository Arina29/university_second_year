#include <iostream>
#include <cstring>
#include "button.h"

using namespace std;

//-----------------------Button class-----------------------

Button::Button() : text(new char[strlen("NoText") + 1])
{	}

Button::Button(char * newText) : text(new char[strlen(newText) + 1])
{
	strcpy(text, newText);
}

Button::Button(const Button &other)
{
	text = new char[strlen(other.text)];
	strcpy(text, other.text);
}

istream& Button::read(istream &in)
{
	if(text)
		delete[] text;

	char* b_text = new char[100];
	cout << "Enter the button text:";
	in >> b_text;

	text = new char[strlen(b_text) + 1];
	strcpy(text, b_text);
	delete[] b_text;

	return in;
}

istream& operator << (istream& in, Button& obj)
{
	return obj.Button::read(in);
}

char* Button::getButtonText()
{
	return text;
}	

//-----------------------Window class-------------------------
Window::Window() : button((char*)"NoText"), x(0.0), y(0.0)
{	}

Window::Window(char * button_text) : button(button_text), x(0.0), y(0.0)
{	}

Window::Window(char* button_text, double x_val, double y_val) : button(button_text)
{
	x = x_val;
	y = y_val;
}

Window::Window(Window& other) : button(other.getButtonText()), x(other.x), y(other.y)
{	}

char* Window::getButtonText()
{
	return button.getButtonText();
}

ostream& Window::print(ostream& out)
{
	out << "Button Message: ";
	out << button.getButtonText();
	out << "\n" << "X coordinate: ";
	out << x;
	out << "\n" << "Y coordinate: ";
	out << y;
}

istream& Window::read(istream& in)
{
	button.read(in);
	cout<<"Enter the coordinates: ";
	in >> x >> y;
	return in;
}

istream& operator >> (istream& in, Window& obj)
{
	return obj.Window::read(in);
}

Window::~Window()
{
	delete[] button.getButtonText();
	x = 0.0;
	y = 0.0;
}
//----------------------Window with button class--------------

Window_with_Button::Window_with_Button() : Window()
{	
	message = new char[strlen("NoMessage") + 1];
}

Window_with_Button::Window_with_Button(char* text, double x_val, double y_val, char* w_message) : Window(text, x_val, y_val)
{
	message = new char [strlen(w_message) + 1];
	strcpy(message, w_message);
}

istream& operator >> (istream& in, Window_with_Button& obj)
{
	obj.Window::read(in);

	if(obj.message)
		delete[] obj.message;

	char* w_message = new char[10];
	cout << "Enter the window message: ";
	in >> w_message;

	obj.message = new char[strlen(w_message) + 1];
	strcpy(obj.message, w_message);
	
	delete[] w_message;

	return in;
}


ostream& operator << (ostream& out, Window_with_Button& obj)
{
	obj.print(out);
	out << "\n" << "Window message: ";
	for(int i = 0; i < strlen(obj.message); i++)
		out << obj.message[i];
	out << endl;
	return out;
}