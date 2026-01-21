#pragma once

#include "../User/user.h"
#include <vector>
#include <string>
#include <map>

/**
 * @brief Responsible for managing the users
 */
class UserManagement{
	public:
	std::map<char, std::vector<User>> users;

	public:
	/**
	 * @brief Adds a user to the map
	 *
	 * @param[in] user Reference of the User Object
	 */
	void Add(User& user);


	/**
	 * @brief Removes a user from the map
	 *
	 * @param[in] name User Name
	 * @param[in] id User Id
	 * @return 1 if user was removed 0 if user does not exist
	 */
	int Remove(const std::string& name, int id);
	
	/**
	 * @brief Removes a user from the map
	 *
	 * @param[in] key User name first letter (lowercase)
	 * @param[in] id User Id
	 * @return 1 if user was removed 0 if user does not exist
	 */
	int Remove(char key, int id);
	
	/**
	 * @brief Gets the User 
	 *
	 * @param[in] key User Name first letter (lowercase) 
	 * @param[in] id User Id 
	 */ 
	User* GetUser(char key, int id); 


	/**
	 * @brief Gets the User
	 *
	 * @param[in] name User name
	 * @param[in] id User Id
	 */
	User* GetUser(const std::string& name, int id);

	/**
	 * @brief Gets the user (read only)
	 *
	 * @param[in] name User Name
	 * @param[in] id User Id
	 */
	const User* GetUserReadOnly(const std::string& name, int id); 

	/**
	 * @brief Gets the user (read only)
	 *
	 * @param[in] key User Name first letter (lowercase) 
	 * @param[in] id User Id
	 */
	const User* GetUserReadOnly(char key, int id);

	void PrintUsers();	
};
