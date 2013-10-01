#include "DVD.h"

using namespace std;

/**
* DVD: Constructor
* in: title, director, scenes
* out: title, director,scenese, moviecast
* return: none
**/
DVD::DVD(const string title, const string director, int nScenes)
:Item(title),Director(director),Scenes(nScenes), Moviecast(new StringSet)
{


}
/**
* DVD: Destructor
* in: none
* out: none
* return: none
**/
DVD::~DVD()
{

	delete Moviecast;

}
/**
* DVD: add cast to dvd
* in: cast
* out: none
* return: none
**/
void DVD::addCast(const string& cast)
{

	Moviecast->insert(cast);

}

/**
* DVD: get cast
* in: none
* out: none
* return: moviecast
**/
const StringSet* DVD::getCast() const
{
	return Moviecast;

}
/**
* DVD: get director
* in: none
* out: none
* return: director
**/
const string DVD::getDirector() const
{
	return Director;

}
/**
* DVD: get scenes
* in: none
* out: none
* return: scenes
**/
const int DVD::getScenes() const
{
	return Scenes;

}

/**
* DVD: print  - movie
* in: out
* out: none
* return: none
**/
void DVD::print(ostream &out) const
{

	out << "-MovieDVD-" << endl;
	out << "director:  " << this->getDirector() << endl;
	out << "cast:      " << this->printCast(this->getCast()) << endl;
	out << "scenes:    " << this->getScenes() << endl;
	out << "title:     " << this->getTitle() << endl;
	out << "keywords:  " << this->printKeywords(this->getKeywords()) << endl;
	out << endl;

}
/**
* DVD: overloaded operator
* in: DVD, out
* out: none
* return: out
**/
ostream& operator<<(ostream& out, const DVD* dvd)
{

	dvd->print(out);
	return out;

}
/**
* DVD: print cast members
* in: cast
* out: none
* return: cast string
**/
string DVD::printCast(const StringSet *cast) const
{

	string castString;

	StringSet::const_iterator itr;



	for(itr = cast->begin(); itr != cast->end(); itr++)


		castString.append(*itr + ", ");

	castString.erase(castString.end() - 2, castString.end());

	return castString;

}