#pragma once

#include <string>
#include <iostream>

class Person{
	private:
        std::string name;
	std::string gender;
	int age;

	public:
	Person(): 
		name{""},
		gender{""},
		age{0}{}
	Person(std::string name, std::string gender, int age): 
		name{name}, 
		gender{gender}, 
		age{age}{}
	~Person(){ std::cout << "\n" <<"Person destructed";}
 
	std::string GetName() const {return name;}
	std::string GetGender() const {return gender;}
	int GetAge() const {return age;}
	int SetName(std::string name);
	int SetGender(std::string gender);
	int SetAge(int age);
};
