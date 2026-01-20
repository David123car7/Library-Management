#include "person.h"
#include "../Utils/utils.h"
#include <stdexcept>
#include <string>

using namespace std;

Person::Person(int id, std::string name, std::string gender, int age): 
	id{id},
	name{name}, 
	gender{gender}, 
	age{age}{
	if(id <= 0) throw invalid_argument("Id must be greater than 0");
	if(name.empty() || isInvalidString(name)) throw invalid_argument("Name can not be empty");
	if(gender.empty() || isInvalidString(gender)) throw invalid_argument("Gender can not be empty");
	if(age <= 0 || age > 120) throw invalid_argument("Age is invalid");
	}

int Person::SetName(string name){
	if(name.length() == 0) return 0;
	this->name = name;
	return 1;
}

int Person::SetGender(string gender) {
	if(gender.length() == 0) return 0;
	this->gender = gender;
	return 1;
}

int Person::SetAge(int age) {
	if(age <= 0) return 0;
	this->age = age;
	return 1;
}
