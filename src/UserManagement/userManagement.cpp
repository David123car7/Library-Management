#include "userManagement.h"
#include "../User/user.h"
#include <cctype>
#include <string>

using namespace std;

int UserManagement::Add(User user){	
	char key = tolower(user.GetName()[0]);
	if(!users.contains(key))
		users[key] = vector<User>();
	users[key].push_back(user);
	return 1;
}

User* UserManagement::GetUser(const string& name, int id){
	return GetUser(tolower(name[0]), id);
}

User* UserManagement::GetUser(char key, int id){	
	if(users.contains(key)){
		vector<User>& list = users[key];
		for(int i=0; i<list.size(); i++){
			if(list[i].GetId() == id)
				return &users[key][i];
		}
	}
	return nullptr;
}

const User* UserManagement::GetUserReadOnly(const string& name, int id){
	return GetUser(name, id);
}

const User* UserManagement::GetUserReadOnly(char key, int id){
	return GetUser(key, id);
}

int UserManagement::Remove(const string& name, int id){
	return Remove(tolower(name[0]), id);
}


int UserManagement::Remove(char key, int id){
	if(users.contains(key)){
		vector<User>& list = users[key];
		for(int i=0; i<list.size(); i++){
			if(list[i].GetId() == id){
				list[i] = list.back();
				list.pop_back();
				return 1;
			}
		}
	}

	return 0;
}

void UserManagement::PrintUsers(){
	for(const auto& [key, list]: users){
		for(const User& user: list){
			cout << user;
			cout << "\n";
		}
	}
}


