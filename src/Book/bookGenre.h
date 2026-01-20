#pragma once

#include <iostream>

enum class BookGenre{
	fantasy,
	horror,
	romance,
	action
};

std::ostream& operator<<(std::ostream& out, BookGenre& genre);


