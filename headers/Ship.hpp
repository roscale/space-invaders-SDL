#pragma once
#include <SDL2pp/SDL2pp.hh>
#include "globals.hpp"
#include <vector>
#include "Bullet.hpp"

using namespace SDL2pp;

class Ship
{
private:
	Texture sprite{ gRenderer, "resources/ship.png" };

	Point pos{ gWindow.GetWidth() / 2, gWindow.GetHeight() - sprite.GetHeight() };
	Point size{ sprite.GetWidth(), sprite.GetHeight() };
	int dir = 0;

public:
	// std::vector<Bullet> bullets;
	Ship() {}

	void setDir(int newDir);
	void move();
	void shoot();
	void draw();
};
