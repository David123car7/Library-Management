#pragma once
#include <iostream>

enum class LoanState{
	toPickUp,
	loaned,
	finished,
};

std::ostream& operator<<(std::ostream& out, LoanState state);
