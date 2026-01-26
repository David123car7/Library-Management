#include "book.h"
#include "../Utils/utils.h"
#include <stdexcept>

using namespace std;

int Book::SetName(const string& name){
	if(name.empty()) return 0;
	this->name = name;
	return 1;
}

int Book::SetAuthor(const string& author){
	if(author.empty()) return 0;
	this->author = author;
	return 1;
}

void Book::SetGenre(BookGenre genre){
	this->genre = genre;
}

void Book::SetReleaseDate(const Date& date){
	releaseDate = date;
}

void Book::SetState(BookState state){
	this->state = state;
}

ostream& operator<<(ostream& out, BookGenre& genre){
	switch(genre){
		case BookGenre::fantasy: return out << "Fantasy";
		case BookGenre::horror: return out << "Horror";
		case BookGenre::romance: return out << "Romance";
		case BookGenre::action: return out << "Action";
		default: return out << "Gnknown Genre";
	}
}

ostream& operator<<(ostream& out, BookState& genre){
	switch(genre){
		case BookState::available: return out << "Available";
		case BookState::notAvailable: return out << "Not Available";
		default: return out << "unknown genre";
	}
}




