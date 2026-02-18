#include "userMenu.h"
#include "../MenuUtils/menuUtils.h"
#include <limits>
#include <iostream>

using namespace std;

void DisplayUserMenu(){
	cout << "\n" << "--------------------" << "\n";
	cout << "1 - Add User" << "\n";
	cout << "2 - Remove User" << "\n";
	cout << "3 - Print User" << "\n";
	cout << "4 - Print Users" << "\n";
	cout << "5 - Print User Loans" << "\n";
	cout << "6 - Print Books User Loans" << "\n";
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
			case 5:
				PrintUserLoansIO(library);
				continue;
			case 6:
				PrintBooksUserLoansIO(library);
				continue;
			case 0:
				return;
		}
	}
}

void AddUserIO(Library& library){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		string name, gender, email, phoneNumber;
		cout << "Name: ";
		cin >> name;
		cout << "Gender: ";
		cin >> gender;
		cout << "Age: ";
		int age = InputInteger();
		if(age == -1){		
			cout << "Error: Invalid Id" << "\n";
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
	cout << "User Id : ";
	int id = InputInteger();
	if(id == -1){		
		cout << "Error: Invalid Id" << "\n";
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
	cout << "User Id: ";
	int id = InputInteger();
	if(id == -1){		
		cout << "Error: Invalid Id" << "\n";
		return;
	}
	if(int res = library.PrintUser(id); res != 1)
		cout << "Error: User does not exist";
}

void PrintUserLoansIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "User Id: ";
	int id = InputInteger();
	if(id == -1){
		cout << "Error: Invalid Id" << "\n";
		return;
	}
	library.PrintUserLoans(id);
}

void PrintBooksUserLoansIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "User Id: ";
	int id = InputInteger();
	if(id == -1){
		cout << "Error: Invalid Id" << "\n";
		return;
	}
	library.PrintBooksUserLoans(id);
}


