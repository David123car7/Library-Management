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

	/**
	 * @brief Adds a user to the user map
	 *
	 * @param[in] user Reference to the user object
	 * @param[in] id User ID
	 * @return 0 if the user allready exists
	 * 1 if the user was added
	 */
	int Add(const User& user, unsigned int id);

	public:

	/**
	 * @brief Adds a user to the map of users
	 *
	 * @param[in] name User Name
	 * @param[in] gender User Gender
	 * @param[in] age User Age
	 * @param[in] email User Email 
	 * @param[in] phoneNumber User PhoneNumber 
	 * @return user id that was added
	 */
	int Add(std::string name, std::string gender, int age, std::string email, std::string phoneNumber);

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

	/**
	 * @brief Stores user data in binary file
	 *
	 * @return 0 if the data was not stored,
	 * 1 if the data was stored
	 */
	int StoreDataInFile();

	/**
	 * @brief Reads user data from a binary file
	 *
	 * @return 0 if the user data was not readed, 
	 * 1 if the user data was readed and loaded
	 */
	int ReadDataFromFile();

	/**
	 * @brief Prints a user
	 *
	 * @param[in] id User Id
	 * @return 0 if the user does not exist,
	 * 1 if the user exists
	 */
	int PrintUser(unsigned int id);

	/**
	 * @brief Prints all Users
	 *
	 */
	void PrintUsers();	
};
