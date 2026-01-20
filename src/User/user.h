#pragma once

#include <iostream>
#include "../Person/person.h"
#include <string>

class User: public Person{
	private:
	std::string phoneNumber;
	std::string email;

	public:
	User(int id, std::string name, std::string gender, int age, std::string phoneNumber, std::string email);

	const std::string& GetPhoneNumber() const {return phoneNumber;}
	const std::string& GetEmail() const {return email;}
	int SetEmail(std::string email);
	int SetPhoneNumber(std::string phoneNumber);
	bool IsUserValid(User user);
    	
	friend std::ostream& operator<<(std::ostream& out, const User& user){
		return out << user.GetId() << " " << user.GetName() << " " << user.GetGender() << " " << user.GetAge() << " " << user.phoneNumber << " " << user.email;
	}

	~User() {}
};
