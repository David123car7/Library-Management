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
	Loan(): id{0}, bookId{0}, userId{0}, startDate{}, endDate{}, deliveredDate{}, state{LoanState::toPickUp}{}
	Loan(unsigned int id, unsigned int bookId, unsigned int userId, Date& startDate, Date& endDate, LoanState state):
		id{id},
		bookId{bookId},
		userId{userId},
		startDate{startDate},
		endDate{endDate},
		deliveredDate{},
		state{state}{}

	Loan(unsigned int id, unsigned int bookId, unsigned int userId, Date& startDate, Date& endDate, Date& deliveredDate, LoanState state):
		id{id},
		bookId{bookId},
		userId{userId},
		startDate{startDate},
		endDate{endDate},
		deliveredDate{deliveredDate},
		state{state}{}


	int GetId() const {return id;}
	int GetBookId() const {return bookId;}
	int GetUserId() const {return userId;}
	const Date& GetStartDate() const {return startDate;}
	const Date& GetEndDate() const {return endDate;}
	LoanState GetState() const {return state;}

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

	friend std::ostream& operator<<(std::ostream& out, Loan& loan){
		return out << loan.id << " " << loan.userId << " " << loan.bookId << " " << loan.startDate 
			<< " " << loan.endDate << " " << loan.deliveredDate << " " << loan.state;
	}
};
