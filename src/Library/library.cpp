#include "library.h"

using namespace std;


Result Library::CreateLoan(unsigned int bookId, unsigned int userId,const Date& currentDate, const Date& startDate, const Date& endDate){
	User* user = usersManagement.GetUser(userId);
	if(user == nullptr) return Result::UserNull;
	Book* book = booksManagement.GetBook(bookId);
	if(book == nullptr) return Result::BookNull;

	if(Result res = IsBookAvailable(*book); res != Result::Sucess) return res;
	if(Result res = CheckInUser(*user, currentDate); res != Result::Sucess) return res;
	loansManagement.Add(bookId, userId, startDate, endDate, LoanState::toPickUp);
	user->IncrementCurrentLoans();
	book->SetState(BookState::notAvailable);		
	return Result::Sucess;
}

Result Library::IsBookAvailable(unsigned int bookId){
	const Book* book = booksManagement.GetBook(bookId);
	if(book == nullptr) return Result::BookNull;
	return IsBookAvailable(*book);
}

Result Library::IsBookAvailable(const Book& book){
	if(book.GetState() == BookState::available) return Result::Sucess;
	else return Result::BookNotAvailable;
}

Result Library::CanUserLoan(unsigned int userId){
	const User* user = usersManagement.GetUser(userId);
	if(user == nullptr) return Result::UserNull;
	return CanUserLoan(*user);
}


Result Library::CanUserLoan(const User& user){
	if(user.GetCurrentLoans() > 3) return Result::LoansMaxReached;
	if(user.GetState() == UserState::active) return Result::Sucess;
	else return Result::UserBanned;
}

Result Library::CheckInUser(unsigned int userId, const Date& currentDate){	
	User* user = usersManagement.GetUser(userId);
	if(user == nullptr) return Result::UserNull;
	return CheckInUser(*user, currentDate);	
}

Result Library::CheckInUser(User& user, const Date& currentDate){	
	if(user.GetState() == UserState::active) return Result::Sucess;
	else{
		if(user.GetBanExpireDate() >= currentDate){
				user.SetUserState(UserState::active);
				return Result::Sucess;
		}
		return Result::UserBanned;
	}
}



