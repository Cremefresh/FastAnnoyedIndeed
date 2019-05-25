#pragma once
#include "RektF.h"
#include "Colors.h"
#include "Graphics.h"
#include "Vec2.h"
#include "FrameTimer.h"

class Ball
{
public:
	Ball() = default;
	Ball(float radius, const Color& color, Vec2 speed, Vec2 posi);
	void Move(FrameTimer& ft);
	void Draw(Graphics& gfx) const;
	bool WallCollision(const RektF& walls);
	void FlipX();
	void FlipY();
	RektF GetRekt() const;


private:
	float radius;
	Color color;
	Vec2 speed;
	Vec2 posi;
	Graphics gfx;


};