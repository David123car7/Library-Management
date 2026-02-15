#include "mainMenu.h"
#include "../UserMenu/userMenu.h"
#include "../BookMenu/bookMenu.h"
#include <limits>

using namespace std;

void DisplayMainMenu(){
	cout << "\n" << "--------------------" << "\n";
	cout << "1 - Users Menu" << "\n";
	cout << "2 - Books Menu" << "\n";
	cout << "3 - Loans Menu" << "\n";
	cout << "4 - Quit" << "\n";
	cout << "--------------------" << "\n";
}

void MainMenu(Library& library){
	while(1){
		DisplayMainMenu();
		int x;	
		if(!(cin >> x)){
			cout << "Error: Invalid Option";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		switch(x){
			case 1:
				UserMenu(library);
			case 2:
				BookMenu(library);
			case 4:
				library.CloseLibrary();

		}
	}
}
