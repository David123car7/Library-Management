#include "library.h"

using namespace std;

Result Library::CreateLoan(unsigned int bookId, unsigned int userId,const Date& currentDate, const Date& startDate, const Date& endDate){
	if(startDate > endDate) return Result::InvalidDate;
	User* user = usersManagement.GetUser(userId);
	if(user == nullptr) return Result::UserNull;
	if(user->GetState() == UserState::banned) return Result::UserBanned;
	Book* book = booksManagement.GetBook(bookId);
	if(book == nullptr) return Result::BookNull;
	if(book->GetState() != BookState::available) return Result::BookNotAvailable;
	if(Result res = CheckInUser(*user, currentDate); res != Result::Sucess) return res;
	if(loansManagement.GetUserMapSize(userId) >= MAX_LOANS) return Result::LoansMaxReached;
	int loanId = loansManagement.Add(bookId, userId, startDate, endDate, Date(), LoanState::toPickUp);
	loansManagement.AddIdUserMap(user->GetId(), loanId);
	loansManagement.AddIdBookMap(book->GetId(), loanId);
	book->SetState(BookState::notAvailable);		
	return Result::Sucess;
}

Result Library::PickupLoan(unsigned int loanId, const Date& pickedUpDate){
	Loan* loan = nullptr;
	User* user = nullptr;
	Book* book = nullptr;
	if(Result res = GetLoanContext(loanId, user, loan, book); res != Result::Sucess)
		return res;
	if(loan->GetState() != LoanState::toPickUp) return Result::LoanPickedUp;
	if(pickedUpDate > loan->GetEndDate()){
		DeactivateLoan(*loan, *user, *book, pickedUpDate);
		ApplyPenalty(*user, pickedUpDate);
		return Result::LoanNotPickedUp;
	}
	LoanBook(*loan);
	return Result::Sucess;
}

Result Library::FinishLoan(unsigned int loanId, const Date& deliveredDate){
	Loan* loan = nullptr;
	User* user = nullptr;
	Book* book = nullptr;
	if(Result res = GetLoanContext(loanId, user, loan, book); res != Result::Sucess)
		return res;
	if(loan->GetState() == LoanState::finished) return Result::LoanFinished;
	DeactivateLoan(*loan, *user, *book, deliveredDate);
	if(deliveredDate > loan->GetEndDate()){
		ApplyPenalty(*user, deliveredDate);	
	}
	return Result::Sucess;
}

Result Library::RemoveUser(unsigned int userId){
	if(loansManagement.ExistsKeyUserMap(userId)) 
		return Result::UserNotRemoved;
	if(int res = usersManagement.Remove(userId); res == 1)
		return Result::Sucess;
	else return Result::UserNull;
}

Result Library::RemoveBook(unsigned int bookId){
	if(loansManagement.ExistsKeyBookMap(bookId)) 
		return Result::BookNotRemoved;
	if(int res = booksManagement.Remove(bookId); res == 1)
		return Result::Sucess;
	else return Result::BookNull;
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

Result Library::GetLoanContext(unsigned int loanId, User*& user, Loan*& loan, Book*& book){
	loan = loansManagement.GetLoan(loanId);
	if(loan == nullptr) return Result::LoanNull;
	user = usersManagement.GetUser(loan->GetUserId());
	if(user == nullptr) return Result::UserNull;
	book = booksManagement.GetBook(loan->GetBookId());
	if(book == nullptr) return Result::BookNull;
	return Result::Sucess;
}

void Library::DeactivateLoan(Loan& loan, User& user, Book& book, const Date& date){
	int userId = user.GetId();
	int bookId = book.GetId();
	int loanId = loan.GetId();
	loan.SetState(LoanState::finished);
	loan.SetDeliveredDate(date);
	book.SetState(BookState::available);
	loansHistoryManagement.AddIdUserMap(userId, loanId);
	loansManagement.RemoveIdUserMap(userId, loanId);
	loansHistoryManagement.AddIdBookMap(bookId, loanId);
	loansManagement.RemoveIdBookMap(bookId, loanId);
	loansHistoryManagement.Add(bookId, userId, loan.GetStartDate(), loan.GetEndDate(), date , loan.GetState());
	loansManagement.Remove(loanId);
}

void Library::ApplyPenalty(User& user, const Date& date){
	user.IncrementOccurrences();
	if(user.GetOccurrences() > MAX_USER_OCCURRENCES){
		BanUser(user, date);	
	}
}

void Library::LoanBook(Loan& loan){
	loan.SetState(LoanState::loaned);	
}

void Library::OpenLibrary(){
	booksManagement.ReadDataFromFile();
	usersManagement.ReadDataFromFile();
	loansManagement.ReadDataFromFile();
}

void Library::CloseLibrary(){
	booksManagement.StoreDataInFile();
	usersManagement.StoreDataInFile();
	loansManagement.StoreDataInFile();
}

Result Library::PrintUserLoans(unsigned int userId){
	PrintLoanColumns();
	if(int res = loansManagement.PrintUserLoans(userId); res == 0) return Result::UserNull; 
	return Result::Sucess;
}

Result Library::PrintBooksUserLoans(unsigned int userId){
	const User* user = usersManagement.GetUser(userId);
	if(user == nullptr) return Result::UserNull;
	const vector<unsigned int>* loans = loansManagement.GetUserLoanIds(userId);
	if(loans == nullptr) return Result::LoansEmpty;
	PrintBookColumns();
	for(unsigned int i=0; i<loans->size(); i++){
		const Loan* loan = loansManagement.GetLoan(loans->at(i));
		if(loan == nullptr) return Result::LoanNull;
		booksManagement.PrintBook(loan->GetBookId());
		cout << "\n";
	}
	return Result::Sucess;
}

void Library::PrintBooksQnt(){
	cout << booksManagement.GetBooksQnt() << "\n";
}


void Library::PrintAvailableBooksQnt(){
	cout << booksManagement.GetAvailableBooksQnt() << "\n";
}

void Library::PrintNotAvailableBooksQnt(){
	cout << booksManagement.GetNotAvailableBooksQnt() << "\n";
}
