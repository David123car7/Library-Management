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
	std::map<int16_t, std::vector<Book>> books;

	public:
	
	/** 
	 * @brief Adds a book to the map
	 *
	 * @param[in] book Book Object
	 */
	void Add(const Book& book);

	/**
	 * @brief Removes a book from the map
	 * *
	 * @param[in] year Book Release Year
	 * @param[in] id Book Id
	 * @return returns 1 if the book was h
	 * returns 0 if the book did not exist
	 */
	int Remove(int16_t year, int id);
	

	/**
	 * @brief Gets the book
	 *
	 * @param[in] year Book Release Year 
	 * @param[in]] id Book Id
	 */
	Book* GetBook(int16_t year, int id);
	const Book* GetBookReadOnly(int16_t year, int id);
	void PrintBooks();
};
