#include "Item.h"
#include "library.h"
#include <iostream>

/**
* Item: constructor - initializer list
* in: title
* out: Keys
* return: none
**/
Item::Item(const string& title): Title(title), Keys(new StringSet)
{


}

/**
* Item: destructor
* in: none
* out: none
* return: none
**/
Item::~Item()
{

     delete Keys;	
	
}

/**
* Item: add keywords to item
* in: keyword
* out: Keys
* return: none
**/
void Item::addKeyword(const string& keyword) const
{

	Keys->insert(keyword);

	
}

/**
* Item: get title
* in: none
* out: none
* return: title
**/
const string Item::getTitle() const
{
	return Title;
}

/**
* Item: get keywords
* in: none
* out: none
* return: keys
**/
const StringSet* Item::getKeywords() const
{
	return Keys;
}

/**
* Item: print keywords
* in: stringset keywords
* out: none
* return: string
**/
string Item::printKeywords(const StringSet* keywords) const
{


	string keyString;

	StringSet::const_iterator itr;

	

	for(itr = keywords->begin();itr != keywords->end();itr++)

	keyString.append(*itr + ", ");

	keyString.erase(keyString.end() - 2, keyString.end());

	return keyString;



}

/**
* Item: overload operator
* in: item
* out: out
* return: out
**/
ostream& operator<<(ostream& out, const Item*  item)
{
	item->print(out);
	return out;
}


/**
* Item: print
* in: out
* out: none
* return: none
**/
void Item::print(ostream &out) const
{


	out << "title: " << this->getTitle() << endl;
	out << endl;

}

