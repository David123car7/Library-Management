#pragma once
#include "../User/user.h"
#include <vector>
#include <string>
#include <map>

/**
 * @brief Responsible for managing the users
 */
class UserManagement{
	private:
	std::map<unsigned int, User> users;

	public:

	/**
	 * @brief Adds a user to the map of users
	 *
	 * @param[in] name User Name
	 * @param[in] gender User Gender
	 * @param[in] age User Age
	 * @param[in] email User Email 
	 * @param[in] phoneNumber User PhoneNumber 
	 */
	void Add(std::string name, std::string gender, int age, std::string email, std::string phoneNumber);

	/**
	 * @brief Removes a user from the map
	 *
	 * @param[in] id User Id
	 * @return 1 if user was removed 0 if user does not exist
	 */
	int Remove(unsigned int id);
	
	/**
	 * @brief Gets the User 
	 *
	 * @param[in] id User Id 
	 */ 
	User* GetUser(unsigned int id); 

	/**
	 * @brief Gets the user (read only)
	 * @param[in] id User Id
	 */
	const User* GetUser(unsigned int id) const; 
	
	/**
	 * @brief Checks if the user with the id exists
	 *
	 * @param[in] id User Id
	 * @return true if user exists, false if does not exist
	 */
	bool UserExists(unsigned int id);

	int PrintUser(unsigned int id);
	void PrintUsers();	
};
