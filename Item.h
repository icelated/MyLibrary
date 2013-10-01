#pragma once

#include <ostream>
#include <set>
#include <string>

using namespace std;

typedef set<string>	StringSet;

class Item
{
protected:

	Item(const string& title);

public:

	void addKeyword(const string& keyword)const;
	const string getTitle() const;
	const StringSet* getKeywords() const;
	virtual void print(ostream& out) const;
	string printKeywords(const StringSet* keywords) const;
	virtual ~Item();

private:

	string Title;
	StringSet* Keys;      // holds keywords


};

ostream& operator<<(ostream& out, const Item* const item);

