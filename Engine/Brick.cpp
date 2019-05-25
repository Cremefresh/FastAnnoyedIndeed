#include "Brick.h"

Brick::Brick(const RektF& rect_in, Color color_in) :
	rektf(rect_in),
	color(color_in),
	destroyed(false)
{

}


void Brick::Draw(Graphics& gfx) const
{
	gfx.DrawRect(rektf, color);

}

bool Brick::BallCollsion(Ball& ball)
{
	if (rektf.IsOverlapped(ball.GetRekt()) && destroyed == false);
	{
		destroyed = true;
		ball.FlipY();
		return true;
	}
	return false;
}

