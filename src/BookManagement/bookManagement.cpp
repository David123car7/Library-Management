#include "bookManagement.h"

using namespace std;

void BookManagement::Add(const Book& book){
	int16_t key = book.GetRealeaseDate().year;
	if(!books.contains(key))
		books[key] = vector<Book>();
	books[key].push_back(book);
}

int BookManagement::Remove(int16_t year, int id){
	if(books.contains(year)){
		vector<Book>& booksRef = books[year];
		for(int i=0; i<booksRef.size(); i++){
			if(booksRef[i].GetId() == id){
				booksRef[i] = booksRef.back();
				booksRef.pop_back();
				return 1;
			}
		}
	}
	return 0;
}

Book* BookManagement::GetBook(int16_t year, int id){
	if(books.contains(year)){
		vector<Book>& booksRef = books[year];
		for(int i=0; i<booksRef.size(); i++){
			if(booksRef[i].GetId() == id){
				return &booksRef[i];
			}
		}
	}
	return nullptr;
}

const Book* BookManagement::GetBookReadOnly(int16_t year, int id){
	return GetBook(year, id);
}

void BookManagement::PrintBooks(){
	cout << "ID" << " | " << "NAME" << " | " << "AUTHOR" << " | " << "DATE" << " | " << "GENRE" << "\n";
	for(auto& [key, list]: books){
		for(Book& book: list){
			cout << book << "\n";
		}	
	}
}
