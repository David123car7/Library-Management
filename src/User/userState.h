#pragma once
#include <ostream>

/**
 * @brief Represents the current status of a user account.
 */
enum class UserState{
	active,
	banned,
};

std::ostream& operator<<(std::ostream& out, UserState state);

