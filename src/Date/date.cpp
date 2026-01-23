#include "date.h"
#include <stdexcept>
using namespace std;

Date::Date(uint8_t day, uint8_t month, uint16_t year):
	day{day},
	month{month},
	year{year}
	{
	if(day > 31) throw invalid_argument("Invalid day");
	if(month > 12) throw invalid_argument("Invalid Month");
}

bool operator<(const Date& date1, const Date& date2){
	if(date1.year > date2.year) return false;
	if(date1.month > date2.month) return false;
	if(date1.year > date2.day) return false;
	return true;
}

bool operator>(const Date& date1, const Date& date2){
	if(date1.year < date2.year) return false;
	if(date1.month < date2.month) return false;
	if(date1.year < date2.day) return false;
	return true;
}
