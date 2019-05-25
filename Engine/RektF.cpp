#include "RektF.h"

RektF::RektF(float top_in, float left_in, float right_in, float bottom_in) :
	top(top_in),
	left(left_in),
	right(right_in),
	bottom(bottom_in)
{

}

RektF::RektF(const Vec2& topLeft, const Vec2& bottomRight) :
	RektF(topLeft.y, topLeft.x, bottomRight.x, bottomRight.y)
{

}

RektF::RektF(const Vec2& topLeft, float width, float height) : RektF(topLeft, topLeft + Vec2(width, height))

{

}

bool RektF::IsOverlapped(const RektF& other)
{
	bool isOverlapped = false;
	if (right > other.left && top < other.bottom && left < other.right && bottom > other.top)
	{
		isOverlapped = true;
	}
	return isOverlapped;
}

RektF RektF::FromCenter(Vec2 center, int halfWidth, int halfHeight)
{
	Vec2 half(halfWidth, halfHeight);
	return RektF(center - half, center + half);
}
