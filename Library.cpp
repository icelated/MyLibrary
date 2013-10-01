#include "Library.h"
#include "book.h"
#include "cd.h"
#include "dvd.h"

#include <iostream>


/**
* Library: Constructor
* in: none
* out: none
* return: none
**/
Library::Library()
: allKeywords(new ItemSet),allMusicByBand(new ItemSet),allMusicByMusician(new ItemSet),
allmoviesByDirector(new ItemSet),allmoviesByActor(new ItemSet), allBooksByAuthor(new ItemSet)
{

}

/**
* Library: add keyword
* in: item, keyword
* out: none
* return: none
**/
void Library::addKeywordForItem(const Item* item, const string& keyword)
{


	item->addKeyword(keyword); // call addkeyword function and add keyword to item

	
}

/**
* Library: Search allkeywords for a given keyword
* in: keyword
* out: none
* return: allkeywords
**/
const ItemSet* Library::itemsForKeyword(const string& keyword) const
{



	const StringSet* kw;

	if(allKeywords->size() > 0) // clear keyword
	{
		allKeywords->clear();
	}

	/* search books */
	for(ItemSet::const_iterator itr = this->allBooks.begin(); itr != this->allBooks.end(); itr++)
	{

		kw = ((*itr)->getKeywords());

		if((kw->find(keyword)) != kw->end())
		{

			allKeywords->insert(*itr);  // add the found keyword

		}


	}



	/* search cd */
	for(ItemSet::const_iterator itr = this->allCDS.begin();itr != this->allCDS.end();itr++)
	{

		kw = ((*itr)->getKeywords());

		if((kw->find(keyword)) != kw->end())
		{

			allKeywords->insert(*itr);

		}

	}



	/* search Movie */
	for(ItemSet::const_iterator itr = this->allDVDs.begin();itr != this->allDVDs.end();itr++)
	{

		kw = ((*itr)->getKeywords());

		if((kw->find(keyword)) != kw->end())
		{

			allKeywords->insert(*itr);

		}

	}

	return allKeywords; // return the find



}

/**
* Library: print
* in: out, item
* out: none
* return: out
**/
void Library::printItem(ostream& out, const Item* const item) const
{

	out << item;

}

/**
* Library: addBook
* in: title, author, pages
* out: none
* return: item
**/
const Item* Library::addBook(const string& title, const string& author, const int nPages)
{

	Book* item = new Book(title,author,nPages);
	allBooks.insert(item); // add to set of all books

	return item;



}

/**
* Library: add all books by a particular author
* in: author
* out: none
* return: none
**/
const ItemSet* Library::booksByAuthor(const string& author) const
{

	/* search allbooks for an author */
	for (ItemSet::const_iterator i = this->allBooks.begin(); i != this->allBooks.end(); ++i)
	{
		if(((Book*) *i)->getAuthor() == author)
		{
			allBooksByAuthor->insert(*i);

		}


	}

	return  allBooksByAuthor;

}

/**
* Library: Return all books that were added
* in: none
* out: none
* return: none
**/
const ItemSet* Library::books() const
{

	return &allBooks;
}


// music-related functions


/**
* Library: add music cd information
* in: title, band, songs
* out: none
* return: item
**/
const Item* Library::addMusicCD(const string& title, const string& band, const int nSongs)
{

	CD* item = new CD(title,band,nSongs);

	allCDS.insert(item);

	return item;

}

/**
* Library: add band members to the allCDS 
* in: musicCD, member
* out: none
* return: none
**/
void Library::addBandMember(const Item* musicCD, const string& member)
{

	
	(((CD*) musicCD)->addBandMember(member)); 

	
}

const ItemSet* Library::musicByBand(const string& band) const
{

	if(allMusicByBand->size() > 0)     // this is just incase there is not a find
	{                                  // and it dont return the last found item.
		allMusicByBand->clear();
	}

	/* search allCDS for a particular band */
	for (ItemSet::const_iterator i = this->allCDS.begin(); i != this->allCDS.end(); ++i)
	{
		if(((CD*) *i)->getBand() == band)
		{
			allMusicByBand->insert(*i);

		}


	}

	return  allMusicByBand;

}


/**
* Library: Search and add all instances of a certian musician
* in: musician
* out: none
* return: allMusicByMusician
**/
const ItemSet* Library::musicByMusician(const string& musician) const
{


	const StringSet* search_m;


	for (ItemSet::const_iterator i = this->allCDS.begin(); i != this->allCDS.end(); ++i)
	{

		search_m = (((CD*) *i)->getMusician());

		if((search_m->find(musician)) != search_m->end())
		{

			allMusicByMusician->insert(*i);

		}

	}

	return  allMusicByMusician;


}

/**
* Library: return all music CD
* in: none
* out: none
* return: allCDS
**/
const ItemSet* Library::musicCDs() const
{
	return &allCDS;
}

// movie-related functions


/**
* Library: add all movies
* in: title, director, scenes
* out: none
* return: item
**/
const Item* Library::addMovieDVD(const string& title, const string& director, const int nScenes)
{



	DVD* item = new DVD(title, director, nScenes);

	allDVDs.insert(item);

	return item;

}
/**
* Library: add cast members to movies
* in: movie, member
* out: none
* return: none
**/
void Library::addCastMember(const Item* const movie, const string& member)
{


	((DVD*) movie)->addCast(member);	


}

/**
* Library: add and return all movies by a certain director
* in: director
* out: none
* return: allmoviesbydirector
**/
const ItemSet* Library::moviesByDirector(const string& director) const
{

	for (ItemSet::const_iterator i = this->allDVDs.begin(); i != this->allDVDs.end(); ++i)
	{
		if(((DVD*) *i)->getDirector() == director)
		{
			allmoviesByDirector->insert(*i);

		}


	}

	return  allmoviesByDirector;

}
/**
* Library: search and add all movies by a certain actor
* in: actor
* out: none
* return: allmoviesbyactor
**/
const ItemSet* Library::moviesByActor(const string& actor) const
{

	const StringSet* search_a;




	for (ItemSet::const_iterator i = this->allDVDs.begin(); i != this->allDVDs.end(); ++i)
	{

		search_a = (((DVD*) *i)->getCast());

		if((search_a->find(actor)) != search_a->end())
		{

			allmoviesByActor->insert(*i);

		}

	}

	return  allmoviesByActor;

}

/**
* Library: retuen all movies
* in: none
* out: none
* return: alldvds
**/
const ItemSet* Library::movies() const
{
	return &allDVDs;
}	

/**
* Library: Destructor
* in: none
* out: none
* return: none
**/
Library::~Library()
{



	delete allKeywords;
	delete allMusicByBand;

	delete allMusicByMusician;
	delete allmoviesByDirector;
	delete allmoviesByActor;
	delete allBooksByAuthor;


	Purge(allBooks);
	Purge(allCDS);
	Purge(allDVDs);


}

/**
* Library: destructor function for removing memory in the sets
* in: itemset
* out: none
* return: item
**/
void Library::Purge(ItemSet &set)
{
	for (ItemSet::iterator it = set.begin(); it != set.end(); ++it)
		delete *it;
	set.clear(); 
}


