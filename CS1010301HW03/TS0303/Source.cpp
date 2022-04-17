#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
	string X;
	int M, N;
	char C, buf;
	while (cin >> X) {
		cin >> M;
		cin >> N;
		buf = cin.get();
		C = cin.get();
		int point = X.find(".");	//т计翴index
		if (point != string::npos) {//Τ计
			point = point + 1;	//逼埃计翴
			int dec = X.length() - point;
			if (dec > N) {	//璝计计N玥簿埃
				while (dec != N) {
					X.pop_back();
					dec = dec - 1;
				}
			}
			else {	//ぃìN玥干0
				while (dec != N) {
					X.push_back('0');
					dec = dec + 1;
				}
			}
			if (N == 0) {
				X.pop_back();	//ぃ玂痙计翴
			}
		}
		else {	//⊿计
			if (N != 0) {	//计翴斗干0
				X.push_back('.');
			}
			while (N--) {
				X.push_back('0');
			}
		}
		int len = X.length();
		while (len < M) {	//玡干じ
			X = C + X;
			len++;
		}
		
		cout << X << endl;
	}
	
}