#include "Point.h"
#include <algorithm>
using namespace std;

void Point::Move(float x, float y) {
	cor[0] += x;
	cor[1] += y;
}

void Point::Rotate() {
	if (cor[0] == 0 && cor[1] == 0) {
		return;
	}
	swap(cor[0], cor[1]);
	cor[1] = -cor[1];
}

void Point::Reflect() {
	if (cor[0] == 0 && cor[1] == 0) {
		return;
	}
	cor[0] = -cor[0];
	cor[1] = -cor[1];
}

const float Point::GetHorizontal() {
	return cor[0];
}

const float Point::GetVertical() {
	return cor[1];
}