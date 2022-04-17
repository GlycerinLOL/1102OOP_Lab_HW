#include <iostream>
#include <algorithm>

using namespace std;

int getLength(int n) {
	int count = 0;
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = n * 3 + 1;
		}
		count++;
	}
	return count + 1;
}

int main() {
	int a, b;
	
	while (cin >> a >> b) {
		int maxcount = 0;
		bool numswap = false;
		if (a > b) {
			swap(a, b);
			numswap = true;
		}
		for (int i = a; i <= b; i++) {
			int count = getLength(i);
			if (count > maxcount) maxcount = count;
		}
		if (numswap) {
			cout << b << " " << a << " " << maxcount << endl;
		}
		else {
			cout << a << " " << b << " " << maxcount << endl;
		}
		
		
	}
}