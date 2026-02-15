#include "userMenu.h"
#include <limits>
#include <iostream>

using namespace std;

void DisplayUserMenu(){
	cout << "\n" << "--------------------" << "\n";
	cout << "1 - Add User" << "\n";
	cout << "2 - Remove User" << "\n";
	cout << "3 - Print User" << "\n";
	cout << "4 - Print Users" << "\n";
	cout << "0 - Go Back" << "\n";
	cout << "--------------------" << "\n";
}

void UserMenu(Library& library){	
	while(1){
		DisplayUserMenu();
		int x;
		if(!(cin >> x)){
			cin.clear();
			cout << "Error: Invalid Option";
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		switch(x){
			case 1: 
				AddUserIO(library);
				continue;
			case 2: 
				RemoveUserIO(library);
				continue;
			case 3:
				PrintUserIO(library);
				continue;
			case 4:
				library.PrintUsers();
				continue;
			case 0:
				return;
		}
	}
}

void AddUserIO(Library& library){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string name, gender, email, phoneNumber;
		int age;

		cout << "Name: ";
		cin >> name;
		cout << "Gender: ";
		cin >> gender;
		cout << "Age: ";
		if(!(cin >> age)){
			cout << "Error: Invalid Age" << "\n";
			cin.clear();
			return;
		}
		cout << "Email: ";
		cin >> email;
		cout << "Phone Number:";
		cin >> phoneNumber;
	
		try{
			library.AddUser(name, gender, age, email, phoneNumber);
			cout << "User added successfully" << "\n";
		}
		catch(exception& e){
			cout << "Error: " <<  e.what() << "\n" << "\n";
		}
}

void RemoveUserIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int id;
	cout << "Id: ";
	if(!(cin >> id)){
		cout << "Error: Invalid Id" << "\n";
		cin.clear();
		return;
	}

	if(Result res = library.RemoveUser(id); res == Result::Sucess)
		cout << "User Removed Successfully" << "\n";
	else if(res == Result::UserNotRemoved)
		cout << "Error: User cant be removed because its being referenced in another place" << "\n";
	else if(res == Result::UserNull)
		cout << "Error: User does not exist" << "\n";
}

void PrintUserIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int id;	
	cout << "Id: " << "\n";
	if(!(cin >> id)){
		cout << "Error: Invalid Id" << "\n";
		cin.clear();
		return;
	}
	if(int res = library.PrintUser(id); res != 1)
		cout << "Error: User does not exist";
}






