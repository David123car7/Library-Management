#pragma once
#include <ostream>

enum class UserState{
	active,
	banned,
};

std::ostream& operator<<(std::ostream& out, UserState& state);

