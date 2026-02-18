#pragma once

#include <ostream>
#include <string>

/**
* @brief Represents the state of a book
*/
enum class BookState{
	available,
	notAvailable,
	noState
};

/**
* @brief Overloads the stream insertion operator to print the BookState.
*
* @param[in,out] out       The output stream to write to.
* @param[in]     bookState The BookState value to be printed.
* @return A reference to the modified output stream to allow chaining.
*/
std::ostream& operator<<(std::ostream& out, BookState bookState);

/**
 * @brief Converts a string to book state
 *
 * @param[in] value Reference to a string 
 * @return The book state converted from a string 
 * @throws invalid_argument if the string is not a valid BookState
 */
BookState StringToBookState(std::string& value);

