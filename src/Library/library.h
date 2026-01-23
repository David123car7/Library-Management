#pragma once

#include "../UserManagement/userManagement.h"
#include "../LoanManagement/loanManagement.h"
#include "../BookManagement/bookManagement.h"

class Library{
	private:
	UserManagement usersManagement;
	BookManagement booksManagement;
	LoanManagement loansManagement;
	
	public:
	void AddUser(std::string name, std::string gender, int age, std::string email, std::string phoneNumber){
		usersManagement.Add(name, gender, age, email, phoneNumber);
	}
	int RemoveUser(unsigned int id){
		return usersManagement.Remove(id);
	}

	/**
	 * @brief Adds a loan
	 *
	 * @param[in] bookId Book Id
	 * @param[in] userId User Id 
	 * @param[in] startDate Start Date
	 * @param[in] endDate End Date
	 * @return returns -1 if the book was not available or did not exist,
	 * returns -2 if the user does not exist,
	 * returns -3 if the end date is higher than the start date
	 * returns 1 if the loan was added sucessufly
	 */
	int CreateLoan(unsigned int bookId, unsigned int userId,const Date& currentDate, const Date& startDate, const Date& endDate);
	int FinishLoan(unsigned int loanId, const Date& deliveredDate);

	/**
	 * @brief Checks if the book is available
	 *
	 * @param[in] bookId Book Id
	 * @return -1 if the book does not exist, 
	 * 0 if the book is not available
	 * 1 if the book is available
	 */
	int IsBookAvailable(unsigned int bookId);

	/**
	 * @brief Checks if the user can loan a book
	 *
	 * @param[in] userId User Id
	 * @return -1 if the user does no exist
	 * -2 if the user reached the max of loans
	 * 0 if the user is banned
	 * 1 if the user is active
	 */
	int CanUserLoan(unsigned int userId);
};
