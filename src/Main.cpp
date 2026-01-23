#include <iostream>
#include "Person/person.h"
#include "User/user.h"
#include "UserManagement/userManagement.h"
#include "Date/date.h"
#include "Book/book.h"
#include "BookManagement/bookManagement.h"
#include "LoanManagement/loanManagement.h"
#include "Loan/loan.h"

using namespace std;

int main(){
	UserManagement users;
	BookManagement books;
	users.Add("David", "Male", 21, "910539445", "david123car7@gmail.com");
	users.Add("Diogo", "Male", 21, "910539445", "david123car7@gmail.com");
	Date date(1,1,2026);
	books.Add("C++ Basics", "CJ", date, BookGenre::fantasy, BookState::available); 
	books.Add("C++ Basics", "CJ", date, BookGenre::fantasy, BookState::available); 
	books.Remove(1);
	books.PrintBooks();
	return 0;
}


