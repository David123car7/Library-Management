#include "user.h"

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
