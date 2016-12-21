#pragma once

#include <SDL2pp/SDL2pp.hh>
#include "globals.hpp"

class Alien
{
private:
	SDL2pp::Texture sprite{ gRenderer, "resources/alien.png" };

	SDL2pp::Point pos;
	SDL2pp::Point size{ sprite.GetWidth(), sprite.GetHeight() };
	double dir = 1;

public:
	Alien(SDL2pp::Point startPos) { pos = startPos; }

	void move();
	void draw();

	friend class AlienSquad;
	friend class Bullet;
};
