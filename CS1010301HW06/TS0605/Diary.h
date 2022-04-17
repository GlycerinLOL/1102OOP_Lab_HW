#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
	string name;
	string content;
}event;

typedef struct {
	string dayName;
	vector<event> event_list;
}day_log;
 
class Diary {
public:
	static void NewDay(string day);
	static void NewEvent(string Cname, string input);
	static vector<day_log> day;
};