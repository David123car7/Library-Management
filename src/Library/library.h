#pragma once

#include "../UserManagement/userManagement.h"
#include "../LoanManagement/loanManagement.h"
#include "../BookManagement/bookManagement.h"
#include "../Result/result.h"
#include "../Constants/constants.h"

class Library{
	private:
	UserManagement usersManagement;
	BookManagement booksManagement;
	LoanManagement loansManagement;
	LoanManagement loansHistoryManagement;

	/**
	 * @brief Gets the user, loan and book related to a loan
	 *
	 * @param[[TODO:direction]] loanId Loan Id
	 * @param[in] user Reference to the User Object
	 * @param[in] loan Reference to the Loan Object
	 * @param[in] book Reference to the Book Object
	 * @return Result::UserNull if the user related to the loan does not exist,
	 * Result::BookNull if the book related to the loan does not exist,
	 * Result::LoanNull if the loan does not exist
	 * Result::Sucess if all objects were retrieved sucesseful
	 */
	Result GetLoanContext(unsigned int loanId, User*& user, Loan*& loan, Book*& book);

	/**
	 * @brief Applys the penalty to a user by banning the user for a period of time
	 *
	 * @param[in] user User Id
	 * @param[in] date Date the penalty starts 
	 * */
	void ApplyPenalty(User& user, const Date& date);

	/**
	 * @brief Loans the book
	 *
	 * @param[in] loan Reference to the Loan Object
	 */
	void LoanBook(Loan& loan);

	/**
	 * @brief Deactivates the loan
	 *
	 * @param[in] loan Reference to the Loan object
	 * @param[in] user Reference to the User object
	 * @param[in] book Reference to the Book object
	 * @param[in] date Date the loan was deactivated 
	 */
	void DeactivateLoan(Loan& loan, User& user, Book& book, const Date& date);

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
	 * @brief Bans the user temporary
	 *
	 * @param[in] user Reference to a user object
	 * @param[in] startDate Date that the ban starts 
	 * @return Result::UserBanned if the user is allready banned,
	 * Result::Sucess if the user was banned sucessefuly
	 */
	Result BanUser(User& user, const Date& startDate);

	public:
	int AddUser(const std::string& name, const std::string& gender, int age, const std::string& email, const std::string& phoneNumber){
		return usersManagement.Add(name, gender, age, email, phoneNumber);
	}	
	Result RemoveUser(unsigned int id);

	int AddBook(std::string name, std::string author, Date& releaseDate, BookGenre genre, BookState state){
		return booksManagement.Add(name, author, releaseDate, genre, state);
	}
	Result RemoveBook(unsigned int bookId);

	/**
	 * @brief Adds a loan
	 *
	 * @param[in] bookId Book Id
	 * @param[in] userId User Id 
	 * @param[in] startDate Start Date
	 * @param[in] endDate End Date
	 * @return Result::BookNull if the book did not exist,
	 * Result::BookNotAvailable if the book was not available,
	 * Result::UserNull if the user did not exist,
	 * Result::InvalidDate if the end date is higher than the start date
	 * Result::LoansMaxReached if the user has reached the max loans
	 * Result:Sucessful if the loan was added sucessufly
	 */
	Result CreateLoan(unsigned int bookId, unsigned int userId,const Date& currentDate, const Date& startDate, const Date& endDate);

	/**
	 * @brief Called when a user picks the book he loaned
	 *
	 * @param[in] loanId Loan Id
	 * @param[in] pickedUpDate Date the book was picked 
	 * @return Result::LoanNull if the loan does not exist,
	 * Result::UserNull if the user associated with the loan does not exist,
	 * Result::BookNull if the user associated with the loan does not exist,
	 * Result::LoanNotPickedup if the pickedUpDate is greater than the end date of the loan 
	 * Result::Sucess if the book was picked
	 */
	Result PickupLoan(unsigned int loanId, const Date& pickedUpDate);

	/**
	 * @Finishes the loan 
	 *
	 * @param[in] loanId Loan Id 
	 * @param[in] deliveredDate Date that the book was delivered
	 * @return Result::LoanNull if the loan did not exist
	 * Result::BookNull if the book associated with the loan did not exist
	 * Result::UserNull if the user associated with the loan did not exist
	 * Result::LoanAllreadyFinished if the loan was allready finished
	 */
	Result FinishLoan(unsigned int loanId, const Date& deliveredDate);

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

	/**
	 * @brief Bans the user temporary
	 *
	 * @param[in] userId User Id
	 * @param[in] startDate Date that the ban starts 
	 * @return Result::UserBanned if the user is allready banned,
	 * Result::UserNull if the user does not exist,
	 * Result::Sucesseful if the user was banned sucessefuly
	 */
	Result BanUser(unsigned int userId, const Date& startDate);

	void OpenLibrary();
	void CloseLibrary();

	void PrintBooksQnt();
	void PrintAvailableBooksQnt();
	void PrintNotAvailableBooksQnt();

	int PrintUser(unsigned int userId){
		return usersManagement.PrintUser(userId);
	}

	int PrintBook(unsigned int bookId){
		return booksManagement.PrintBook(bookId);
	}

	int PrintLoan(unsigned int loanId){
		return loansManagement.PrintLoan(loanId);
	}

	/**
	 * @brief Prints all books
	 *
	 */
	void PrintBooks(){
		PrintBookColumns();
		booksManagement.PrintBooks();
	}
	
	/**
	 * @brief Prints all active loans
	 *
	 */
	void PrintLoans(){ 
		PrintLoanColumns();
		loansManagement.PrintLoans();
	}

	/**
	 * @brief Prints past loans
	 *
	 */
	void PrintHistoryLoans(){ 
		PrintLoanColumns();
		loansHistoryManagement.PrintLoans();
	}
	
	/**
	 * @brief Prints all users
	 *
	 */
	void PrintUsers(){
		PrintUserColumns();
		usersManagement.PrintUsers();
	}
	
	/**
	 * @brief Prints all loans associated with a user
	 *
	 * @param[in] userId User Id 
	 * @return Result::UserNull if the user does not exist,
	 * Result::Sucess if the loans were printed sucesseful
	 */
	Result PrintUserLoans(unsigned int userId);	
	
	/**
	 * @brief Prints the books being loaned to a user 
	 *
	 * @param[in] userId User Id
	 * @return Result::UserNull if the user does not exist,
	 * Result::Sucess if the books were printed sucesseful
	 */
	Result PrintBooksUserLoans(unsigned int userId);

	void PrintUserColumns(){
		std::cout << "ID" " | " << " | " << "NAME" << " | " << "GENDER" << " | " << "AGE" << " | " << 
			"PHONE NUMBER" << " | " << "EMAIL" << " | " << "STATE" << " | " << "OCCURRENCES" <<
			" | " << "BAN EXPIRE DATE" << "\n";
	}
	void PrintBookColumns(){
		std::cout << "ID" << " | " << "NAME" << " | " << "AUTHOR" << " | " << "DATE" << " | " << "GENRE" << "\n";
	}
	void PrintLoanColumns(){
		std::cout << "ID" << " | " << "USER ID" << " | " << "BOOK ID" << " | " << "START DATE" << " | "
			"END DATE" << " | " << "DELIVERED DATE" << " | " << "STATE" << "\n";
	}
};
