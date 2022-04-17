#pragma once
class Point {
private:
	float cor[2] = { 0.0,0.0 };
public:
	void Set(float x, float y) {
		cor[0] = x;
		cor[1] = y;
	}
	void Move(float, float);
	void Rotate();
	void Reflect();
	const float GetHorizontal();
	const float GetVertical();
	Point(const Point& previous) {
		cor[0] = previous.cor[0];
		cor[1] = previous.cor[1];
	}
	Point() {};
};