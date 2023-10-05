#include "Vec2D.h"
#include <math.h>

Vec2D Vec2D::up = { 0.0, 1.0 };
Vec2D Vec2D::zero = { 0, 0 };
Vec2D Vec2D::right = { 1, 0 };

double Vec2D::Distance(const Vec2D& a, const Vec2D& b)
{
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool Vec2D::operator=(const Vec2D& rhs)
{
	return (this->x == rhs.x && this->y == rhs.y);
}
