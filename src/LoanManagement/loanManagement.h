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

	/**
	 * @brief Gets a loan
	 *
	 * @param[in] id Loan Id
	 * @return Returns a Loan pointer
	 */
	Loan* GetLoan(unsigned int id);

	/**
	 * @brief Gets loan
	 *
	 * @param[in] id Loan Id
	 * @return Returns a const Loan Pointer
	 */
	const Loan* GetLoan(unsigned int id) const;
	
	/**
	 * @brief Checks if the loan exists
	 *
	 * @param[in] id Loan Id
	 * @return true if the loan exists, 
	 * false if the loan does not exist
	 */
	bool LoanExists(unsigned int id);

	/**
	 * @brief Prints all loans
	 *
	 */
	void PrintLoans();
};
