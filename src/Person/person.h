#pragma once

#include <string>
#include <iostream>

class Person{
	private:
	int id;
        std::string name;
	std::string gender;
	int age;

	public:
	Person(): name{""}, gender{""}, age{0}{}
	Person(int id, std::string name, std::string gender, int age): 
		id{id},
		name{name}, 
		gender{gender}, 
		age{age}{}

	~Person(){ std::cout << "\n" <<"Person destructed";}
 
	const std::string& GetName() const {return name;}
	const std::string& GetGender() const {return gender;}
	int GetAge() const {return age;}
	int SetName(std::string name);
	int SetGender(std::string gender);
	int SetAge(int age);
};
