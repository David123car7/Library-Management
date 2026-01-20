#pragma once

#include "bookGenre.h"
#include "bookState.h"
#include "../Date/date.h"
#include <string>
#include <iostream>

class Book {
	private:
	int id;
	std::string name;
	std::string author;
	Date releaseDate;
	BookGenre genre;
	BookState state;
	
	public:
	Book(int id, std::string name, std::string author, Date& releaseDate, BookGenre genre, BookState state);
	
	int GetId() const {return id;}
	const std::string& GetName() const {return name;}
	const std::string& GetAuthor() const {return author;}
	const Date& GetRealeaseDate() const {return releaseDate;}
	BookGenre GetGenre() const {return genre;}

	int SetName(const std::string& name);
	int SetAuthor(const std::string& author);
	void SetReleaseDate(const Date& date);
	void SetGenre(const BookGenre genre);
	void SetState(const BookState state);

	friend std::ostream& operator<<(std::ostream& out, Book& book){
		return out << book.id << " " << book.name << " " << book.author << " " << book.releaseDate << " " << book.genre << " " << book.state;	
	}

	~Book(){}
};
