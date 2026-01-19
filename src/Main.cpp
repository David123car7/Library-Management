#include <iostream>
#include "Person/person.h"
#include "User/user.h"
#include "UserManagement/userManagement.h"

using namespace std;

int main(){
	UserManagement users;
	User user(1,"David", "Male", 21, "910539445", "david123car7@gmail.com");
	users.Add(user);
	const User* x = users.GetUser('d', 1);
	if(x == nullptr) cout << "User is null";
	else{
		cout << x->GetName();
	}
	//cout << "User: " << user.GetName() << " " <<user.GetGender() << " " << user.GetAge() << " " << user.GetPhoneNumber() << " " << user.GetEmail();
	
	return 0;
}


