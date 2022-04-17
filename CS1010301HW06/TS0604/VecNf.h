#pragma once
#include <iostream>
#include <vector>

using namespace std;

class VecNf {
public:
	VecNf();
	VecNf(float* dest, int cnt);
	VecNf(const VecNf& rhs);
	VecNf operator+(const VecNf&) const;
	VecNf operator-(const VecNf&) const;
	float operator*(const VecNf&) const;
	float& operator[](int) const;
	void operator=(const VecNf&);
	VecNf operator*(double) const;
	friend VecNf operator*(double, const VecNf&);
	//friend ostream& operator<<(ostream&, VecNf&);
	int Size() {
		return cnt;
	}
private:
	vector<float> element;
	int cnt = 1;
};