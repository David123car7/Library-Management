#include "library.h"

using namespace std;

Result Library::CreateLoan(unsigned int bookId, unsigned int userId,const Date& currentDate, const Date& startDate, const Date& endDate){
	if(startDate > endDate) return Result::InvalidDate;
	User* user = usersManagement.GetUser(userId);
	if(user == nullptr) return Result::UserNull;
	Book* book = booksManagement.GetBook(bookId);
	if(book == nullptr) return Result::BookNull;
	if(Result res = IsBookAvailable(*book); res != Result::Sucess) return res;
	if(Result res = CheckInUser(*user, currentDate); res != Result::Sucess) return res;
	if(user->GetCurrentLoans() >= MAX_LOANS) return Result::LoansMaxReached;
	int loanId = loansManagement.Add(bookId, userId, startDate, endDate, LoanState::toPickUp);
	user->AddLoanId(loanId);	
	book->SetState(BookState::notAvailable);		
	return Result::Sucess;
}

Result Library::FinishLoan(unsigned int loanId, const Date& deliveredDate){
	Loan* loan = loansManagement.GetLoan(loanId);
	if(loan == nullptr) return Result::LoanNull;
	User* user = usersManagement.GetUser(loan->GetUserId());
	if(user == nullptr) return Result::UserNull;
	Book* book = booksManagement.GetBook(loan->GetBookId());
	if(book == nullptr) return Result::BookNull;
	if(loan->GetState() == LoanState::finished)
		return Result::LoanFinished;
	loan->SetState(LoanState::finished);
	loan->SetDeliveredDate(deliveredDate);
	book->SetState(BookState::available);
	if(deliveredDate > loan->GetEndDate()){
		user->IncrementOccurrences();
		if(user->GetOccurrences() >= MAX_USER_OCCURRENCES){
			BanUser(loan->GetUserId(), deliveredDate);	
		}
	}
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
	if(user.GetCurrentLoans() > MAX_LOANS) return Result::LoansMaxReached;
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
				user.SetState(UserState::active);
				return Result::Sucess;
		}
		return Result::UserBanned;
	}
}

Result Library::BanUser(User& user, const Date& startDate){
	if(user.GetState() == UserState::banned) return Result::UserBanned;
	user.SetState(UserState::banned);
	Date banDate = startDate + BAN_DAYS;
	user.SetBanExpireDate(banDate); 
	return Result::Sucess;
}

Result Library::BanUser(unsigned int userId, const Date& startDate){
	User* user = usersManagement.GetUser(userId);
	if(user == nullptr) return Result::UserNull;
	return BanUser(*user, startDate);
}



