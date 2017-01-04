#pragma once
#include <SDL2pp/SDL2pp.hh>
#include "globals.hpp"
#include "Vector2D.hpp"

using namespace SDL2pp;

class Alien
{
private:
	Texture sprite{ gRenderer, "resources/alien.png" };

	Vector2D pos = {-1, -1};
	Vector2D size = { sprite.GetWidth(), sprite.GetHeight() };
	Vector2D vel = {25, 0};

public:
	Alien(Vector2D startPos);

	void update();
	void shoot();
	void draw();

	friend class BulletManager;
	friend class AlienSquad;
};
