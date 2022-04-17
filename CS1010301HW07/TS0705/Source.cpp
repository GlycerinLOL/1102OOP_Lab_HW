#include <iostream>
#include <string>

using namespace std;


//4¶i¦ì
//V=0 U=1 C=2 D=3
int toNum(string a) {
	int sum = 0;
	int len = a.length();
	for (int i = 0; i < len; i++) {
		switch (a[i]) {
		case 'V':
			sum = sum * 4 + 0;
			break;
		case 'U':
			sum = sum * 4 + 1;
			break;
		case 'C':
			sum = sum * 4 + 2;
			break;
		case 'D':
			sum = sum * 4 + 3;
			break;
		default:
			break;
		}
	}
	return sum;
}

int main() {
	int case_n;
	cin >> case_n;
	cout << "COWCULATIONS OUTPUT" << endl;
	for (int i = 0; i < case_n; i++) {
		string cow1;
		string cow2;
		string result;
		cin >> cow1 >> cow2;
		int num1 = toNum(cow1);
		int num2 = toNum(cow2);
		for (int j = 0; j < 3; j++) {
			char operation;
			cin >> operation;
			switch (operation) {
			case 'A':
				num2 = num1 + num2;
				break;
			case 'R':
				num2 = num2 / 4;
				break;
			case 'L':
				num2 = num2 * 4;
				break;
			case 'N':
				break;
			}
		}
		cin >> result;
		if (toNum(result) == num2) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;
}