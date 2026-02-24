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
	
	/**
	 * @brief Adds a book to the map
	 *
	 * @param[in] book Reference to a book object 
	 * @return 0 if a book with the same id allready exists
	 * 1 if the book was added
	 * */
	int Add(const Book& book);

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
	 * @brief Stores all books in a csv file
	 *
	 * @return 0 if the data was not saved
	 * 1 if the data was saved
	 */
	int StoreDataInFile();
	int StoreDataInFile(std::string fileName);

	/**
	 * @brief Reads books data from a csv file
	 *
	 * @return 0 if the data was not read
	 * 1 if the data was read and load sucessfuly
	 */
	int ReadDataFromFile();
	int ReadDataFromFile(std::string fileName);

	/**
	 * @brief Prints all books
	 *
	 */
	void PrintBooks();

	/**
	 * @brief Prints a book
	 *
	 * @param[in] id Book Id 
	 * @return 0 if the book does not exist,
	 * 1 if the book was printed
	 */
	int PrintBook(unsigned int id);
};
