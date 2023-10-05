#pragma once
#include <math.h>

class Vec2D
{
public:
	static Vec2D up;
	static Vec2D zero;
	static Vec2D right;
public:
	double x, y;
public:
	
	Vec2D(double x, double y) : x(x), y(y) {}
	Vec2D() : Vec2D(0, 0) { }
	double Magnitude();
	Vec2D Normalized();
public:
	static double Distance(const Vec2D& a, const Vec2D& b);
public:
	bool operator=(const Vec2D& rhs);
	Vec2D operator-();
	Vec2D operator-(const Vec2D& rhs);
	Vec2D operator*(const Vec2D& rhs);
	Vec2D operator/(const double scalar);
};

inline double Vec2D::Magnitude() { return sqrt((x * x) + (y * y)); }
inline Vec2D Vec2D::Normalized() { return (*this / Magnitude()); }


inline Vec2D Vec2D::operator-() { return { -x, -y }; }

inline Vec2D Vec2D::operator-(const Vec2D& rhs)
{
	return { this->x - rhs.x, this->y - rhs.y };
}

inline Vec2D Vec2D::operator*(const Vec2D& rhs)
{
	return { this->x * rhs.x, this->y * rhs.y };
}

inline Vec2D Vec2D::operator/(const double scalar) {
	return { this->x / scalar, this->y / scalar };
}