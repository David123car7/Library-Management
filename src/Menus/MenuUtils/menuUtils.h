#pragma region 

#include <string>
#include "../../Date/date.h"

/**
 * @brief Does the input for the Date
 *
 * @return Returns the date converted from the input
 * @throws invalid_argument If the input is not a valid date
 */
Date InputDate();

/**
 * @brief Does the input for a integer value, only works for positive integers
 *
 * @return -1 if the input was invalid
 * positive number if the input was readed correctly
 */
int InputInteger();


