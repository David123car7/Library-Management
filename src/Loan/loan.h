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
	Loan(unsigned int id, unsigned int bookId, unsigned int userId, const Date& startDate, const Date& endDate, LoanState state):
		id{id},
		bookId{bookId},
		userId{userId},
		startDate{startDate},
		endDate{endDate},
		deliveredDate{},
		state{state}{}

	Loan(unsigned int id, unsigned int bookId, unsigned int userId, const Date& startDate, const Date& endDate, const Date& deliveredDate, LoanState state):
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
	const Date& GetDeliveredDate() const {return deliveredDate;}
	LoanState GetState() const {return state;}

	void SetState(LoanState state) { this->state = state;}
	void SetDeliveredDate(const Date& deliveredDate) {this->deliveredDate = deliveredDate;}

	friend std::ostream& operator<<(std::ostream& out, const Loan& loan){
		return out << loan.id << " | " << loan.userId << " | " << loan.bookId << " | " << loan.startDate << " | " << loan.endDate << " | " << loan.deliveredDate << " | " << loan.state;
	}
};
