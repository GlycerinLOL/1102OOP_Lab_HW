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
		int point = X.find(".");	//���p���Iindex
		if (point != string::npos) {//���p��
			point = point + 1;	//�ư��p���I
			int dec = X.length() - point;
			if (dec > N) {	//�Y�p�ƫ�Ʀr�j��N�h����
				while (dec != N) {
					X.pop_back();
					dec = dec - 1;
				}
			}
			else {	//����N�h��0
				while (dec != N) {
					X.push_back('0');
					dec = dec + 1;
				}
			}
			if (N == 0) {
				X.pop_back();	//���O�d�p���I
			}
		}
		else {	//�S�p��
			if (N != 0) {	//�p���I�ᶷ��0
				X.push_back('.');
			}
			while (N--) {
				X.push_back('0');
			}
		}
		int len = X.length();
		while (len < M) {	//�e���ɦr��
			X = C + X;
			len++;
		}
		
		cout << X << endl;
	}
	
}