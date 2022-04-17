#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct {
public:
	string body;
	int amount;
}bodyPart;

class Creature {
public:
	Creature(string name);
	Creature(string name, Creature pCreature);
	Creature& operator[](string name);
	void operator=(int input);
	void operator+=(int input);
	void operator-=(int input);
	void PrintStatus();
	void PrintLog();
private:
	vector<bodyPart> full;
	vector<string> log;
	string name;
	string date;
	int index = 0;
	int start;
	int dayIndex;
};