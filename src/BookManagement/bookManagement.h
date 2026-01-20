#pragma once

#include "../Book/book.h"
#include <map>
#include <vector>

class BookManagement{
	private:
	std::map<int16_t, std::vector<Book>> books;

	public:
	void Add(const Book& book);
	int Remove(int16_t year, int id);
	Book* GetBook(int16_t year, int id);
	const Book* GetBookReadOnly(int16_t year, int id);
	void PrintBooks();
};
