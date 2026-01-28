#include "bookManagement.h"
#include <stdexcept>

using namespace std;

int BookManagement::Add(string name, string author, Date& releaseDate, BookGenre genre, BookState state){
	if(name.empty()) throw invalid_argument("Name cant be empty!");
	if(author.empty()) throw invalid_argument("Author cant be empty!");
	int id;
	if(books.empty()){
		id = 0;
	}
	else{
		id = books.crbegin()->first;
		id++;
	}
	books[id] = Book(id, name, author, releaseDate, genre, state);
	return id;
}

int BookManagement::Remove(unsigned int id){
	if(!books.contains(id)) return 0;
	books.erase(id);
	return 1;	
}

Book* BookManagement::GetBook(unsigned int id){
	if(!books.contains(id)) return nullptr;
	return &books[id];
}

const Book* BookManagement::GetBook(unsigned int id) const{
	if(!books.contains(id)) return nullptr;
	return &books.at(id);
}

void BookManagement::PrintBooks(){
	for(auto& [key, book]: books){
		cout << book << "\n";
	}
}

bool BookManagement::BookExists(unsigned int id){
	if(books.contains(id)) return true;
	else return false;
}


int BookManagement::GetBooksQnt(){
	return books.size();
}

int BookManagement::GetAvailableBooksQnt(){
	int qnt = 0;
	for(auto& [key, book]: books){
		if(book.GetState() == BookState::available)
			qnt++;
	}
	return qnt;
}

int BookManagement::GetNotAvailableBooksQnt(){
	int qnt = 0;
	for(auto& [key, book]: books){
		if(book.GetState() == BookState::notAvailable)
			qnt++;
	}
	return qnt;
}

int BookManagement::PrintBook(unsigned int id){
	const Book* book = GetBook(id);
	if(book == nullptr) return 0;
	cout << *book;
	return 1;
}

