#ifdef _WIN32
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif
#include <iostream>
#include "Library.h"
using namespace std;
static Library *library;
static void printItemSet(ostream& out, const ItemSet *itemSet)
{
if (itemSet != NULL && itemSet->size() > 0)
for (ItemSet::const_iterator i = itemSet->begin(); i != itemSet->end(); i++)
library->printItem(out, (Item *) *i);
else
out << "none" << endl << endl;
}
int main(int argc, char **argv)
{
ostream&	out(cout);
const Item	*item;
cout << "Library Database \n" << endl;
// create library instance
library = new Library();
// add items to library
cout << ">>> adding items to library:\n\n";
item = library->addBook("The Curious Incident of the Dog in the Night-Time", "Mark Haddon", 240);
if (item != NULL) {
library->addKeywordForItem(item, "autism");
library->addKeywordForItem(item, "Asperger's Syndrome");
library->printItem(cout, item);
}
item = library->addBook("Starship Troopers", "Robert A. Heinlein", 325);
if (item != NULL) {
library->addKeywordForItem(item, "science fiction");
library->addKeywordForItem(item, "war");
library->addKeywordForItem(item, "weapons");
library->printItem(cout, item);
}
item = library->addBook("The Moon Is A Harsh Mistress", "Robert A. Heinlein", 389);
if (item != NULL) {
library->addKeywordForItem(item, "science fiction");
library->addKeywordForItem(item, "moon");
library->addKeywordForItem(item, "social structures");
library->printItem(cout, item);
}
item = library->addMusicCD("Europe In '72", "Grateful Dead", 12);
if (item != NULL) {
library->addKeywordForItem(item, "acid rock");
library->addKeywordForItem(item, "sixties");
library->addKeywordForItem(item, "jam bands");
library->addBandMember(item, "Jerry Garcia");
library->addBandMember(item, "Bill Kreutzman");
library->addBandMember(item, "Keith Godcheaux");
library->printItem(cout, item);
}
item = library->addMusicCD("Don't Let Go", "Jerry Garcia Band", 15);
if (item != NULL) {
library->addKeywordForItem(item, "acid rock");
library->addKeywordForItem(item, "jam bands");
library->addBandMember(item, "Jerry Garcia");
library->addBandMember(item, "Keith Godcheaux");
library->printItem(cout, item);
}
item = library->addMusicCD("Sergeant Pepper's Lonely Hearts Club Band", "Beatles", 10);
if (item != NULL) {
library->addKeywordForItem(item, "acid rock");
library->addKeywordForItem(item, "sixties");
library->addBandMember(item, "John Lennon");
library->addBandMember(item, "George Harrison");
library->addBandMember(item, "Ringo Starr");
library->printItem(cout, item);
}
item = library->addMovieDVD("Lost In Translation", "Sofia Coppola", 14);
if (item != NULL) {
library->addKeywordForItem(item, "Japan");
library->addKeywordForItem(item, "loneliness");
library->addCastMember(item, "Bill Murray");
library->addCastMember(item, "Sofia Coppola");
library->printItem(cout, item);
}
item = library->addMovieDVD("Groundhog Day", "Harold Ramis", 14);
if (item != NULL) {
library->addKeywordForItem(item, "newscaster");
library->addKeywordForItem(item, "groundhog");
library->addKeywordForItem(item, "time");
library->addCastMember(item, "Bill Murray");
library->addCastMember(item, "Andie MacDowell");
library->printItem(cout, item);
}
// print books, musicCDs, movies
cout << ">>> books:\n\n";
printItemSet(out, library->books());
cout << ">>> music CDs:\n\n";
printItemSet(out, library->musicCDs());
cout << ">>> movies:\n\n";
printItemSet(out, library->movies());
// print items for keyword
cout << ">>> items for keyword \"science fiction\"\n\n";
printItemSet(out, library->itemsForKeyword("science fiction"));
cout << ">>> items for keyword \"jam bands\"\n\n";
printItemSet(out, library->itemsForKeyword("jam bands"));
cout << ">>> items for keyword \"xxx\"\n\n";
printItemSet(out, library->itemsForKeyword("xxx"));
// items for artist
cout << ">>> books by Robert A. Heinlein:\n\n";
printItemSet(cout, library->booksByAuthor("Robert A. Heinlein"));
cout << ">>> music by the Grateful Dead:\n\n";
printItemSet(out, library->musicByBand("Grateful Dead"));
cout << ">>> music by the Rolling Stones:\n\n";
printItemSet(out, library->musicByBand("Rolling Stones"));
cout << ">>> movies by Sofia Coppola:\n\n";
printItemSet(out, library->moviesByDirector("Sofia Coppola"));
cout << ">>> music by Jerry Garcia:\n\n";
printItemSet(out, library->musicByMusician("Jerry Garcia"));
cout << ">>> movies with Bill Murray:\n\n";
printItemSet(out, library->moviesByActor("Bill Murray"));
delete library;
// in Visual Studio, reports on memory leaks in the Output window
#ifdef _WIN32
_CrtDumpMemoryLeaks();
#endif
}
