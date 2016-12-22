#pragma once
#include <SDL2pp/SDL2pp.hh>
#include "globals.hpp"

using namespace SDL2pp;

class Alien
{
private:
	Texture sprite{ gRenderer, "resources/alien.png" };

	Point pos;
	Point size{ sprite.GetWidth(), sprite.GetHeight() };
	double dir = 1;

public:
	Alien(Point startPos) { pos = startPos; }

	void move();
	void draw();

	friend class AlienSquad;
	friend class Bullet;
};
