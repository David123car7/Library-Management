#pragma once
#include "userState.h"
#include "../Date/date.h"
#include <cstdint>

/**
 * @brief Struct that holds user related data to determine his state
 */
struct UserProfile{
	UserState state;
	uint8_t occurrences;
	Date banExpireDate;

	/**
	 * @brief Default User Profile constructor that initializes the object
	 *
	 */
	UserProfile(): state{UserState::active}, occurrences{0}, banExpireDate{} {}
	
	/**
	 * @brief Constructs the User Profile
	 *
	 * @param[in] state User State 
	 * @param[in] occurrences Number of occurrences 
	 * @param[in] banExpireDate Ban Expire Date
 	 */
	UserProfile(UserState state, uint8_t occurrences, const Date& banExpireDate):
		state{state},
		occurrences{occurrences},
		banExpireDate{banExpireDate} {}
	
	/**
	 * @brief Constructs the User Profile
	 *
	 * @param[in] state User State 
	 * @param[in] occurrences Number of occurrences 
 	 */
	UserProfile(UserState state, uint8_t occurrences):
		state{state},
		occurrences{occurrences},
		banExpireDate{} {}
};

