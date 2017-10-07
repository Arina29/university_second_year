#ifndef _DOCUMENT_H
#define _DOCUMENT_H

#include <iostream>
#include <cstring>

using namespace std;

class Document
{
private:
	char * title;
	char * subject;
	char * author;
	char * day;
	char * lastChange;

	int pages;

	void modifyTitle();
	void modifySubject();
	void modifyAuthor();
	void modifyDay();
	void modifyPages();
	void modifylastChange();

public:
	Document() : pages(0), lastChange(new char[strlen("noChange") + 1]), title(new char[strlen("noTitle") + 1]), subject(new char[strlen("noSubject") + 1]), author(new char[strlen("noAuthor") + 1]), day(new char[strlen("noDay") + 1])
	{	}
	Document(char *);
	Document(const Document &);
	Document(char*, char*, char*, char*, int, char*);
	~Document();

	void modifyData();
	void setTitle(char*);
	void setSubject(char*);
	void setAuthor(const char*);
	void setDay(char*);
	void setLastChange(char*);	
	void setNumberOfPages(int);
	void displayDocumentInformation();

};

#endif
