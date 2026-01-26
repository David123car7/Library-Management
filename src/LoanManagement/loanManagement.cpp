#include "loanManagement.h"

using namespace std;

int LoanManagement::Add(unsigned int bookId, unsigned int userId, const Date& startDate, const Date& endDate, LoanState state){
	int id;
	if(loans.empty()) id = 0;
	else{
		auto it = loans.crbegin();
		id = it->first;
		id++;
	}
	Loan loan(id, bookId, userId, startDate, endDate, state);
	loans[id] = loan;
	return id;
}

int LoanManagement::Remove(unsigned int id){
	if(!loans.contains(id)) return 0;
	loans.erase(id);
	return 1;
}

Loan* LoanManagement::GetLoan(unsigned int id){
	if(!loans.contains(id)) return nullptr;
	return &loans.at(id);
}

const Loan* LoanManagement::GetLoan(unsigned int id) const{
	if(!loans.contains(id)) return nullptr;
	return &loans.at(id);
}

bool LoanManagement::LoanExists(unsigned int id){
	if(!loans.contains(id)) return false;
	else return true;
}

void LoanManagement::PrintLoans(){
	for(auto& [key, loan]: loans){
		cout << loan << "\n";
	}
}

