#pragma once

#include "../User/user.h"
#include <vector>
#include <string>
#include <map>

class UserManagement{
	public:
	std::map<char, std::vector<User>> users;

	public:
	int Add(User user);
	int Remove(const std::string& name, int id);
	int Remove(char key, int id);
	
	User* GetUser(char key, int id); 
	User* GetUser(const std::string& name, int id);
	const User* GetUserReadOnly(const std::string& name, int id); 
	const User* GetUserReadOnly(char key, int id);

	void PrintUsers();	
};
