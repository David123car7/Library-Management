#include "loanManagement.h"
#include "../Utils/utils.h"
#include <fstream>

using namespace std;

int LoanManagement::GetNextId(){
	int id;
	if(loans.empty()) id = 0;
	else{
		auto it = loans.crbegin();
		id = it->first;
		id++;
	}
	return id;
}

int LoanManagement::Add(Loan& loan){
	int id = loan.GetId();
	if(LoanExists(id)) return 0;
	loans[id] = loan;
	return 1;
}

int LoanManagement::Add(unsigned int bookId, unsigned int userId, const Date& startDate, const Date& endDate, const Date& deliveredDate ,LoanState state){
	int id = GetNextId();
	Loan loan(id, bookId, userId, startDate, endDate, deliveredDate, state);
	loans[id] = loan;
	return id;
}

int LoanManagement::Remove(unsigned int id){
	if(!loans.contains(id)) return 0;
	loans.erase(id);
	return 1;
}

Loan* LoanManagement::GetLoan(unsigned int id){
	if(!loans.contains(id)) return nullptr;
	return &loans.at(id);
}

const Loan* LoanManagement::GetLoan(unsigned int id) const{
	if(!loans.contains(id)) return nullptr;
	return &loans.at(id);
}

bool LoanManagement::LoanExists(unsigned int id){
	if(!loans.contains(id)) return false;
	else return true;
}

bool LoanManagement::ExistsKeyUserMap(unsigned int key){
	return loansUserMap.contains(key);
}

bool LoanManagement::ExistsKeyBookMap(unsigned int key){
	return loansBookMap.contains(key);
}

const vector<unsigned int>* LoanManagement::GetUserLoanIds(unsigned key){
	if(!ExistsKeyUserMap(key)) return nullptr;
	return &loansUserMap[key];
}

bool LoanManagement::LoanIdUserMapExists(unsigned int key, unsigned int id){
	if(!ExistsKeyUserMap(key)) return false;
	vector<unsigned int>& ids = loansUserMap[key];
	for(unsigned int i=0; i<ids.size(); i++){
		if(ids[i] == id)
			return true;
	}
	return false;
}

bool LoanManagement::LoanIdBookMapExists(unsigned int key, unsigned int id){
	if(!ExistsKeyBookMap(key)) return false;
	vector<unsigned int>& ids = loansBookMap[key];
	for(unsigned int i=0; i<ids.size(); i++){
		if(ids[i] == id)
			return true;
	}
	return false;
}

int LoanManagement::AddIdUserMap(unsigned int key, unsigned int id){
	if(LoanIdUserMapExists(key, id)) return 0;
	loansUserMap[key].push_back(id);
	return 1;
}


int LoanManagement::RemoveIdUserMap(unsigned int key, unsigned int id){
	if(!ExistsKeyUserMap(key)) return 0;
	vector<unsigned int>& ids = loansUserMap[key];
	for(unsigned int i=0; i<ids.size(); i++){
		if(ids[i] == id){
			ids[i] = ids.back();
			ids.pop_back();
			return 1;
		}
	}
	return 0;
}

int LoanManagement::AddIdBookMap(unsigned int key, unsigned int id){
	if(LoanIdBookMapExists(key, id)) return 0;
	loansUserMap[key].push_back(id);
	return 1;
}


int LoanManagement::RemoveIdBookMap(unsigned int key, unsigned int id){
	if(!ExistsKeyBookMap(key)) return 0;
	vector<unsigned int>& ids = loansBookMap[key];
	for(unsigned int i=0; i<ids.size(); i++){
		if(ids[i] == id){
			ids[i] = ids.back();
			ids.pop_back();
			return 1;
		}
	}
	return 0;
}

int LoanManagement::GetUserMapSize(unsigned int key){
	if(!ExistsKeyUserMap(key)) return 0;
	return loansUserMap[key].size();
}

int LoanManagement::StoreDataInFile(){
	ofstream wf{LOANS_FILE_NAME};
	if(!wf) return 0;
	for(auto& [key, loan]: loans){
		wf << loan.GetId() << "," << loan.GetBookId() << "," << loan.GetUserId() << "," << loan.GetStartDate() << "," << loan.GetEndDate()
			<< "," << loan.GetDeliveredDate() << "," << loan.GetState() << "\n";
	}
	return 1;
}

int LoanManagement::ReadDataFromFile(){
	ifstream rf{LOANS_FILE_NAME, ios::in};
	if(!rf) return 0;
	string line{};
	while(getline(rf,line)){
		vector<string> words = ParseString(line, ',');		
		for(unsigned int i=0; i<words.size(); i++){
			unsigned int id = stoi(words[0]);
			unsigned int bookId = stoi(words[1]);
			unsigned int userId = stoi(words[2]);
			Date startDate = StringToDate(words[3]);
			Date endDate = StringToDate(words[4]);
			Date deliveredDate = StringToDate(words[5]);
			LoanState state = StringToLoanState(words[6]);
			Loan loan(id, bookId, userId, startDate, endDate, deliveredDate, state);
			Add(loan);	
		}
	}
	return 1;
}

void LoanManagement::PrintLoans(){
	for(auto& [key, loan]: loans){
		cout << loan << "\n";
	}
}

int LoanManagement::PrintLoan(unsigned int id){
	const Loan* loan = GetLoan(id);
	if(loan == nullptr) return 0;
	cout << *loan;
	return 1;
}

int LoanManagement::PrintUserLoans(unsigned int userId){
	if(!ExistsKeyUserMap(userId)) return 0;
	vector<unsigned int>& ids = loansUserMap[userId];
	for(unsigned int i=0; i<ids.size(); i++){
		const Loan* loan = GetLoan(ids[i]);
		if(loan != nullptr)
			cout << *loan << "\n";
	}
	return 1;
}
