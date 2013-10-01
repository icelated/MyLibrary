#ifndef DVD_H
#define DVD_H
#pragma once
#include "item.h"
#include <set>

typedef set<string>	StringSet;

class DVD : public Item
{
public:

	DVD(const string title, const string director, int nScenes);
	const string getDirector() const;
    void addCast(const string& cast);
	const int getScenes() const;
	const StringSet* getCast() const;
	virtual void print(ostream& out) const;
	string printCast(const StringSet* cast) const;
	~DVD();

private:

	string Director;
	StringSet* Moviecast;       // hold cast members
	int Scenes;

};

ostream& operator<<(ostream& out, const DVD* dvd);
#endif
