#pragma once
#include "userState.h"
#include "../Date/date.h"
#include <cstdint>

/**
 * struct UserProfile - Struct that holds user related data to determine his state
 */
struct UserProfile{
	UserState state;
	uint8_t occurrences;
	Date banExpireDate;

	UserProfile(): state{UserState::active}, occurrences{0}, banExpireDate{} {}
	UserProfile(UserState state, uint8_t occurrences, const Date& banExpireDate):
		state{state},
		occurrences{occurrences},
		banExpireDate{banExpireDate} {}
	UserProfile(UserState state, uint8_t occurrences):
		state{state},
		occurrences{occurrences},
		banExpireDate{} {}
};

