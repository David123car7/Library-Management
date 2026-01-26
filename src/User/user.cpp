#include "user.h"
#include <string>

using namespace std;

int User::SetPhoneNumber(string phoneNumber){
	if(phoneNumber.length() == 0) return 0;
	this->phoneNumber = phoneNumber;
	return 1;
}

int User::SetEmail(string email){
	if(email.length() == 0) return 0;
	this->email = email;
	return 1;
}

bool User::CheckLoanIdExists(uint8_t id){
	for(unsigned int i=0; i<currentLoans.size(); i++){
		if(currentLoans[i] == id)
			return true;
	}
	return false;
}

int User::AddLoanId(uint8_t id){
	if(CheckLoanIdExists(id)) return 0;
	currentLoans.push_back(id);
	return 1;
}

int User::RemoveLoanId(uint8_t id){
	for(unsigned int i=0; i<currentLoans.size(); i++){
		if(currentLoans[i] == id){
			currentLoans[i] = currentLoans.back();
			currentLoans.pop_back();
			return 1;
		}
	}
	return 0;
}

ostream& operator<<(ostream& out, UserState state){
	switch(state){
		case UserState::active: return out << "Active";
		case UserState::banned: return out << "Banned";
		default: return out << "Unknown";
	}
}
