#include <iostream>
#include "Person/person.h"
#include "User/user.h"

using namespace std;

int main(){
	User user("David", "Male", 21, "910539445", "david123car7@gmail.com");
	user.SetName("Kazzio");
	cout << "User: " << user.GetName() << " " <<user.GetGender() << " " << user.GetAge() << " " << user.GetPhoneNumber() << " " << user.GetEmail();
	
	return 0;
}


