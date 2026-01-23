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

ostream& operator<<(ostream& out, UserState& state){
	switch(state){
		case UserState::active: return out << "Active";
		case UserState::banned: return out << "Banned";
		default: return out << "Unknown";
	}
}
