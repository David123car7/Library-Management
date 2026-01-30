#include "userManagement.h"
#include "../User/user.h"
#include "../Utils/utils.h"
#include "../Constants/constants.h"
#include <string>
#include <fstream>
#include <stdexcept>

using namespace std;

int UserManagement::Add(const User& user, unsigned int id){
	if(UserExists(id)) return 0;
	users[id] = user;
	return 1;
}

int UserManagement::Add(std::string name, std::string gender, int age, std::string email, std::string phoneNumber){	
	if(name.empty()) throw invalid_argument("Name cant be empty.");
	if(gender.empty()) throw invalid_argument("Gender cant be empty.");
	if(age < 0 || age > 120) throw invalid_argument("Age is invalid");
	if(email.empty()) throw invalid_argument("Enail cant be empty");
	if(phoneNumber.empty()) throw invalid_argument("PhoneNumber cant be empty");

	int id;
	if(users.empty())
		id = 0;
	else{
		auto it = users.crbegin();
		id = it->first;
		id++;
	}
	users[id] = User(id, name, gender, age, email, phoneNumber, UserState::active, 0);
	return id;
}

User* UserManagement::GetUser(unsigned int id){
	if(!users.contains(id)) return nullptr;
	return &users[id];
}

const User* UserManagement::GetUser(unsigned int id) const{
	if(!users.contains(id)) return nullptr;
	return &users.at(id);
}

int UserManagement::Remove(unsigned int id){
	if(!users.contains(id)) return 0;
	users.erase(id);
	return 1;
}

int UserManagement::ReadDataFromFile(){
	ifstream rf{USERS_FILE_NAME, ios::binary};
	if(!rf) return 0;
	while(rf.peek() != EOF){
		unsigned int id, age;
		uint8_t occurrences;
		UserState state;
		string name, gender, email, phoneNumber;
		Date banExpireDate;
		rf.read(reinterpret_cast<char*>(&id), sizeof(id));
		ReadBinaryToString(rf, name);
		ReadBinaryToString(rf, gender);
		rf.read(reinterpret_cast<char*>(&age), sizeof(age));
		ReadBinaryToString(rf, phoneNumber);
		ReadBinaryToString(rf, email);
		rf.read(reinterpret_cast<char*>(&state), sizeof(state));
		rf.read(reinterpret_cast<char*>(&occurrences), sizeof(occurrences));
		rf.read(reinterpret_cast<char*>(&banExpireDate), sizeof(banExpireDate));
		User user(id, name, gender, age, phoneNumber, email, state, occurrences);
		Add(user, id);
	}
	rf.close();
	return 1;
}

int UserManagement::StoreDataInFile(){
	ofstream wf{USERS_FILE_NAME, ios::binary};
	if(!wf) return 0;
	for(auto& [key, user]: users){
		unsigned int id = user.GetId();
		unsigned int age = user.GetAge();
		UserState state = user.GetState();
		Date banExpireDate = user.GetBanExpireDate();
		uint8_t occurrences = user.GetOccurrences();
		wf.write(reinterpret_cast<char*>(&id), sizeof(id));
		StoreStringToBinary(wf, user.GetName());
		StoreStringToBinary(wf, user.GetGender());
		wf.write(reinterpret_cast<char*>(&age), sizeof(age));
		StoreStringToBinary(wf, user.GetPhoneNumber());
		StoreStringToBinary(wf, user.GetEmail());
		wf.write(reinterpret_cast<char*>(&state), sizeof(state));
		wf.write(reinterpret_cast<char*>(&occurrences), sizeof(occurrences));
		wf.write(reinterpret_cast<char*>(&banExpireDate), sizeof(banExpireDate));
	}
	wf.close();
	return 1;
}

void UserManagement::PrintUsers(){
	for(const auto& [key, user]: users){
		cout << user << "\n";
	}
}

int UserManagement::PrintUser(unsigned int id){
	const User* user = GetUser(id);
	if(user == nullptr) return 0;
	cout << user;
	return 1;
}

bool UserManagement::UserExists(unsigned int id){
	if(users.contains(id)) return true;
	else return false;
}





