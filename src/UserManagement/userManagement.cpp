#include "userManagement.h"
#include "../User/user.h"
#include <cctype>
#include <string>
#include <stdexcept>

using namespace std;

void UserManagement::Add(std::string name, std::string gender, int age, std::string email, std::string phoneNumber){	
	if(name.empty()) throw invalid_argument("Name cant be empty.");
	if(gender.empty()) throw invalid_argument("Gender cant be empty.");
	if(age < 0 || age > 120) throw invalid_argument("Age is invalid");
	if(email.empty()) throw invalid_argument("Enail cant be empty");
	if(phoneNumber.empty()) throw invalid_argument("PhoneNumber cant be empty");

	int id;
	if(users.empty())
		id = 0;
	else{
		auto it = users.crbegin();
		id = it->first;
		id++;
	}
	users[id] = User(id, name, gender, age, email, phoneNumber);
}

User* UserManagement::GetUser(unsigned int id){
	if(!users.contains(id)) return nullptr;
	return &users[id];
}

const User* UserManagement::GetUserReadOnly(unsigned int id){
	return GetUser(id);
}

int UserManagement::Remove(unsigned int id){
	if(!users.contains(id)) return 0;
	users.erase(id);
	return 1;
}

void UserManagement::PrintUsers(){
	for(const auto& [key, user]: users){
		cout << user;	
	}
}


