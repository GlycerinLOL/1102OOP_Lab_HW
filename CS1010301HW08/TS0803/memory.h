#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class Memory
{
public:
	vector<int> data;
	int size;
	Memory();
	Memory(int size);
	void setMemory(int location, string type, string val);
	void getMemory(int location, string type);
};
long long stringToInt(string s);