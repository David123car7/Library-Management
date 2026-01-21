#include "person.h"
#include "../Utils/utils.h"
#include <stdexcept>
#include <string>

using namespace std;

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
