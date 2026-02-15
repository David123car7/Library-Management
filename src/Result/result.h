#pragma once
#include <ostream>

enum class Result{
	Sucess,
	UserNull,
	UserBanned,
	UserNotRemoved,
	BookNull,
	LoanNull,
	LoansMaxReached,
	BookNotAvailable,
	InvalidDate,
	LoanFinished,
	LoanPickedUp,
	LoanNotPickedUp,
	LoansEmpty,
};

std::ostream& operator<<(std::ostream& out, Result result);
