#pragma once
#include <ostream>

enum class Result{
	Sucess,
	UserNull,
	UserBanned,
	BookNull,
	LoanNull,
	LoansMaxReached,
	BookNotAvailable,
	InvalidDate,
	LoanFinished,
};

std::ostream& operator<<(std::ostream& out, Result result);
