#pragma once

#include <ostream>

enum class BookState{
	available,
	notAvailable
};

std::ostream& operator<<(std::ostream& out, BookState& bookState);


