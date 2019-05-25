#pragma once
#include "RektF.h"
#include "Graphics.h"
#include "Colors.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick& operator= (const Brick&) = default;
	Brick(const RektF& rect_in, Color color);
	void Draw(Graphics& gfx) const;
	bool BallCollsion(Ball& ball);

public:


private:
	bool destroyed;
	RektF rektf;
	Color color;
	Graphics gfx;

};