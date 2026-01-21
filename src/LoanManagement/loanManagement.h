#pragma once
#include <vector>
#include <map>
#include "../Loan/loan.h"

class LoanManagement{
	private:
	std::map<unsigned int, Loan> loans;	
	std::map<unsigned int, Loan> finishedLoans;
	public:
	int Add(const Loan& loan);
	int Remove(unsigned int id);

	Loan* GetLoan(unsigned int loanId);
	const Loan* GetLoanReadOnly(unsigned int loanId);
	
	void PrintLoans();
};
