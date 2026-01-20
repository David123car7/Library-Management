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
	Person(int id, std::string name, std::string gender, int age);
	~Person(){}
 
	const std::string& GetName() const {return name;}
	const std::string& GetGender() const {return gender;}
	int GetId() const {return id;}
	int GetAge() const {return age;}
	int SetName(std::string name);
	int SetGender(std::string gender);
	int SetAge(int age);


	friend std::ostream& operator<<(std::ostream& out, const Person& person){
		return out << person.id << " " << person.name << " " << person.gender << " " << person.age;
	}
};
