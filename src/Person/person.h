#pragma once

#include <string>
#include <iostream>

class Person{
	private:
	unsigned int id;
        std::string name;
	std::string gender;
	int age;

	public:
	Person(): id{0}, name{""}, gender{""}, age{0} {}	

	/**
	 * @brief Constructor for the Person Class
	 *
	 * @param[in] id Person Id
	 * @param[in] name Name
	 * @param[in] gender Gender
	 * @param[in] age Age
	 */
	Person(unsigned int id, std::string name, std::string gender, int age): 
		id{id},
		name{name}, 
		gender{gender}, 
		age{age}{}


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
