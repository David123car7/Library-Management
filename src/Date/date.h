#pragma once

#include <cstdint>
#include <ostream>

struct Date{
	uint8_t day;
	uint8_t month;
	uint16_t year;

	Date(uint8_t day, uint8_t month, uint16_t year);

	friend std::ostream& operator<<(std::ostream& out, Date& date){
		return out << (int)date.day << "/" << (int)date.month << "/" << date.year;
	}
};
