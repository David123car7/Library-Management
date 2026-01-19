#pragma once

#include "../User/user.h"
#include <vector>
#include <map>

class UserManagement{
	public:
	std::map<char, std::vector<User>> users;

	public:
	int Add(User user);
	int Remove(int id);
	const User* GetUser(char key, int id);
};
