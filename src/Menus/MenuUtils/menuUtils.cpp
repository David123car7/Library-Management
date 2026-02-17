#include "menuUtils.h"
#include "../../Utils/utils.h"
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

Date InputDate(){
	string aux;
	cin >> aux;
	return StringToDate(aux);
}

int InputInteger(){
	int id;	
	if(!(cin >> id)){
		cin.clear();
		return -1;
	}
	return id;
}
