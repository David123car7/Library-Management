#pragma once

#include "bookGenre.h"
#include "bookState.h"
#include "../Date/date.h"
#include <string>
#include <iostream>

/**
 * @brief Class that represents a book 
 **/
class Book {
	private:
	unsigned int id;
	std::string name;
	std::string author;
	Date releaseDate;
	BookGenre genre;
	BookState state;
	
	public:
	Book(): id{0}, name{""}, author{""}, releaseDate{}, genre{BookGenre::noGenre}, state{BookState::noState} {}

	/**
	* @brief Constructs a new Book object.
	*
	* @param[in] id          The unique identifier for the book.
	* @param[in] name        The title of the book.
	* @param[in] author      The name of the author.
	* @param[in] releaseDate The publication date of the book.
	* @param[in] genre       The genre or category of the book.
	* @param[in] state       The initial state of the book..
	*/
	Book(unsigned int id, std::string name, std::string author, Date& releaseDate, BookGenre genre, BookState state):
		id{id},
		name{name},
		author{author},
		releaseDate{releaseDate},
		genre{genre},
		state{state}{}

	
	int GetId() const {return id;}
	const std::string& GetName() const {return name;}
	const std::string& GetAuthor() const {return author;}
	const Date& GetReleaseDate() const {return releaseDate;}
	BookGenre GetGenre() const {return genre;}
	BookState GetState() const {return state;}

	int SetName(const std::string& name);
	int SetAuthor(const std::string& author);
	void SetReleaseDate(const Date& date);
	void SetGenre(const BookGenre genre);
	void SetState(const BookState state);

	/**
	* @brief Overloads the stream insertion operator to print the Book's details.
	*
	* Outputs the book information in the following order:
	* ID Name Author ReleaseDate Genre State
	*
	* @param[in,out] out   The output stream to write to.
	* @param[in]     book  The Book object to be printed.
	* @return A reference to the modified output stream.
	*/
	friend std::ostream& operator<<(std::ostream& out, const Book& book){
		return out << book.id << " | " << book.name << " | " << book.author << " | " << book.releaseDate << " | " << book.genre << " | " << book.state;	
	}
};
