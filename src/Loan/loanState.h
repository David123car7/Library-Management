#pragma once
#include <iostream>
#include <string>

enum class LoanState{
	toPickUp,
	loaned,
	finished,
};

std::ostream& operator<<(std::ostream& out, LoanState state);

LoanState StringToLoanState(std::string& value);


