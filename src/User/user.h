#pragma once

#include <iostream>
#include "../Person/person.h"
#include <string>
#include "userState.h"
#include "userProfile.h"
#include <cstdint> 
#include <vector>

/**
 * @brief Class that represents the user
 * Future Improvements: Add binary search to the vector of current loans
 */
class User: public Person{
	private:
	std::string phoneNumber;
	std::string email;
	UserProfile profile;
	uint16_t currentLoans;

	public:
	User(): phoneNumber{""}, email{""}{}

	/**
	 * @brief Constructor for the user
	 *
	 * @param[in] id Person Id
	 * @param[in] name Person Name
	 * @param[in] gender Person Gender
	 * @param[in] age Person Age
	 * @param[in] phoneNumber Phone Number
	 * @param[in] email Person Email
	 */
	User(unsigned int id, std::string name, std::string gender, int age, std::string phoneNumber, std::string email, 
			UserState state, int occurrences): 
		Person(id, name, gender, age),
		phoneNumber{phoneNumber},
		email{email},
		profile{UserProfile(state, occurrences)},  
		currentLoans{0} {}
		
	const std::string& GetPhoneNumber() const {return phoneNumber;}
	const std::string& GetEmail() const {return email;}
	UserState GetState() const {return profile.state;}
	int GetOccurrences() const {return profile.occurrences;}
	Date GetBanExpireDate() const {return profile.banExpireDate;}
	int GetCurrentLoans() const {return currentLoans;}

	int SetEmail(std::string email);
	int SetPhoneNumber(std::string phoneNumber);
	void SetUserState(UserState state) {profile.state = state;}
	void IncrementUserOccurrences() {profile.occurrences++;}
	void SetUserBanExpireDate(Date& date) {profile.banExpireDate = date;}
	void IncrementCurrentLoans() {currentLoans++;}
	void DecrementCurrentLoans() {currentLoans--;}

	friend std::ostream& operator<<(std::ostream& out, const User& user){
		return out << user.GetId() << " " << user.GetName() << " " << user.GetGender() << " " << user.GetAge() << " " << user.phoneNumber << " " << user.email;
	}

};
