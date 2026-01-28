#pragma once

#include "../Book/book.h"
#include <map>
#include <vector>

/**
 * @brief Class responsible to manage books.
 * All books are inside a map where the key is the year of the book and the value is a vector of Book
 */
class BookManagement{
	private:
	std::map<unsigned int, Book> books;

	public:
	
	/** 
	 * @brief Adds a book to the map
	 *
	 * @param[in] book Book Object
	 * @return The id of the book added
	 */
	int Add(std::string name, std::string author, Date& releaseDate, BookGenre genre, BookState state);

	/**
	 * @brief Removes a book from the map
	 * *
	 * @param[in] id Book Id
	 * @return returns 1 if the book was h
	 * returns 0 if the book did not exist
	 */
	int Remove(unsigned int id);
	
	/**
	 * @brief Checks if a book with the id exists
	 *
	 * @param[in] id Book Id
	 * @return true if exists false if does not exist
	 */
	bool BookExists(unsigned int id);

	/**
	 * @brief Gets the book
	 * @param[in]] id Book Id
	 */
	Book* GetBook(unsigned int id);

	/**
	 * @brief Gets the book
	 * @param[in] id Book Id
	 */
	const Book* GetBook(unsigned int id) const;

	/**
	 * @brief Gets the quantity if books
	 *
	 * @return the quantity of the book
	 */
	int GetBooksQnt();
	
	/**
	 * @brief Gets the quantity of available books
	 *
	 * @return the quantity of available books
	 */
	int GetAvailableBooksQnt();
	
	/**
	 * @brief Gets the quantity of not available books
	 *
	 * @return the quantity of not available books
	 */
	int GetNotAvailableBooksQnt();

	/**
	 * @brief Prints all books
	 *
	 */
	void PrintBooks();

	int PrintBook(unsigned int id);
};
