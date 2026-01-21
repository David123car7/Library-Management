#include "loanManagement.h"

using namespace std;

int LoanManagement::Add(const Loan& loan){
	if(loans.contains(loan.GetId())) return 0;
	loans[loan.GetId()] = loan;
	return 1;
}

int LoanManagement::Remove(unsigned int id){
	if(!loans.contains(id)) return 0;
	loans.erase(id);
	return 1;
}

Loan* LoanManagement::GetLoan(unsigned int loanId){
	if(!loans.contains(loanId)) return nullptr;
	return &loans.at(loanId);
}

const Loan* LoanManagement::GetLoanReadOnly(unsigned int loanId){
	return GetLoan(loanId);
}

void LoanManagement::PrintLoans(){
	for(auto& [key, loan]: loans){
		cout << loan;
	}
}

