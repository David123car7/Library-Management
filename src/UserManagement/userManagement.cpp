#include "userManagement.h"
#include "../User/user.h"
#include <cctype>


using namespace std;

int UserManagement::Add(User user){	
	char key = tolower(user.GetName()[0]);
	if(!users.contains(key))
		users[key] = vector<User>();
	users[key].push_back(user);
	return 1;
}

const User* UserManagement::GetUser(char key, int id){	
	if(users.contains(key)){
		for(int i=0; i<users[key].size(); i++){
			if(users[key][i].GetId() == id)
				return &users[key][i];
		}
	}
	return nullptr;
}
