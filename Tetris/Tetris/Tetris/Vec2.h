#pragma once

class Vec2
{
public:
	Vec2() = default;
	Vec2( const int& x_in, const int& y );
	Vec2 operator+(const Vec2& rhs) const;
	Vec2& operator+=(const Vec2& rhs);
	Vec2 operator-(const Vec2& rhs) const;
	Vec2& operator-=(const Vec2& rhs);
public:
	int x = 0;
	int y = 0;
};