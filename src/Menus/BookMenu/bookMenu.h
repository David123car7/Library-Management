#pragma once

#include "../../Library/library.h"

/**
 * @brief Displays the book menu
 *
 */
void DisplayBookMenu();

/**
 * @brief Book menu funcionality
 * @param[in] library Reference to the library object
 */
void BookMenu(Library& library);

/**
 * @brief Add Book funcionality 
 * @param[in] library Reference to the library object
 */
void AddBookIO(Library& library);

/**
 * @brief Remove Book funcionality 
 * @param[in] library Reference to the library object
 */
void RemoveBookIO(Library& library);

/**
 * @brief Print Book funcionality 
 * @param[in] library Reference to the library object
 */
void PrintBookIO(Library& library);
