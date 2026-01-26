#include "utils.h"

using namespace std;

bool isInvalidString(const string& x){
	if(isspace(x[0])) return true;
	else return false;
}

int GetMonthDays(uint8_t month, unsigned int year){
	static constexpr const std::array<uint8_t, 12> month_days = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(month < 0 || month > 12) return -1;
	if(month == 2){
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
			return 29;
		}
	}
	return month_days[month];	
}
