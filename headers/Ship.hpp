#pragma once

#include <SDL2pp/SDL2pp.hh>
#include "globals.hpp"
#include <vector>
#include "Bullet.hpp"

class Ship
{
private:
	SDL2pp::Texture sprite{ gRenderer, "resources/ship.png" };

	SDL2pp::Point pos{ gWindow.GetWidth() / 2, gWindow.GetHeight() - sprite.GetHeight() };
	SDL2pp::Point size{ sprite.GetWidth(), sprite.GetHeight() };
	int dir = 0;

public:
	std::vector<Bullet> bullets;
	Ship() {}

	void setDir(int newDir);
	void move();
	void shoot();
	void draw();
};
