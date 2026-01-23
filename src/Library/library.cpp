#include "library.h"

using namespace std;


int Library::CreateLoan(unsigned int bookId, unsigned int userId,const Date& currentDate, const Date& startDate, const Date& endDate){
	if(int res = IsBookAvailable(bookId); res != 1) return res;
	int res = CanUserLoan(userId);
	if(res == -1) return res;
	
	User* user = usersManagement.GetUser(userId);
	if(res == 1){
		loansManagement.Add(bookId, userId, startDate, endDate, LoanState::toPickUp);
	}
	else if(res == 0){
	
	}
}

int Library::IsBookAvailable(unsigned int bookId){
	if(!booksManagement.BookExists(bookId)) return -1;
	const Book* book = booksManagement.GetBook(bookId);
	return book->GetState() == BookState::available;
}

int Library::CanUserLoan(unsigned int userId){
	if(!usersManagement.UserExists(userId)) return -1;
	const User* user = usersManagement.GetUser(userId);
	if(user->GetCurrentLoans() > 3) return -2;
	return user->GetState() == UserState::active;
}




