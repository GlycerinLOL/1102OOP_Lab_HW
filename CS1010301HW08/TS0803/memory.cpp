#include "memory.h"

Memory::Memory() {
	size = 0;
	data.clear();
}

Memory::Memory(int size) {
	this->size = size;
	for (int i = 0; i < size; i++) {
		data.push_back(0);
	}
}

long long stringToInt(string s)
{
	long long n = 0;
	int c = 1;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		n += (s[i] - '0') * c;
		c *= 10;
	}
	return n;
}

void Memory::setMemory(int location, string type, string val) {
	if (location >= size || location < 0) {
		cout << "Violation Access." << endl;
	}
	else {
		long long num;
		if (type == "char") {
			data[location] = stringToInt(val);
		}
		else if (type == "String") {
			if (location + val.length() > size - 1)
			{
				cout << "Violation Access." << endl;
			}
			for (int i = 0; i < size; i++)
			{
				data[i + location] = val[i];
			}
		}
		else if (type == "int" || type == "short") {
			if (type == "int")
			{
				if (location + 4 > size)
				{
					cout << "Violation Access." << endl;
				}
			}
			if (type == "short")
			{
				if (location + 2 > size)
				{
					cout << "Violation Access." << endl;
				}
			}
			num = stringToInt(val);
			vector<int> hex;
			int temp = 0;
			int c = 1;
			while (num > 0) {
				temp += (num % 16) * c;
				if (c == 16) {
					c = 1;
					hex.push_back(temp);
					temp = 0;
				}
				else {
					c *= 16;
				}
				num /= 16;
			}
			for (int i = 0; i < hex.size(); i++) {
				data[i + location] = hex[i];
			}
		}
	}
}

void Memory::getMemory(int location, string type) {
	if (location >= size || location < 0) {
		cout << "Violation Access." << endl;
	}
	else {
		if (type == "char") {
			cout << data[location];
		}
		else if (type == "String") {
			while (location < size && data[location] != 0) {
				cout << (char)data[location];
				location++;
			}
		}
		else if (type == "short") {
			if (location + 2 > size - 1) {
				cout << "Violation Access." << endl;
				return;
			}
			else {
				int temp = 0;
				temp += data[location];
				temp += data[location + 1] * 16 * 16;
				cout << temp;
			}
		}
		else if (type == "int") {
			if (location + 4 > size - 1) {
				cout << "Violation Access." << endl;
			}
			else {
				int temp = 0;
				temp += data[location];
				temp += data[location + 1] * 16 * 16;
				temp += data[location + 2] * 16 * 16 * 16 * 16;
				temp += data[location + 3] * 16 * 16 * 16 * 16 * 16 * 16;
				cout << temp;
			}
		}
		cout << endl;
	}
}