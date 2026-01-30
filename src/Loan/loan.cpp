#include "loan.h"
#include <stdexcept>
#include <ostream>

using namespace std;

ostream& operator<<(ostream& out, LoanState state){
	switch(state){
		case LoanState::toPickUp: return out << "ToPickUp";
		case LoanState::loaned: return out << "Loaned";
		case LoanState::finished: return out << "Finished";
		default: return out << "Unknown_State";
	}
}

LoanState StringToLoanState(string& value){
	if(value == "ToPickUp") return LoanState::toPickUp;
	else if(value == "Loaned") return LoanState::loaned;
	else if(value == "Finished") return LoanState::finished;
	else throw invalid_argument("Invalid Loan State: " + value);
}
