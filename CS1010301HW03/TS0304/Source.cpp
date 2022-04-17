#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int year;
	while (cin >> year) {
		int power, ans = 0;
		double k = 1, fac = 0;
		power = (year - 1900) / 10;
		k = pow(2, 2 + power);
		while (fac < k) {
			ans++;
			fac = fac + log2(ans);
		}
		cout << ans - 1 << endl;
	}
}
/*
Math:

2^2^(2+n) = x! (¦P¨úlog2)
2^(2+n) = log2(x!) = log2(x)(x-1)! = log2(x) + log2(x-1)!
==> 2^(2+n) = log2(x) + log2(x-1) + log2(x-2) + ... + log2(2) + log2(1) + 1
==> while loop

*/