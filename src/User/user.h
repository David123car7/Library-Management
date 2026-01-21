#pragma once

#include <iostream>
#include "../Person/person.h"
#include <string>

class User: public Person{
	private:
	std::string phoneNumber;
	std::string email;

	public:
	/**
	 * @brief Constructor for the user
	 *
	 * @param[in] id Person Id
	 * @param[in] name Person Name
	 * @param[in] gender Person Gender
	 * @param[in] age Person Age
	 * @param[in] phoneNumber Phone Number
	 * @param[in] email Person Email
	 */
	User(unsigned int id, std::string name, std::string gender, int age, std::string phoneNumber, std::string email);

	const std::string& GetPhoneNumber() const {return phoneNumber;}
	const std::string& GetEmail() const {return email;}
	int SetEmail(std::string email);
	int SetPhoneNumber(std::string phoneNumber);
    	
	friend std::ostream& operator<<(std::ostream& out, const User& user){
		return out << user.GetId() << " " << user.GetName() << " " << user.GetGender() << " " << user.GetAge() << " " << user.phoneNumber << " " << user.email;
	}

};
