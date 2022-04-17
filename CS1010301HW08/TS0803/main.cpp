#include <iostream>
#include <string>
#include "memory.h"
#define DEBUG

using namespace std;

int main() {
	int size = 0;
	int times = 0;
	while (cin >> size >> times) {
		Memory memory(size);
		for (int i = 0; i < times; i++) {
			string operation;
			int address;
			string type;
			cin >> operation;
			cin >> address;
			cin >> type;
			if (operation == "Set") {
				cin.get();
				string value;
				getline(cin, value, '\n');
				memory.setMemory(address, type, value);
			}
			else if (operation == "Get") {
				memory.getMemory(address, type);
			}
		}
	}
}