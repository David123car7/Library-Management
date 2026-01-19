#pragma once

#include <iostream>
#include "../Person/person.h"
#include <string>

class User: public Person{
	private:
	int id;
	std::string phoneNumber;
	std::string email;

	public:
	User(): id{0}, phoneNumber{""}, email{""} {}
	User(int id, std::string name, std::string gender, int age, std::string phoneNumber, std::string email): 
		Person(id, name, gender, age),
		id{id},
		phoneNumber{phoneNumber},
		email{email}{}
	
	const int GetId() const {return id;}
	const std::string& GetPhoneNumber() const {return phoneNumber;}
	const std::string& GetEmail() const {return email;}
	int SetEmail(std::string email);
	int SetPhoneNumber(std::string phoneNumber);
	bool IsUserValid(User user);


	~User() {std::cout << "\n" << "User Destructed";}
};
