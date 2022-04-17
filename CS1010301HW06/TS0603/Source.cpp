#include "NumberGame.h"
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

void NumberGame::ProcessInput() {
	int length = to_string(A).length();
	int max = pow(2.0,(double)length);
	for (int i = 1; i < max; i++) {
		int sum = 1;
		bitset<32> num(i);
		for (int j = 0; j < length; j++) {
			if (num[j] == 1) {
				sum *= (to_string(A)[j] - '0');
			}
		}
		valid.push_back(sum);
	}
}

void NumberGame::LoadNumberList() {
	fstream file;
	file.open(filename, ios::in);
	int temp;
	vector<int> test;
	while (file >> temp) {
		test.push_back(temp);
		for (int i = 0; i < valid.size(); i++) {
			if (temp == valid[i]) {
				result.push_back(temp);
				break;
			}
		}
	}
#ifdef DEBUG
	for (int i = 0; i < 50;i++) {
		cout << test[i] << '+';
	}
#endif
}

void NumberGame::PrintAllValid() {
	for (int n : result) {
		cout << n << endl;
	}
}

void NumberGame::Reset() {
	result.clear();
	valid.clear();
	filename = "";
	A = 0;
}