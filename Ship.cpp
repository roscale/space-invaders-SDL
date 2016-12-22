#include "Ship.hpp"
#include "globals.hpp"
#include <SDL2pp/SDL2pp.hh>
#include <vector>
#include "Bullet.hpp"
#include "BulletManager.hpp"

using namespace SDL2pp;

void Ship::setDir(int newDir) { dir = newDir; }

void Ship::move()
{
	pos.x += dir;

	// Clapping sprite on window
	if (pos.x < 0)
		pos.x = 0;
	else if (pos.x > gWindow.GetWidth() - sprite.GetWidth())
		pos.x = gWindow.GetWidth() - sprite.GetWidth();
}

void Ship::shoot()
{
	// At the half of the ship
	Point bulletPos = { pos.x + size.x/2-3, pos.y };
	BulletManager::addBullet(bulletPos, -10);
}

void Ship::draw()
{
	gRenderer.Copy(sprite, NullOpt, pos);
}
