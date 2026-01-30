#include "date.h"
#include "../Utils/utils.h"
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

Date Date::operator+ (unsigned int days)const{
	int sumDays = this->day + days;
	int currentMonth = month;
	int currentYear = year;
	int currentMonthDays = GetMonthDays(currentMonth-1, currentYear);
	cout << currentMonthDays << "\n";
	while(sumDays > currentMonthDays){
		sumDays = sumDays - currentMonthDays;	
		currentMonth++;
		if(currentMonth > 12){
			currentYear++;
			currentMonth = 0;
		}
		currentMonthDays = GetMonthDays(currentMonth-1, currentYear);
	}
	Date date(sumDays, currentMonth, currentYear);
	return date;
}

bool operator<(const Date& date1, const Date& date2){
	if(date1.year != date2.year){
		return date1.year < date2.year;
	}

	if(date1.month != date2.month){
		return date1.month < date2.month;
	}

	return date1.day < date2.day;
}

bool operator>(const Date& date1, const Date& date2){
	if(date1.year != date2.year){
		return date1.year > date2.year;
	}

	if(date1.month != date2.month){
		return date1.month > date2.month;
	}

	return date1.day > date2.day;
}

bool operator>=(const Date& date1, const Date& date2){
	if(date1.year != date2.year){
		return date1.year >= date2.year;
	}

	if(date1.month != date2.month){
		return date1.month >= date2.month;
	}

	return date1.day >= date2.day;
}

bool operator<=(const Date& date1, const Date& date2){
	if(date1.year != date2.year){
		return date1.year <= date2.year;
	}

	if(date1.month != date2.month){
		return date1.month <= date2.month;
	}

	return date1.day <= date2.day;

}

Date StringToDate(std::string& value){
	vector<string> dateParsed = ParseString(value, '/');
	if(dateParsed.empty()) throw invalid_argument("Invalid Date: " + value);
	int day = stoi(dateParsed[0]);
	int month = stoi(dateParsed[1]);
	int year = stoi(dateParsed[2]);
	Date date((uint8_t)day, (uint8_t)month, (uint16_t)year);
	return date;
}
