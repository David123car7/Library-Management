#include <iostream>
#include "Person/person.h"
#include "User/user.h"
#include "UserManagement/userManagement.h"
#include "Date/date.h"
#include "Book/book.h"
#include "BookManagement/bookManagement.h"
#include "LoanManagement/loanManagement.h"
#include "Loan/loan.h"
#include "Utils/utils.h"
#include "Library/library.h"

using namespace std;

int main(){
	Library library;
	Date date(1,1,2005);
	Date date1(1,2,2005);
	Date date2(1,3,2005);
	Date date3(1,5,2005);
	library.AddUser("David", "Male", 21, "kazzio", "ola");
	library.AddBook("C++", "CJ", date, BookGenre::fantasy, BookState::available); 
	library.AddBook("86", "Goat", date, BookGenre::fantasy, BookState::available); 
	library.AddBook("Vim", "Bruh", date, BookGenre::fantasy, BookState::available); 
	library.AddBook("C++", "CJ", date, BookGenre::fantasy, BookState::available); 
	library.CreateLoan(0,0, date, date1, date2);
	library.CreateLoan(1,0, date, date1, date2);
	library.CreateLoan(2,0, date, date1, date2);
	library.PickupLoan(0, date);
	library.PickupLoan(1, date);
	library.FinishLoan(2, date3);
	library.PrintLoans();
	return 0;
}


