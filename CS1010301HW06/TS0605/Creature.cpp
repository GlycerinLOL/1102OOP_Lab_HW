#include "Creature.h"
#include "Diary.h"
#define RUN

vector<day_log> Diary::day;

void PrintO(string input) {
#ifdef DEBUG
	cout << input;
#endif
}

bool compareString(bodyPart a, bodyPart b) {
	return a.body < b.body;
}


Creature::Creature(string name) {
	string debugOutput = "Creature " + name + '(' + name + ")//";
	PrintO(debugOutput);
	this->name = name;
	start = Diary::day.size() - 1;

}

Creature::Creature(string name, Creature pCreature) {
	string debugOutput = "Creature " + name + '(' + name + ',' + pCreature.name + ")//";
	PrintO(debugOutput);
	this->name = name;
	full = pCreature.full;
	start = Diary::day.size() - 1;

}


Creature& Creature::operator[](string name) {
	string debugOutput = this->name + "[\""+name + "\"]";
	PrintO(debugOutput);
	for (unsigned int i = 0; i < full.size(); i++) {
		if (name == full[i].body) {
			index = i;
			return *this;
		}
	}
	index = full.size();
	bodyPart temp = { name,0 };
	full.push_back(temp);
	return *this;
}

void Creature::operator=(int input) {
	string debugOutput = '=' + to_string(input) + "//";
	PrintO(debugOutput);
	string output;
	string bodyname = full[index].body;
	int old = full[index].amount;
	full[index].amount = input;
	if (old == 0 && input) {
		output += name + "'s " + bodyname + " appeared" + " (" + to_string(old) + " -> " + to_string(input) + ")." + '\n';
	}
	else if (input > old) {
		output += name + "'s " + bodyname + " increased" + " (" + to_string(old) + " -> " + to_string(input) + ")." + '\n';
	}
	else if (input < old) {
		output += name + "'s " + bodyname + " decreased" + " (" + to_string(old) + " -> " + to_string(input) + ")." + '\n';
	}
	else if (input == old) {
		return;
	}
	Diary::NewEvent(name, output);
}

void Creature::operator+=(int input) {
	string debugOutput = "+=" + to_string(input) + "//";
	PrintO(debugOutput);
	string output;
	string bodyname = full[index].body;
	if (input == 0) {
		return;
	}
	int old = full[index].amount;
	full[index].amount += input;
	if (old == 0 && input) {
		output += name + "'s " + bodyname + " appeared" + " (" + to_string(old) + " -> " + to_string(input) + ")." + '\n';
	}
	else if( input > 0 ) {
		output += name + "'s " + bodyname + " increased" + " (" + to_string(old) + " -> " + to_string(full[index].amount) + ")." + '\n';
	}
	else {
		output += name + "'s " + bodyname + " decreased" + " (" + to_string(old) + " -> " + to_string(full[index].amount) + ")." + '\n';
	}
	Diary::NewEvent(name, output);
	return;
}

void Creature::operator-=(int input) {
	string debugOutput = "-=" + to_string(input) + "//";
	PrintO(debugOutput);
	string output;
	string bodyname = full[index].body;
	if (input == 0) {
		return;
	}
	int old = full[index].amount;
	full[index].amount -= input;
	if (full[index].amount < 0) {
		full[index].amount = 0;
	}
	if (input < 0) {
		if (old == 0) {
			output += name + "'s " + bodyname + " appeared" + " (" + to_string(old) + " -> " + to_string(full[index].amount) + ")." + '\n';
		}
		else {
			output += name + "'s " + bodyname + " increased" + " (" + to_string(old) + " -> " + to_string(full[index].amount) + ")." + '\n';
		}
	}
	else {
		output += name + "'s " + bodyname + " decreased" + " (" + to_string(old) + " -> " + to_string(full[index].amount) + ")." + '\n';
	}
	Diary::NewEvent(name, output);
}

void Creature::PrintStatus() {
	string debugOutput = name + ".PrintStatus( )//";
	PrintO(debugOutput);
#ifdef RUN
	sort(full.begin(), full.end(), compareString);
	cout << name + "'s status:\n";
	for (int i = 0; i < full.size(); i++) {
		if (full[i].amount != 0) {
			cout << full[i].body << " * " << full[i].amount << '\n';
		}
	}
	cout << '\n';
#endif
}

void Creature::PrintLog() {
	string debugOutput = name + ".PrintLog( )//";
	PrintO(debugOutput);
#ifdef RUN
	cout << name << "'s log:" << '\n';
	for (int i = start; i < Diary::day.size(); i++) {
		cout << "Day " << Diary::day[i].dayName << '\n';
		for (int j = 0; j < Diary::day[i].event_list.size(); j++) {
			if (Diary::day[i].event_list[j].name == name) {
				cout << Diary::day[i].event_list[j].content;
			}
		}
	}
	cout << '\n';
#endif 
}


