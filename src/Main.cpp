#include <iostream>
#include "Person/person.h"
#include "User/user.h"
#include "UserManagement/userManagement.h"

using namespace std;

int main(){
	UserManagement users;
	User user(1,"David", "Male", 21, "910539445", "david123car7@gmail.com");
	User user2(2,"Diogo", "Male", 21, "910539445", "david123car7@gmail.com");
	users.Add(user);
	users.Add(user2);
	User* x = users.GetUser("David", 1);
	users.PrintUsers();
	
	return 0;
}


