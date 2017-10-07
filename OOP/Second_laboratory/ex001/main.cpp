#include <iostream>
#include "document.h"

using namespace std;

int main()
{
	Document * doc = new Document;
	doc->setAuthor("Andrei");
	doc->setDay("Marti");
	doc->setTitle("License");
	doc->setLastChange("29/09/2017");
	doc->setNumberOfPages(100);
	doc->setSubject("criminal");

	doc->displayDocumentInformation();
	doc->modifyData();
	doc->displayDocumentInformation();	

	return 0;
}