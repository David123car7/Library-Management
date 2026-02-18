#pragma once
#include <ostream>

/**
 * @brief Represents the outcome of library operations (e.g., borrowing, returning).
 */
enum class Result{
	Sucess,
	UserNull,
	UserBanned,
	UserNotRemoved,
	BookNotRemoved,
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
