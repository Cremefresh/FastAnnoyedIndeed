#pragma once
#include "Vec2.h"

class RektF
{

public:
	RektF() = default;
	RektF(float top_in, float left_in, float right_in, float bottom_in);
	RektF(const Vec2& topLeft, const Vec2& bottomRight);
	RektF(const Vec2& topLeft, float width, float height);
	bool IsOverlapped(const RektF& other);
	static  RektF FromCenter(Vec2 center, int halfWidth, int halfHeight);

public:
	float top;
	float left;
	float right;
	float bottom;
};