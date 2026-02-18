#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "../Constants/constants.h"
#include "../Date/date.h"

/**
 * @brief Gets the days a month has
 *
 * @param[in] year Year the month belongs to
 * @param[in] month Month
 * @return the number of days the month has,
 * -1 if the month was invalid
 */
int GetMonthDays(uint8_t month, unsigned int year);

/**
 * @brief Checks if the string is valid by cheking if the first letter is not a empty char
 *
 * @param[in] x reference to a string
 * @return true if the string is valid 
 * false if the string is not valid
 */
bool isInvalidString(const std::string& x);

/**
 * @brief Parses a string
 *
 * @param[in] line string to be parsed
 * @param[in] c char that will divide the string
 * @return a vector<string> with the string parsed
 */
std::vector<std::string> ParseString(const std::string& line, char c);

/**
 * @brief Stores a string into binary file
 *
 * @param[in, out] wf Reference to a ofstream 
 * @param[in] value Reference to a string
 */
void StoreStringToBinary(std::ofstream& wf, const std::string& value);

/**
 * @brief Reads from a binary file
 *
 * @param[in, out] rf Reference to a ifstream 
 * @param[in] value Reference to a string
 */
void ReadBinaryToString(std::ifstream& rf, std::string& value);

/**
 * @brief Converts a string to a date
 *
 * @param[in] value Reference to a string
 * @return the converted date 
 * @throws invalid_argument If the string is not a valid date
 * */
Date StringToDate(std::string& value);

