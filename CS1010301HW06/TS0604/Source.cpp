#include "VecNf.h"
#include <iostream>

using namespace std;

VecNf::VecNf() {
}

VecNf::VecNf(float* dest, int cnt) {
	this->cnt = cnt;
	for (int i = 0; i < cnt; i++) {
		element.push_back(dest[i]);
	}
}

VecNf::VecNf(const VecNf& rhs) {
	cnt = rhs.cnt;
	for (int i = 0; i < cnt; i++) {
		element.push_back(rhs.element[i]);
	}
}


VecNf VecNf::operator+(const VecNf& v) const {
	VecNf ans;
	if (cnt != v.cnt) {
		cout << "dimensions inconsistent" << endl;
		return ans;
	}
	else {
		ans.cnt = cnt;
		for (int i = 0; i < cnt; i++) {
			ans.element.push_back(v.element[i] + element[i]);
		}
		return ans;
	}
}

VecNf VecNf::operator-(const VecNf& v) const {
	VecNf ans;
	if (cnt != v.cnt) {
		cout << "dimensions inconsistent" << endl;
		return ans;
	}
	else {
		ans.cnt = cnt;
		for (int i = 0; i < cnt; i++) {
			ans.element.push_back(element[i] - v.element[i]);
		}
		return ans;
	}
}

float VecNf::operator*(const VecNf& v) const {
	float ans = 0.0;
	if (cnt != v.cnt) {
		cout << "dimensions inconsistent" << endl;
		return ans;
	}
	else {
		for (int i = 0; i < cnt; i++) {
			ans += element[i] * v.element[i];
		}
		return ans;
	}
}

VecNf VecNf::operator*(double n) const {
	VecNf ans;
	ans.cnt = cnt;
	for (int i = 0; i < cnt; i++) {
		ans.element.push_back(element[i] * n);
	}
	return ans;
}

VecNf operator*(double n, const VecNf& v) {
	VecNf ans;
	ans.cnt = v.cnt;
	for (int i = 0; i < v.cnt; i++) {
		ans.element.push_back(v.element[i] * n);
	}
	return ans;
}

float& VecNf::operator[](int n) const {
	float temp = element[n];
	return temp;
}

void VecNf::operator=(const VecNf& v) {
	cout << "ASSIGNMENT!!!" << endl;
	cnt = v.cnt;
	element.clear();
	for (int i = 0; i < v.cnt; i++) {
		element.push_back(v.element[i]);
	}
}

