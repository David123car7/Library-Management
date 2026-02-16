#include "utils.h"
#include <sstream>

using namespace std;

bool isInvalidString(const string& x){
	if(isspace(x[0])) return true;
	else return false;
}

int GetMonthDays(uint8_t month, unsigned int year){
	static constexpr const std::array<uint8_t, 12> month_days = {31,28,31,30,31,30,31,31,30,31,30,31};
	if(month > 12) return -1;
	if(month == 2){
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
			return 29;
		}
	}
	return month_days[month];	
}

vector<string> ParseString(const string& line, char c){
	stringstream s(line);
	string word{};
	vector<string> output;
	while(getline(s,word, c)){
		output.push_back(word);	
	}
	return output;
}

void StoreStringToBinary(ofstream& wf, const string& value){
	size_t len = value.size();
	wf.write(reinterpret_cast<char*>(&len), sizeof(len));
	if(len > 0) wf.write(value.c_str(), len);
}

void ReadBinaryToString(ifstream& rf, string& value){
	size_t len;
	rf.read(reinterpret_cast<char*>(&len), sizeof(len));
	value.resize(len);
	rf.read(&value[0], len);
}

Date StringToDate(std::string& value){
	vector<string> dateParsed = ParseString(value, '/');
	if(dateParsed.empty()) throw invalid_argument("Invalid Date: " + value);
	int day = stoi(dateParsed[0]);
	int month = stoi(dateParsed[1]);
	int year = stoi(dateParsed[2]);
	Date date((uint8_t)day, (uint8_t)month, (uint16_t)year);
	return date;
}
