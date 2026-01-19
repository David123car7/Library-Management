#pragma once

#include <iostream>
#include "../Person/person.h"
#include <string>

class User: public Person{
	private:
	std::string phoneNumber;
	std::string email;

	public:
	User(): phoneNumber{""}, email{""} {}
	User(std::string phoneNumber, std::string email): phoneNumber{phoneNumber}, email{email} {}
	User(std::string name, std::string gender, int age): Person(name, gender, age) {}
	User(std::string name, std::string gender, int age, std::string phoneNumber, std::string email): 
		Person(name, gender, age),
		phoneNumber{phoneNumber},
		email{email}{}

	std::string GetPhoneNumber() const {return phoneNumber;}
	std::string GetEmail() const {return email;}
	int SetEmail(std::string email);
	int SetPhoneNumber(std::string phoneNumber);


	~User() {std::cout << "\n" << "User Destructed";}
};
