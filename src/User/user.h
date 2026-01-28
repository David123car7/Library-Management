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
		profile{UserProfile(state, occurrences)}{}
		
	const std::string& GetPhoneNumber() const {return phoneNumber;}
	const std::string& GetEmail() const {return email;}
	UserState GetState() const {return profile.state;}
	int GetOccurrences() const {return profile.occurrences;}
	Date GetBanExpireDate() const {return profile.banExpireDate;}

	int SetEmail(std::string email);
	int SetPhoneNumber(std::string phoneNumber);
	void SetState(UserState state) {profile.state = state;}
	void SetOccurrences(int value) {profile.occurrences = value;}
	void IncrementOccurrences() {profile.occurrences++;}
	void SetBanExpireDate(Date& date) {profile.banExpireDate = date;}

	friend std::ostream& operator<<(std::ostream& out, const User& user){
		return out << user.GetId() << " | " << user.GetName() << " | " << user.GetGender() << " | " << user.GetAge() << " | " 
			<< user.phoneNumber << " | " << user.email << " | " << user.profile.state << " | " << (int)user.profile.occurrences << 
			" | " << user.profile.banExpireDate;
	}

};
