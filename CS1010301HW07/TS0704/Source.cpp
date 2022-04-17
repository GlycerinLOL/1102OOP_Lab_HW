#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dp[1010][1010];

int CalcLength(string a, string b) {
	int lengthA, lengthB;
	lengthA = a.length();
	lengthB = b.length();
	if (lengthA == 0) {
		return lengthB;
	}
	if (lengthB == 0) {
		return lengthA;
	}
	for (int i = 1; i <= lengthA; i++) {
		dp[i][0] = i;
	}
	for (int j = 1; j <= lengthB; j++) {
		dp[0][j] = j;
	}
	for (int i = 1; i <= lengthA; i++) {
		for (int j = 1; j <= lengthB; j++) {
			if (a[i - 1] == b[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
			}
		}
	}
	return dp[lengthA][lengthB];
}

int main() {
	string a, b;
	
	while (getline(cin, a, '\n')) {
		getline(cin, b, '\n');
		int ans = CalcLength(a, b);
		cout << ans << endl;
	}
}