#pragma once

struct Vec2 {
	int x;
	int y;

	Vec2() : x(0), y(0) {};
	Vec2(const int &_x, const int &_y) : x(_x), y(_y) {};
	Vec2(const Vec2 &v) : x(v.x), y(v.y) {};

	friend bool operator== (const Vec2 &v1, const Vec2 &v2)
	{
		return (v1.x == v2.x) && (v1.y == v2.y);
	}

};