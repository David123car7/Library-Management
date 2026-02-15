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
			case 4:
				library.PrintBooks();
		}
	}
}

void AddBookIO(Library& library){
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	string name, author, releaseDate;
	BookGenre genre;
	BookState state;
	cout << "Name: " << "\n";
	cin >> name;
	cout << "Author: " << "\n";
	cin >> author;
	cout << "Date(dd/mm/yyyy):" << "\n";
	cin >> releaseDate;

	vector<string> date = ParseString(releaseDate, '/');	
	try{
		int day = stoi(date[0]);
		int month = stoi(date[1]);
		int year = stoi(date[2]);
	}
	catch(exception& e){
		cout << e.what();
		return;
	}

	cout << "BookGenre:" << "\n";
}

void RemoveBookIO(Library& library){
}

void PrintBookIO(Library& library){
}

