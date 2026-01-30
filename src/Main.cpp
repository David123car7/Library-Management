#include <iostream>
#include "Date/date.h"
#include "Library/library.h"

using namespace std;

int main(){
	Library library;
        library.OpenLibrary();

	Date date(1,1,2005);
	Date date1(1,2,2005);
	Date date2(1,3,2005);
	Date date3(1,5,2005);
	
	//library.AddUser("David", "Male", 21,"david123car7@gmail.com", "910539445");  
	//library.AddBook("c++", "cj", date, BookGenre::fantasy, BookState::available); 
	//library.CreateLoan(0,0, date, date2, date3);

	library.PrintUsers(); 
	cout << "\n";
	library.PrintBooks();
	cout << "\n";
	library.PrintLoans();
	
	library.CloseLibrary();
	return 0;
}


