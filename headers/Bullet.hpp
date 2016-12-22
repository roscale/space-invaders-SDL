#pragma once
#include <SDL2pp/SDL2pp.hh>

using namespace SDL2pp;

class Alien;
class Bullet
{
private:
	Point pos;
	Point size{ 6, 18 };

	int dir;

public:
	Bullet(Point startPos, int startDir) : pos{startPos}, dir{startDir}
	{}

	void move();
	bool hits(const Alien &alien) const;
	void draw() const;

	Point getPos() const;
};
