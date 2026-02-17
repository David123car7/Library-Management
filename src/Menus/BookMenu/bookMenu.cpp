#include "bookMenu.h"
#include "../../Utils/utils.h"
#include <limits>

using namespace std;


void DisplayBookMenu(){
	cout << "\n" << "--------------------" << "\n";
	cout << "1 - Add Book" << "\n";
	cout << "2 - Remove Book" << "\n";
	cout << "3 - Print Book" << "\n";
	cout << "4 - Print Books" << "\n";
	cout << "0 - Go Back" << "\n";
	cout << "--------------------" << "\n";
}

void BookMenu(Library& library){
	while(1){
		DisplayBookMenu();
		int x;
		if(!(cin >> x)){
			cout << "Error: Invalid Option" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		switch(x){
			case 1:
				AddBookIO(library);
				continue;
			case 2:
				RemoveBookIO(library);
				continue;
			case 3:
				PrintBookIO(library);
				continue;
			case 4:
				library.PrintBooks();
				continue;
			case 0:
				return;
		}
	}
}

void AddBookIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string name, author, releaseDateAux, genreAux, stateAux;
	Date releaseDate;
	BookGenre genre;
	cout << "Name: ";
	cin >> name;
	cout << "Author: ";
	cin >> author;
	cout << "Release Date(dd/mm/yyyy): ";
	cin >> releaseDateAux;

	vector<string> date = ParseString(releaseDateAux, '/');	
	try{
		int day = stoi(date[0]);
		int month = stoi(date[1]);
		int year = stoi(date[2]);
		releaseDate = Date(day,month, year);
		cout << "BookGenre: ";
		cin >> genreAux;
		genre = StringToBookGenre(genreAux);
		cout << library.AddBook(name, author, releaseDate, genre, BookState::available);
	}
	catch(exception& e){
		cout << "Error: " << e.what() << "\n";
		return;
	}
}

void RemoveBookIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int id;
	cout << "Id: ";
	if(!(cin >> id)){
		cout << "Error: Invalid Id" << "\n";
		cin.clear();
		return;
	}

	if(Result res = library.RemoveBook(id); res == Result::Sucess)
		cout << "Book Removed Successfully" << "\n";
	else if(res == Result::BookNotRemoved)
		cout << "Error: Book cant be removed because its being referenced in another place" << "\n";
	else if(res == Result::BookNull)
		cout << "Error: Book does not exist" << "\n";
}

void PrintBookIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	int id;
	cout << "Id: ";
	if(!(cin >> id)){
		cout << "Error: Invalid Id" << "\n";
		cin.clear();
		return;
	}

	if(int res = library.PrintBook(id); res != 1)
		cout << "Error: Book does not exist";
}

