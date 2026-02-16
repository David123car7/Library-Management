#include "loanMenu.h"
#include "../../Utils/utils.h"
#include "../MenuUtils/menuUtils.h"
#include <limits>

using namespace std;

void DisplayLoanMenu(){
	cout << "\n" << "--------------------" << "\n";
	cout << "1 - Add Loan" << "\n";
	cout << "2 - Deliver Loan" << "\n";
	cout << "3 - Remove Loan" << "\n";
	cout << "4 - Print Loan" << "\n";
	cout << "5 - Print Loans" << "\n";
	cout << "0 - Go Back" << "\n";
	cout << "--------------------" << "\n";
}

void LoanMenu(Library& library){
	while(1){
		DisplayLoanMenu();
		int x;
		if(!(cin >> x)){
			cout << "Error: Invalid Option" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		switch(x){
			case 1:
				AddLoanIO(library);	
				continue;
			case 2:
				DeliverLoanIO(library);
				continue;
			case 3:
				FinishLoanIO(library);
				continue;
			case 4:
				PrintLoanIO(library);
				continue;
			case 5:
				library.PrintLoans();
				continue;
			case 0:
				return;
		}
	}
}

void AddLoanIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	unsigned int bookId, userId;
	Date startDate, endDate, currentDate;
	string aux;
	cout << "Book Id: ";
	cin >> bookId;
	cout << "User Id; ";
	cin >> userId;
	try{
		cout << "Current Date(dd/mm/yyyy): ";
		cin >> aux;
		cout << "Start Date(dd/mm/yyyy): ";
		cin >> aux;
		startDate = StringToDate(aux);
		cout << "End Date(dd/mm/yyyy): ";
		cin >> aux;
		endDate = StringToDate(aux);
		currentDate = StringToDate(aux);
		cout << startDate << " " << endDate << " " << currentDate;
	}
	catch(exception& e){
		cout << "Error: " << e.what();
	}
	cout << library.CreateLoan(bookId, userId, currentDate, startDate, endDate);
}

void DeliverLoanIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int id;
	Date pickedUpDate;
	string aux;
	cout << "Id: ";
	if(!(cin >> id)){
		cout << "Error: Invalid Id" << "\n";
		cin.clear();
		return;
	}
	try{
		string name = "Delivered Date(dd/mm/yyyy): "; 	
		pickedUpDate = InputDate(name);
	}
	catch(exception& e){
		cout << "Error: " << e.what();
	}
	cout << library.PickupLoan(id, pickedUpDate);
}

void FinishLoanIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int id;
	Date deliveredDate;
	string aux;
	cout << "Id: ";
	if(!(cin >> id)){
		cout << "Error: Invalid Id" << "\n";
		cin.clear();
		return;
	}
	try{
		string name = "Delivered Date(dd/mm/yyyy): "; 	
		deliveredDate = InputDate(name);
	}
	catch(exception& e){
		cout << "Error: " << e.what();
	}
	cout << library.FinishLoan(id, deliveredDate); 
}

void PrintLoanIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int id;
	cout << "Id: ";
	if(!(cin >> id)){
		cout << "Error: Invalid Id" << "\n";
		cin.clear();
		return;
	}

	if(int res = library.PrintLoan(id); res != 1)
		cout << "Error: Loan does not exist";
}


