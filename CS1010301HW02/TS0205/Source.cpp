#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

typedef struct Bigint {
	string num;
}Bigint;

Bigint add(Bigint, Bigint);

int main() {
	int n;
	while (cin >> n) {
		for (int i = 0; i < n; i++) {
			Bigint a, b;
			bool notdigit = false;
			cin >> a.num;
			cin >> b.num;
			for (int j = 0; j < a.num.length(); j++) { //浪琩琌Τ獶计
				if (!isdigit(a.num[j])) {
					notdigit = true;
					break;
				}
			}
			for (int k = 0; k < b.num.length(); k++) { //浪琩琌Τ獶计
				if (!isdigit(b.num[k])) {
					notdigit = true;
					break;
				}
			}
			if (notdigit == true) {
				cout << "Not a valid number, please try again.\n";
			}
			else {
				cout << add(a, b).num << endl;
			}
		}
	}
}

Bigint add(Bigint a, Bigint b) {
	int carry = 0; //秈ノ跑计
	Bigint result;
	if (b.num.length() > a.num.length()) {
		swap(a, b); //耕计耚玡
	}
	int zero = (a.num.length() - b.num.length());
	while (zero--) {
		b.num = "0"+b.num; //耕计干0(﹃)
	}
	for (int i = a.num.length() - 1; i >= 0; i--) {
		int ans = (a.num[i] - '0') + (b.num[i] - '0') + carry;
		if (ans > 9) {
			carry = 1; //秈
		}
		else {
			carry = 0; //睲秈
		}
		result.num = (char)(ans % 10 + '0') + result.num;
	}						//玂痙计(锣じ)
	if (carry) {
		result.num = "1" + result.num; //程秈
	}
	return result;
}