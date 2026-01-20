#include "utils.h"

using namespace std;

bool isInvalidString(const string& x){
	if(isspace(x[0])) return true;
	else return false;
}
