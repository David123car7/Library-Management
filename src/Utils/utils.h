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

std::vector<std::string> ParseString(const std::string& line, char c);

void StoreStringToBinary(std::ofstream& wf, const std::string& value);
void ReadBinaryToString(std::ifstream& rf, std::string& value);

Date StringToDate(std::string& value);

