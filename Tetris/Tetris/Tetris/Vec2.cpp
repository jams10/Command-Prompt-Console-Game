#include "Vec2.h"

Vec2::Vec2( const int& x_in, const int& y_in )
	:
	x(x_in),
	y(y_in)
{
}

Vec2 Vec2::operator+(const Vec2& rhs) const
{
	return Vec2( x + rhs.x, y + rhs.y );
}

Vec2& Vec2::operator+=(const Vec2& rhs)
{
	return *this = *this + rhs;
}

Vec2 Vec2::operator-(const Vec2& rhs) const
{
	return Vec2( x - rhs.x, y - rhs.y );
}

Vec2& Vec2::operator-=(const Vec2& rhs)
{
	return *this = *this - rhs;
}