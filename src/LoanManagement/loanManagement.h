#pragma once
#include <vector>
#include <map>
#include "../Loan/loan.h"

class LoanManagement{
	private:
	std::map<unsigned int, Loan> loans;	
	
	public:
	/**
	 * @brief Addes a book to the loan map
	 *
	 * @param[in] bookId Book Id
	 * @param[in] userId User Id
	 * @param[in] startDate Start Date
	 * @param[in] endDate End Date
	 * @param[in] state Loan State
	 * @return The id of the Loan added
	 */
	int Add(unsigned int bookId, unsigned int userId, const Date& startDate, const Date& endDate, LoanState state);
	/**
	 * @brief Removes a loan from the loan map
	 *
	 * @param[in] id Loan Id
	 * @return 1 if loan was removed
	 * 0 if loan did no exist
	 */
	int Remove(unsigned int id);

	Loan* GetLoan(unsigned int id);
	const Loan* GetLoanReadOnly(unsigned int id);
	
	bool LoanExists(unsigned int id);

	void PrintLoans();
};
