#pragma once

#include <ostream>

/**
* @brief Represents the state of a book..
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


