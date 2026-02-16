#include "menuUtils.h"
#include "../../Utils/utils.h"
#include <iostream>
#include <vector>

using namespace std;

Date InputDate(string& name){
	string aux;
	cout << name;
	cin >> aux;
	return StringToDate(aux);
}
