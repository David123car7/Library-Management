#include <iostream>
#include "Person/person.h"
#include "User/user.h"
#include "UserManagement/userManagement.h"
#include "Date/date.h"
#include "Book/book.h"
#include "BookManagement/bookManagement.h"

using namespace std;

int main(){
	UserManagement users;
	BookManagement books;
	User user(1,"David", "Male", 21, "910539445", "david123car7@gmail.com");
	User user2(2,"Diogo", "Male", 21, "910539445", "david123car7@gmail.com");
	users.Add(user);
	users.Add(user2);
	Date date = Date(1,2,2026);
	Book book = Book(1, "C++ Basics", "David", date, BookGenre::fantasy, BookState::available);
	Book book2 = Book(2, "Operative Systems", "David", date, BookGenre::fantasy, BookState::available);
	books.Add(book);
	books.Add(book2);

	const Book* x = books.GetBook(2026, 1);
	books.PrintBooks();
	return 0;
}


