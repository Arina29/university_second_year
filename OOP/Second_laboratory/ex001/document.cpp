#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>

#include "document.h"

using namespace std;

Document::Document(char * newTitle, char * newSubject, char * newAuthor, char * newDay, int newPages, char * newLastChange)
{
	title = new char[strlen(newTitle) + 1];
	strcpy(title, newTitle);
	
	subject = new char[strlen(newSubject) + 1];
	strcpy(subject, newSubject);
	
	author = new char[strlen(newAuthor) + 1];
	strcpy(author, newAuthor);
	
	day = new char[strlen(newDay) + 1];
	strcpy(day,  newDay);
	
	pages = newPages;
	lastChange = new char[strlen(newLastChange) + 1];
	strcpy(lastChange, newLastChange);
}


Document::Document(const Document &doc) : title(doc.title), subject(doc.subject), author(doc.author), pages(doc.pages), day(doc.day), lastChange(doc.lastChange)
{
	title = new char [strlen(doc.title) + 1];
	strcpy(title, doc.title);

	subject = new char[strlen(doc.subject) + 1];
	strcpy(subject, doc.subject);
	
	author = new char [strlen(doc.author) + 1];
	strcpy(author, doc.author);
	
	day = new char[strlen(doc.day) + 1];
	strcpy(day, doc.day);
	
	pages = doc.pages;
	lastChange = new char[strlen(doc.lastChange) + 1];
	strcpy(lastChange, doc.lastChange);
}

Document::Document(char * title)
{
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
	subject = new char [strlen("noSubject") + 1];
	author = new char [strlen("noAuthor") + 1];
	day = new char [strlen("noDay") + 1];
	lastChange = new char [strlen("noChanges") + 1];
	pages = 0;
	
}

void Document::setTitle(char * _title)
{
	if (title)
		delete[] title;
	title = new char[strlen(_title) + 1];
	strcpy(title, _title);
}

void Document::setSubject(char * _subject)
{
	if (subject)
		delete[] subject;
	subject = new char[strlen(_subject) + 1];
	strcpy(subject, _subject);
}

void Document::setAuthor(const char * _author)
{
	if (author)
		delete[] author;
	author = new char[strlen(_author) + 1];
	strcpy(author, _author);
}

void Document::setDay(char * _day)
{
	if (day)
		delete[] day;
	day = new char[strlen(_day) + 1];
	strcpy(day, _day);
}

void Document::setNumberOfPages(int _pages)
{
	pages = _pages;
}

void Document::setLastChange(char * _lastChange)
{
	if(lastChange)
		delete[] lastChange;
	lastChange = new char[strlen(_lastChange) + 1];
	strcpy(lastChange, _lastChange);
}

void Document::displayDocumentInformation()
{
	cout << "\n";
	cout << setw(5) << setw(15) << left << "Title: "<< setw(15) << left << title << endl;
	cout << setw(5) << setw(15) << left << "Subject: " << setw(15) << left << subject << endl;
	cout << setw(5) << setw(15) << left << "Author: " << setw(15) << left << author << endl;
	cout << setw(5) << setw(15) << left << "Pages: " << setw(15) << left << pages << endl;
	cout << setw(5) << setw(15) << left << "Day: " << setw(15)  << left <<day << endl;
	cout << setw(5) << setw(15) << left << "Last change: " << setw(15) << left << lastChange << endl;
}

void Document::modifyTitle()
{
	char * _title = new char[100];
	cout << "Enter the new title: " << endl;
	cin >> _title;
	
	delete[] title;
	title = new char[strlen(_title) + 1];
	strcpy(title, _title);

}

void Document::modifySubject()
{
	char * _subject = new char[100];
	cout << "Enter the new subject: " << endl;
	cin >> _subject;

	delete[] subject;
	subject = new char[strlen(_subject) + 1];
	strcpy(subject, _subject);
}

void Document::modifyAuthor()
{
	char * _author = new char[100];
	cout << "Enter the new name of the author: " << endl;
	cin >> _author;

	delete[] author;
	author = new char[strlen(_author) + 1];
	strcpy(author, _author);
}

void Document::modifyDay()
{
	char * _day = new char[100];
	cout << "Enter the new date: " << endl;
	cin >> _day;

	delete[] day;
	day = new char[strlen(_day) + 1];
	strcpy(day, _day);
}

void Document::modifyPages()
{
	int _pages = 0;
	cout << "Enter the new number of pages:" << endl;
	cin >> _pages;

	pages = _pages;
}

void Document::modifylastChange()
{
	char * _lastChange = new char[100];
	cout << "Enter the new day of the lastChange: " << endl;
	cin >> _lastChange;

	delete[] lastChange;
	lastChange = new char[strlen(_lastChange) + 1];
	strcpy(lastChange, _lastChange);
}


void Document::modifyData()
{
	enum choice {Title = 1, Subject = 2, Author = 3, Day = 4, Pages = 5, LastChange = 6};
	int nr;

	cout << "\n\nWhat do you want to change? Enter the number according to your choice:\n" <<
		"1 - Title\n" << "2 - Subject\n" << "3 - Author\n" << "4- Day\n" <<
		"5 - Pages\n" << "6 - Last change" << endl;
	cin >> nr;

	switch (nr)
	{
	case 1:
		modifyTitle();
		break;
	case 2:
		modifySubject();
		break;
	case 3:
		modifyAuthor();
		break;
	case 4:
		modifyDay();
		break;
	case 5:
		modifyPages();
		break;
	case 6:
		modifylastChange();
		break;
	default:
		cout << "The number entered is not correct...Try again";
		modifyData();
		break;
	}
}

Document::~Document()
{
	cout << "Deleted";
	delete[] title;
	delete[] subject;
	delete[] author;
	delete[] day;
	delete[] lastChange;
	pages = 0;
}



