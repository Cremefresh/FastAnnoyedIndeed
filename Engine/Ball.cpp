#include "Ball.h"


Ball::Ball(float radius_in, const Color& color_in, Vec2 speed_in, Vec2 posi_in) :
	radius(radius_in),
	color(color_in),
	speed(speed_in),
	posi(posi_in)
{
}

void Ball::Move(FrameTimer& ft)
{
	float dt = ft.Mark();
	posi += speed * dt;
}

void Ball::Draw(Graphics& gfx) const
{
	gfx.DrawCircle(int(posi.x), int(posi.y), int(radius), color);
}

bool Ball::WallCollision(const RektF& wall)
{
	bool collision = false;
	RektF rekt = GetRekt();
	int offset = 5;
	if (rekt.bottom > wall.bottom - offset)
	{
		FlipY();
		collision = true;
	}
	if (rekt.top < wall.top + offset)
	{
		FlipY();
		collision = true;
	}
	if (rekt.left < wall.left + offset)
	{
		FlipX();
		collision = true;
	}
	if (rekt.right > wall.right - offset)
	{
		FlipX();
		collision = true;
	}

	return collision;
}

void Ball::FlipX()
{
	speed.x = -speed.x;
}

void Ball::FlipY()
{
	speed.y = -speed.y;
}

RektF Ball::GetRekt() const
{
	return RektF::FromCenter(posi, radius, radius);
}
