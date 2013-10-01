#ifndef BOOK_H
#define BOOK_H

#pragma once
#include "item.h"

using namespace std;

class Book : public Item
{
public:
	Book(const string& title, const string& author, const int nPages);
	~Book();
	const int getPages() const;
	const string getAuthor() const;
	virtual void print(ostream& out) const;

private:

	int numPages;
	string Author;

};
ostream& operator<<(ostream& out, const Book* book);
#endif

