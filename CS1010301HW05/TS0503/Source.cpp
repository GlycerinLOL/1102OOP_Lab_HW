#include <iostream>
#include <string>
#include <vector>
#define RUN

using namespace std;

typedef struct {
	string firstName;
	string lastName;
	string phone;
}stRec;
int search(stRec, vector<stRec>&);
bool isNum(string);


void insert(stRec temp, vector<stRec>& data) {
	if (data.size() < 10 && search(temp, data) == 99) {
		data.push_back(temp);
	}
	else {
		cout << "Insert Error" << endl;
	}
}


void del(stRec temp, vector<stRec>& data) {
	int index = search(temp, data);
	if (index != 99) {
		data.erase(data.begin() + index);
	}
	else {
		cout << "Delete Error" << endl;
	}
}

int search(stRec temp, vector<stRec>& data) {
	for (int i = 0; i < data.size(); i++) {
		if (data[i].firstName == temp.firstName && data[i].lastName == temp.lastName && data[i].phone == temp.phone) {
			return i;
		}
	}
	return 99;
	
}

void print(vector<stRec> data) {
	if (data.size() != 0) {
		for (stRec temp : data) {
			cout << temp.firstName << ' ' << temp.lastName << ' ' << temp.phone << endl;
		}
	}
	else {
		cout << "Print Error" << endl;
	}
}

bool errorCheck(stRec temp) { //false == error
	if (temp.firstName.length() > 25 || temp.lastName.length() > 30 || temp.phone.length() > 15) {
		cout << "Input Error" << endl;
		return false;
	}
	else if (!isNum(temp.phone)) {
		cout << "Input Error" << endl;
		return false;
	}
	else {
		return true;
	}
}

bool isNum(string ph) {
	for (const char c : ph) {
		if (isdigit(c) == 0) {
			return false;
		}
	}
	return true;
}


int main() {
#ifdef DEBUG
	string temp;
	vector<string> input;
	while (cin) {
		getline(cin, temp);
		input.push_back(temp);
		input.push_back("+");
	}
	for (string n : input) {
		cout << n;
	}
	
#endif
#ifdef RUN
	string command;
	vector<stRec> data;
	while (cin >> command) {
		stRec temp;
		if (command == "insert") {
			cin >> temp.firstName >> temp.lastName >> temp.phone;
			if (errorCheck(temp)) {
				insert(temp, data);
			}
		}
		else if (command == "delete") {
			cin >> temp.firstName >> temp.lastName >> temp.phone;
			if (errorCheck(temp)) {
				del(temp, data);
			}
		}
		else if (command == "search") {
			cin >> temp.firstName >> temp.lastName >> temp.phone;
			if (errorCheck(temp)) {
				int index = search(temp,data);
				if (index != 99) {
					cout << index << endl;
				}
				else {
					cout << "Search Error" << endl;
				}
			}
		}
		else if (command == "print") {
			print(data);
		}
		else {
			cout << "Input Error" << endl;
		}
	}
#endif
}