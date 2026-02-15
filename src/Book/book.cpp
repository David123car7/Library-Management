#include "book.h"
#include <stdexcept>
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

ostream& operator<<(ostream& out, BookGenre genre){
	switch(genre){
		case BookGenre::fantasy: return out << "Fantasy";
		case BookGenre::horror: return out << "Horror";
		case BookGenre::romance: return out << "Romance";
		case BookGenre::action: return out << "Action";
		default: return out << "Unknown_Genre";
	}
}

ostream& operator<<(ostream& out, BookState state){
	switch(state){
		case BookState::available: return out << "Available";
		case BookState::notAvailable: return out << "Not_Available";
		default: return out << "Unknown_Genre";
	}
}

istream& operator>>(istream& in, BookGenre& genre) {
    std::string token;
    in >> token; 

    if (token == "Fantasy")      genre = BookGenre::fantasy;
    else if (token == "Horror")  genre = BookGenre::horror;
    else if (token == "Romance") genre = BookGenre::romance;
    else if (token == "Action")  genre = BookGenre::action;
    else {
        in.setstate(std::ios::failbit);
    }
    return in;
}

BookState StringToBookState(string& value){
	if(value == "Available") return BookState::available;
	else if(value == "Not_Available") return BookState::notAvailable;
	else throw invalid_argument("Invalid BookState: " + value);
}

BookGenre StringToBookGenre(string& value){
	if(value == "Fantasy") return BookGenre::fantasy;
	if(value == "Horror") return BookGenre::horror;
	if(value == "Romance") return BookGenre::romance;
	if(value == "Action") return BookGenre::action;
	else throw invalid_argument("Invalid BookGenre: " + value);
}

void DisplayBookGenreOptions(){

}



