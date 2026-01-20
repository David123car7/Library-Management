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

