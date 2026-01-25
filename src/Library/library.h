#pragma once

#include "../UserManagement/userManagement.h"
#include "../LoanManagement/loanManagement.h"
#include "../BookManagement/bookManagement.h"
#include "../Result/result.h"

class Library{
	private:
	UserManagement usersManagement;
	BookManagement booksManagement;
	LoanManagement loansManagement;
	
	/**
	 * @brief Does the user check in by checking the user state, if it is banned
	 * will check if the ban expire date has passed if passed the user will be unbanned
	 *
	 * @param[in] user Reference to a user object
	 * @param[in] currentDate Current date
	 * @return Result::UserNull if the user does not exist
	 * Result::UserBanned if the user is banned
	 * Result::Sucess if the user is active
	 */
	Result CheckInUser(User& user, const Date& currentDate);
	
	/**
	 * @brief Checks if the user can loan a book
	 *
	 * @param[in] user Reference to a user object
	 * @return Result::UserNull if the user does no exist
	 * Result::LoansMaxReached if the user reached the max of loans
	 * Result::UserBanned if the user is banned
	 * Result::Sucess if the user is active
	 */
	Result CanUserLoan(const User& user);

	/**
	 * @brief Checks if the book is available
	 *
	 * @param[in] bookId Book Id
	 * Result::BookNotAvailable if the books is not available,
	 * Result::Sucess if the book is available
	 */
	Result IsBookAvailable(const Book& book);

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
	Result CreateLoan(unsigned int bookId, unsigned int userId,const Date& currentDate, const Date& startDate, const Date& endDate);
	int FinishLoan(unsigned int loanId, const Date& deliveredDate);

	/**
	 * @brief Checks if the book is available
	 *
	 * @param[in] bookId Book Id
	 * @return Result::BookNull if book does not exist, 
	 * Result::BookNotAvailable if the books is not available,
	 * Result::Sucess if the book is available
	 */
	Result IsBookAvailable(unsigned int bookId);

	/**
	 * @brief Checks if the user can loan a book
	 *
	 * @param[in] userId User Id
	 * @return Result::UserNull if the user does no exist
	 * Result::LoansMaxReached if the user reached the max of loans
	 * Result::UserBanned if the user is banned
	 * Result::Sucess if the user is active
	 */
	Result CanUserLoan(unsigned int userId);
	
	/**
	 * @brief Does the user check in by checking the user state, if it is banned
	 * will check if the ban expire date has passed if passed the user will be unbanned
	 *
	 * @param[in] userId User Id
	 * @param[in] currentDate Current date
	 * @return Result::UserNull if the user does not exist
	 * Result:UserBanned if the user is banned
	 * Result::Sucess if the user is active
	 */
	Result CheckInUser(unsigned int userId, const Date& currentDate);
};
