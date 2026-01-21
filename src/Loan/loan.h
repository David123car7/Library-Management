#pragma once

#include "../Date/date.h"
#include "loanState.h"

class Loan{
	private:
	unsigned int id;
	unsigned int bookId;
	unsigned int userId;
	Date startDate; 
	Date endDate;
	Date deliveredDate;
	LoanState state;	

	public:
	
	/**
	* @brief Starts the loan by changing the book state to loaned.
	*
	* @param[in] currentDate The current date when the function is called.
	* @return 0 if the current date is greater than the end date of the loan.
	* 1 if the loan state is changed successfully.
	*/
	Loan(unsigned int id, unsigned int bookId, unsigned int userId, Date& startDate, Date& endDate, Date& deliveredDate, LoanState state):
		id{id},
		bookId{bookId},
		userId{userId},
		startDate{startDate},
		endDate{endDate},
		deliveredDate{deliveredDate},
		state{state}{}

	/**
	* @brief Starts the loan by changing the book state to loaned.
	*
	* @param[in] currentDate The current date when the function is called.
	* @return 0 if the current date is greater than the end date of the loan.
	* 1 if the loan state is changed successfully.
	*/
	int StartLoan(Date& currentDate);
	
	/**
	* @brief Finishes the loan by changing the loan state to finished.
	*
	* @param[in] currentDate The current date when the function is called
	* @return -1 if the current date is greater than the endDate
	* 1 if the current date is lesser than the endDate 
	* (In all cases the loan state is changed)
	*/
	int FinishLoan(Date& currentDate);
};
