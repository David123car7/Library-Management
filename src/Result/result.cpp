#include "result.h"

using namespace std;

ostream& operator<<(ostream& out, Result result){
	switch(result){
		case Result::Sucess: return out << "Executed Sucessufly";
		case Result::UserNull: return out << "User does not exist";
		case Result::BookNull: return out << "Book does not exist";
		case Result::LoanNull: return out << "Loan does not exist";
		case Result::UserBanned: return out << "User is banned";
		case Result::LoansMaxReached: return out << "User reached the max of loans";
		case Result::BookNotAvailable: return out << "Book is not available";
		case Result::InvalidDate: return out << "The date is invalid";
		case Result::LoanFinished: return out << "The loan is allready finished";
		case Result::LoanPickedUp: return out << "Th loan was allready picked up";
		case Result::LoanNotPickedUp: return out << "The loan was not picked up";
		default: return out << "Unknown Result";
	}
}

