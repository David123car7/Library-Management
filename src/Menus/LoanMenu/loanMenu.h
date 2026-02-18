#pragma once

#include "../../Library/library.h"

/**
 * @brief Displays the loan menu
 *
 */
void DisplayLoanMenu();

/**
 * @brief Loan menu funcionality
 *
 * @param[in] library Reference to the library object
 */
void LoanMenu(Library& library);

/**
 * @brief Add loan funcionality
 *
 * @param[in] library Reference to the library object
 */
void AddLoanIO(Library& library);

/**
 * @brief Deliver loan funcionality
 *
 * @param[in] library Reference to the library object
 */
void DeliverLoanIO(Library& library);

/**
 * @brief Finish loan funcionality
 *
 * @param[in] library Reference to the library object
 */
void FinishLoanIO(Library& library);

/**
 * @brief Print loan funcionality
 *
 * @param[in] library Reference to the library object
 */
void PrintLoanIO(Library& library);

/**
 * @brief Print all loans funcionality
 *
 * @param[in] library Reference to the library object
 */
void PrintLoansIO(Library& library);
