#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct {
	string top;
	string middle;
	string botton;
}Number;



int main() {
	Number list[10];
	list[0] = { " _ ","| |","|_|" };
	list[1] = { "   ","  |","  |" };
	list[2] = { " _ "," _|","|_ " };
	list[3] = { " _ "," _|"," _|" };
	list[4] = { "   ","|_|","  |" };
	list[5] = { " _ ","|_ "," _|" };
	list[6] = { " _ ","|_ ","|_|" };
	list[7] = { " _ ","  |","  |" };
	list[8] = { " _ ","|_|","|_|" };
	list[9] = { " _ ","|_|"," _|" };
	
	string input;

	while (getline(cin,input)) {
		bool flag = false;
		string top, middle, botton;
		for (char n : input) {
			if (isdigit(n)) {
				//flag = true;
				int i;
				i = n - '0';
				top += list[i].top;
				middle += list[i].middle;
				botton += list[i].botton;
			}
		}
		
		cout << top << '\n' << middle << '\n' << botton << endl;
	}
}