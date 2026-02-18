#pragma once
#include <iostream>
#include <string>

enum class LoanState{
	toPickUp,
	loaned,
	finished,
};

std::ostream& operator<<(std::ostream& out, LoanState state);

/**
 * @brief Converts a string to a Loan State
 *
 * @param[in] value Reference to a string 
 * @return loan state converted from a string 
 * @throws invalid_argument If the string was not a valid loan state
 */
LoanState StringToLoanState(std::string& value);


