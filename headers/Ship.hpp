#pragma once
#include <SDL2pp/SDL2pp.hh>
#include "globals.hpp"
#include "Vector2D.hpp"
#include "Bullet.hpp"

using namespace SDL2pp;

class Ship
{
private:
	Texture sprite{ gRenderer, "resources/ship.png" };

	// Use Vector2D !! Eigen maybe or better internet copied code
	// PS: Nope, I made one myself :P

	Vector2D pos = { gWindow.GetWidth() / 2, gWindow.GetHeight() - sprite.GetHeight()};
	Vector2D size = { sprite.GetWidth(), sprite.GetHeight() };
	Vector2D dir;

public:
	Ship() {}

	void setDir(Vector2D newDir);
	void update();
	void shoot();
	void draw();
};
