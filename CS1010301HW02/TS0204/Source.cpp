#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class employer {
public:
	string name;
	string salary;
	string bonus;
};

int main() {
	int n;
	while (cin >> n) {
		int maxw1 = 0, maxw2 = 0, maxw3 = 0;
		employer* people = new employer[n];
		for (int i = 0; i < n; i++) {
			string temp[3];
			cin >> temp[0] >> temp[1] >> temp[2];
			if (maxw1 < temp[0].size()) {
				maxw1 = temp[0].size();
			}
			if (maxw2 < temp[1].size()) {
				maxw2 = temp[1].size();
			}
			if (maxw3 < temp[2].size()) {
				maxw3 = temp[2].size();
			}
			people[i].name = temp[0];
			people[i].salary = temp[1];
			people[i].bonus = temp[2];
		}
		for (int j = 0; j < n; j++) {
			cout << setw(maxw1) << people[j].name << '|';
			cout << setw(maxw2 + 2) << people[j].salary << '|';
			cout << setw(maxw3 + 2) << people[j].bonus << endl;
		}
	}
	return 0;
	
}