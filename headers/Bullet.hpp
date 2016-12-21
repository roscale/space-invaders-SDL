#pragma once

#include <SDL2pp/SDL2pp.hh>

class Alien;

class Bullet
{
private:
	SDL2pp::Point pos;
	SDL2pp::Point size{ 6, 18 };

	int dir = -10;

public:
	Bullet(SDL2pp::Point startPos, int newDir) : pos{startPos}, dir{newDir}
	{}

	void move();
	bool hits(const Alien &alien) const;
	void draw() const;

	SDL2pp::Point getPos() const;
};
