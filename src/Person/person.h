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
	/**
	 * @brief Constructor for the Person Class
	 *
	 * @param[in] id Person Id
	 * @param[in] name Name
	 * @param[in] gender Gender
	 * @param[in] age Age
	 */
	Person(unsigned int id, std::string name, std::string gender, int age);
 
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
