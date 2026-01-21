#include "loan.h"

using namespace std;


/**
 * @brief Starts the loan by changing the book state to loaned.
 *
 * @param[in] currentDate The current date when the function is called.
 * @return 0 if the current date is greater than the end date of the loan.
 * 1 if the loan state is changed successfully.
 */
int Loan::StartLoan(Date& currentDate){
	if(currentDate > endDate) return 0;
	state = LoanState::loaned;
	return 1;
} 


/**
 * @brief Finishes the loan by changing the loan state to finished.
 *
 * @param[in] currentDate The current date when the function is called
 * @return -1 if the current date is greater than the endDate
 * 1 if the current date is lesser than the endDate 
 * (In all cases the loan state is changed)
 */
int Loan::FinishLoan(Date& currentDate){
	state = LoanState::finished;
	if(currentDate > endDate) return -1;
	return 1;
}
