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
			for (int j = 0; j < a.num.length(); j++) { //�ˬd�O�_���D�Ʀr
				if (!isdigit(a.num[j])) {
					notdigit = true;
					break;
				}
			}
			for (int k = 0; k < b.num.length(); k++) { //�ˬd�O�_���D�Ʀr
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
	int carry = 0; //�i����ܼ�
	Bigint result;
	if (b.num.length() > a.num.length()) {
		swap(a, b); //���j�Ʀr�\�e��
	}
	int zero = (a.num.length() - b.num.length());
	while (zero--) {
		b.num = "0"+b.num; //���p�Ʀr�r����0(�r��)
	}
	for (int i = a.num.length() - 1; i >= 0; i--) {
		int ans = (a.num[i] - '0') + (b.num[i] - '0') + carry;
		if (ans > 9) {
			carry = 1; //�i��
		}
		else {
			carry = 0; //�M�Ŷi���
		}
		result.num = (char)(ans % 10 + '0') + result.num;
	}						//�u�O�d�Ӧ�Ʀr(��^�r��)
	if (carry) {
		result.num = "1" + result.num; //�̫�@��i��
	}
	return result;
}