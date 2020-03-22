#pragma once

struct Vec2 {
	int x;
	int y;

	Vec2() : x(0), y(0) {};
	Vec2(const int &_x, const int &_y) : x(_x), y(_y) {};
	Vec2(const Vec2 &v) : x(v.x), y(v.y) {};

};