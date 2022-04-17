#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#define RUN

using namespace std;

bool check(vector<vector<int>> num) {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < 9; i += 3) {
		for (int j = 0; j < 9; j++) {
			for (int k = 0; k < 3; k++) {
				count++;
				sum += num[j][k + i];
				if (count == 9) {
					if (sum != 45) {
						return false;
					}
					else {
						sum = 0;
						count = 0;
					}
				}
			}
		}
	}
	return true;
}

int main() {
	int count = 0;
	vector<int> tempv;
	vector<vector<int>> num;
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
	while (cin) {
		int temp;
		if (cin.peek() == ',' || cin.peek() == '\n') {
			cin.get();
			continue;
		}
		else {
			cin >> temp;
			tempv.push_back(temp);
			if (tempv.size() == 9) {
				num.push_back(tempv);
				tempv.clear();
			}
			count++;
			
		}
		if (count == 81) {
			bool isCorrect = check(num);
			if (isCorrect) {
				cout << "True" << endl;
			}
			else {
				cout << "False" << endl;
			}
			count = 0;
			num.clear();
		}
	}
#endif
}