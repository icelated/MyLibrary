#include "CD.h"

using namespace std;

/**
* CD: constructor
* in: none
* out: none
* return: none
**/
CD::CD(const string& theTitle, const string& theBand, const int snumber)
: Item(theTitle), band(theBand),number(snumber), music(new StringSet)
{



}
/**
* CD: Destructor
* in: none
* out: none
* return: none
**/
CD::~CD()
{

	delete music;

}

/**
* CD: get band
* in: none
* out: none
* return: band
**/
const string CD::getBand() const
{
	return band;

}

/**
* CD: get musician
* in: none
* out: none
* return: music
**/
const StringSet* CD::getMusician() const
{
	return music;

}
/**
* CD: get number
* in: none
* out: none
* return: number
**/
const int CD::getNumber() const
{

	return number;

}

/**
* CD: add band members to the set
* in: member
* out: none
* return: none
**/
void CD::addBandMember(const string &member)
{

	music->insert(member);

}

/**
* CD: print - music information
* in: out
* out: none
* return: none
**/
void CD::print(ostream &out) const
{

	out << "-MusicCD-" << endl;
	out << "band:      " << this->getBand() << endl;
	out << "musicians: " << this->printmusicians(this->getMusician()) << endl;
	out << "songs:     " << this->getNumber() << endl;
	out << "title:     " << this->getTitle() << endl;
	out << "keywords:  " << this->printKeywords(this->getKeywords()) << endl;
	out << endl;


}
/**
* CD: overloaded operator
* in: out,cd
* out: none
* return: out
**/
ostream& operator<<(ostream& out, const CD* cd)
{

	cd->print(out);
	return out;

}

/**
* CD: print musicians
* in: stringset musicians
* out: none
* return: music string
**/
string CD::printmusicians(const StringSet *musicians) const
{

	string musicString;

	StringSet::const_iterator itr;



	for(itr = musicians->begin(); itr != musicians->end(); itr++)


		musicString.append(*itr + ", ");

	musicString.erase(musicString.end() - 2, musicString.end());

	return musicString;

}