#include "Book.h"

using namespace std;

/**
* Book: constructor
* in: title, author, pages
* out: item,pages, author
* return: none
**/
Book::Book(const string &title, const string &author, const int nPages)
:Item(title),numPages(nPages),Author(author)
{


}

/**
* Book: get author
* in: none
* out: none
* return: author
**/
const string Book::getAuthor() const
{

	return Author;

}

/**
* Book: get pages
* in: none
* out: none
* return: pages
**/
const int Book::getPages() const
{
	return numPages;

}
/**
* Book: print book information
* in: out
* out: none
* return: none
**/
void Book::print(ostream &out) const

{
	out << "-Book-" << endl;
	out << "author:    " << this->getAuthor() << endl;
	out << "pages:     " << this->getPages() << endl;
	out << "title:     " << this->getTitle() << endl;
	out << "keywords:  " << this->printKeywords(this->getKeywords()) << endl; 
	out << endl;

}
/**
* Book: overloaded operator
* in: out, book
* out: out
* return: out
**/
ostream& operator<<(ostream& out, const Book* book)
{
	book->print(out);
	return out;

}

/**
* Book: destructor
* in: none
* out: none
* return: author
**/
Book::~Book()
{

}