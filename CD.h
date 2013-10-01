#ifndef CD_H
#define CD_H
#pragma once
#include "item.h"
#include <set>


typedef set<string>	StringSet;


class CD : public Item
{
public:

	CD(const string& theTitle, const string& theBand, const int snumber);
	void addBandMember(const string& member);
	const int getNumber() const;
	const StringSet* getMusician() const;
	const string getBand() const;
	virtual void print(ostream& out) const;
	string printmusicians(const StringSet* musicians) const;

	~CD();


private:

	string band;
    StringSet* music;   // hold musicians

	string title;
	int number;

};

ostream& operator<<(ostream& out, const CD* cd);

#endif
