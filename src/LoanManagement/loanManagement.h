#pragma once
#include <vector>
#include <map>
#include "../Loan/loan.h"

class LoanManagement{
	private:
	std::map<unsigned int, Loan> loans;
	std::map<unsigned int, std::vector<unsigned int>> loansUserMap; //map that holds the loan ids related to a user

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
	 * @brief Checks if there is a key in the user map
	 *
	 * @param[in] key User Id
	 * @return 0 if it does not exist,
	 * 1 if it does exist
	 */
	bool ExistsKeyUserMap(unsigned int key);

	/**
	 * @brief Checks if a loan id associated with a given key exists in the user map
	 *
	 * @param[in] key User Id 
	 * @param[in] id Loan Id
	 * @return true if the loan id exists
	 * false if the loan id does not exist in the associated key
	 */
	bool LoanIdUserMapExists(unsigned int key, unsigned int id);

	/**
	 * @brief Gets the size of the vector assosiated with the key in the user map
	 *
	 * @param[in] key User Id
	 * @return -1 if the key does not exist,
	 * the length of the vector assosiated with the key
	 */
	int GetUserMapSize(unsigned int key);

	/**
	 * @brief Gets the loan ids associated with a given key
	 *
	 * @param[in] key User Id
	 */
	const std::vector<unsigned int>* GetUserLoanIds(unsigned key);

	/**
	 * @brief Adds a loan id to the user map
	 *
	 * @param[in] key User Id 
	 * @param[in] id Loan Id 
	 * @return 1 if the loan id was added
	 * 0 if the loan id allready exists
	 */
	int AddIdUserMap(unsigned int key, unsigned int id);

	/**
	 * @brief Removes a loan id drom the user map
	 *
	 * @param[in] key User Id 
	 * @param[in] id Loan Id 
	 * @return 1 if the loan id was removed
	 * 0 if the loan id does not exist
	 */
	int RemoveIdUserMap(unsigned int key, unsigned int id);

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

	/**
	 * @brief Prints loan
	 * @param [in] ud Loan Id
	 */
	int PrintLoan(unsigned int id);

	int PrintUserLoans(unsigned int userId);
};
