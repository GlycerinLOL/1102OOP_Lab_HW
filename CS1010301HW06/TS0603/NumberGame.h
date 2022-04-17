#pragma once
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class NumberGame {
private:
	int A;
	vector<int> valid;
	vector<int> result;
	string filename;
public:
	void SetInput(int a) {
		A = a;
	}
	void ProcessInput();
	void SetFileName(string name) {
		filename = name;
	}
	void LoadNumberList();
	void PrintAllValid();
	void Reset();
};