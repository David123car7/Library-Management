#pragma once
#include <iostream>

/**
* @brief Represents the literary genre of a book.
*/
enum class BookGenre{
	fantasy,
	horror,
	romance,
	action,
	noGenre,
};

/**
* @brief Overloads the stream insertion operator to print the BookGenre.
*
* @param[in,out] out   The output stream to write to.
* @param[in]     genre The BookGenre value to be printed.
* @return A reference to the modified output stream.
*/
std::ostream& operator<<(std::ostream& out, BookGenre genre);

/**
 * @brief Converts a string to Book Genre
 *
 * @param[in] value Reference to a String 
 * @return Book Genre converted from a string
 * @throws invalid_argument If the string is not a valid Book Genre
 */
BookGenre StringToBookGenre(std::string& value);

/**
 * @brief Displays all book genre options
 */
void DisplayBookGenreOptions();


