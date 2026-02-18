#pragma once

#include "../../Library/library.h"

/**
 * @brief Displays the User Menu
 *
 */
void DisplayUserMenu();

/**
 * @brief User Menu Functionality
 *
 * @param[[TODO:direction]] library [TODO:description]
 */
void UserMenu(Library& library);

/**
 * @brief Add User Funcionality
 *
 * @param[in] library Reference to the library object
 */
void AddUserIO(Library& library);

/**
 * @brief Removes a user funcionality
 *
 * @param[in] library Reference to the library object
 */
void RemoveUserIO(Library& library);

/**
 * @brief Prints a user funcionality
 *
 * @param[in] library Reference to the library object
 */
void PrintUserIO(Library& library);

/**
 * @brief Prints all user loans funcionality
 *
 * @param[in] library Reference to the library object
 */
void PrintUserLoansIO(Library& library);

/**
 * @brief Prints all book a user loans funcionality
 *
 * @param[in] library Reference to the library object
 */
void PrintBooksUserLoansIO(Library& library);





