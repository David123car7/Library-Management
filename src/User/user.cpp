#include "user.h"
#include "../Utils/utils.h"
#include <stdexcept>
#include <string>

using namespace std;

User::User(unsigned int id, string name, string gender, int age, string phoneNumber, string email): 
	Person(id, name, gender, age),
	phoneNumber{phoneNumber},
	email{email}{	
	if(id <= 0) throw invalid_argument("Id must be greater than 0");
	if(email.empty() || isInvalidString(email)) throw invalid_argument("Email can not be empty");
	if(phoneNumber.empty() || isInvalidString(phoneNumber)) throw invalid_argument("PhoneNumber can not be empty!");
}

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


