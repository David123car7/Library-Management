#pragma once

#include <cstdint>
#include <ostream>

/**
 * struct Date - Struct that represents a date in the format day/month/year
 */
struct Date{
	uint8_t day;
	uint8_t month;
	uint16_t year;
	
	Date(): day{0}, month{0}, year{0}{};
	Date(uint8_t day, uint8_t month, uint16_t year);
	
	/**
	 * @brief Overloads the + operator to calculate a date plus days
	 *
	 * @param[in] days Number of days
	 * @return A new date resulted of the operation
	 */
	Date operator+(unsigned int days)const;

	/**
	* @brief Overloads the stream insertion operator to print the Date.
	* * Outputs the date in the format: day/month/year.
	*
	* @param[in,out] out   The output stream to write to (e.g., std::cout).
	* @param[in]     date  The Date object to be printed.
	* @return A reference to the modified output stream to allow chaining.
	*/
	friend std::ostream& operator<<(std::ostream& out, const Date& date){
		return out << (int)date.day << "/" << (int)date.month << "/" << date.year;
	}
	
	/**
	* @brief Overloads the < operator
	*
	* @param[in] date1 The date on the left of the operator
	* @param[in] date2 The date on the right of the operator
	* @return false if the date1 is not lesser than date2
	* true if the date1 is lesser than date2
	*/
	friend bool operator<(const Date& date1, const Date& date2);
	
	/**
	* @brief Overloads the > operator
	*
	* @param[in] date1 The date on the left of the operator
	* @param[in] date2 The date on the right of the operator
	* @return false if the date1 is not greater than date2
	* true if the date1 is greater than date2
	*/
	friend bool operator>(const Date& date1, const Date& date2);

	
	/**
	* @brief Overloads the >= operator
	*
	* @param[in] date1 The date on the left of the operator
	* @param[in] date2 The date on the right of the operator
	* @return false if the date1 is not greater than date2
	* true if the date1 is greater than date2
	*/
	friend bool operator>=(const Date& date1, const Date& date2);

	/**
	* @brief Overloads the <= operator
	*
	* @param[in] date1 The date on the left of the operator
	* @param[in] date2 The date on the right of the operator
	* @return false if the date1 is not greater than date2
	* true if the date1 is greater than date2
	*/
	friend bool operator<=(const Date& date1, const Date& date2);
};


