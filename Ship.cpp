#include "Ship.hpp"
#include "globals.hpp"
#include <SDL2pp/SDL2pp.hh>
#include <vector>
#include "Bullet.hpp"

void Ship::setDir(int newDir) { dir = newDir; }

void Ship::move()
{
	pos.x += dir;

	// Clapping sprite on window
	using namespace SDL2pp;
	if (pos.x < 0)
		pos.x = 0;
	else if (pos.x > gWindow.GetWidth() - sprite.GetWidth())
		pos.x = gWindow.GetWidth() - sprite.GetWidth();

}

void Ship::shoot()
{
	// At the half of the ship
	SDL2pp::Point bulletPos = { pos.x + size.x/2-3, pos.y };
	bullets.push_back(Bullet{ bulletPos, -10});
}

void Ship::draw()
{
	using namespace SDL2pp;
	gRenderer.Copy(sprite, NullOpt, pos);
}
