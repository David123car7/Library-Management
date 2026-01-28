#include "loan.h"
#include <ostream>

using namespace std;

ostream& operator<<(ostream& out, LoanState state){
	switch(state){
		case LoanState::toPickUp: return out << "To Pick Up";
		case LoanState::loaned: return out << "Loaned";
		case LoanState::finished: return out << "Finished";
		default: return out << "Unknown State";
	}
}
