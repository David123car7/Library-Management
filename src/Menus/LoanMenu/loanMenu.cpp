#include "loanMenu.h"
#include "../../Utils/utils.h"
#include "../MenuUtils/menuUtils.h"
#include <limits>

using namespace std;

void DisplayLoanMenu(){
	cout << "\n" << "--------------------" << "\n";
	cout << "1 - Add Loan" << "\n";
	cout << "2 - Deliver Loan" << "\n";
	cout << "3 - Finish Loan" << "\n";
	cout << "4 - Print Loan" << "\n";
	cout << "5 - Print Loans" << "\n";
	cout << "6 - Print Loans History" << "\n";
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
			case 6: 
				library.PrintHistoryLoans();
				continue;
			case 0:
				return;
		}
	}
}

void AddLoanIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	Date startDate, endDate, currentDate;
	string aux;
	cout << "Book Id: ";
	int bookId = InputInteger();
	if(bookId == -1){		
		cout << "Error: Invalid Id" << "\n";
		return;
	}
	cout << "User Id; ";
	int userId = InputInteger();
	if(userId == -1){		
		cout << "Error: Invalid Id" << "\n";
		return;
	}
	try{
		cout << "Current Date(dd/mm/yyyy): ";
		cin >> aux;
		currentDate = StringToDate(aux);
		cout << "Start Date(dd/mm/yyyy): ";
		cin >> aux;
		startDate = StringToDate(aux);
		cout << "End Date(dd/mm/yyyy): ";
		cin >> aux;
		endDate = StringToDate(aux);
	}
	catch(exception& e){
		cout << "Error: " << e.what();
	}
	cout << library.CreateLoan(bookId, userId, currentDate, startDate, endDate);
}

void DeliverLoanIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	Date pickedUpDate;
	string aux;
	cout << "Loan Id: ";
	int id = InputInteger();
	if(id == -1){		
		cout << "Error: Invalid Id" << "\n";
		return;
	}
	try{
		cout << "Delivered Date(dd/mm/yyyy): ";
		pickedUpDate = InputDate();
	}
	catch(exception& e){
		cout << "Error: " << e.what();
	}
	cout << library.PickupLoan(id, pickedUpDate);
}

void FinishLoanIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	Date deliveredDate;
	string aux;
	cout << "Loan Id: ";
	int id = InputInteger();
	if(id == -1){		
		cout << "Error: Invalid Id" << "\n";
		return;
	}
	try{
		cout << "Delivered Date(dd/mm/yyyy): ";
		deliveredDate = InputDate();
	}
	catch(exception& e){
		cout << "Error: " << e.what();
	}
	cout << library.FinishLoan(id, deliveredDate); 
}

void PrintLoanIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Loan Id: ";
	int id = InputInteger();
	if(id == -1){		
		cout << "Error: Invalid Id" << "\n";
		return;
	}

	if(int res = library.PrintLoan(id); res != 1)
		cout << "Error: Loan does not exist";
}


