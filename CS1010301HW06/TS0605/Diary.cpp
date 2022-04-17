#include "Diary.h"
#define RUN


void Diary::NewDay(string input) {
	string debugOutput = "Diary::NewDay(\"" + input + "\")//";
	//cout << debugOutput;
	day_log new_day;
	new_day.dayName = input;
	day.push_back(new_day);
}

void Diary::NewEvent(string Cname, string input) {
	event new_event;
	new_event.name = Cname;
	new_event.content = input;
	day[day.size() - 1].event_list.push_back(new_event);
}