#include "Ship.hpp"
#include "globals.hpp"
#include <SDL2pp/SDL2pp.hh>
#include "Bullet.hpp"
#include "BulletManager.hpp"

using namespace SDL2pp;

void Ship::setDir(Vector2D newDir) { dir = newDir; }

void Ship::update()
{
	pos += (dir * gTimer.get_ticks() / 1000.0f );

	// Clapping sprite on window
	if (pos.x < 0)
		pos.x = 0;
	else if (pos.x > gWindow.GetWidth() - sprite.GetWidth())
		pos.x = gWindow.GetWidth() - sprite.GetWidth();
}

void Ship::shoot()
{
	// At the half of the ship
	Vector2D bulletPos = { pos.x + size.x / 2 - 3, pos.y };
	BulletManager::addBullet(Bullet{bulletPos, Vector2D{0, -10}, false});
}

void Ship::draw()
{
	Rect renderRect{ pos.x, pos.y, size.x, size.y };
	gRenderer.Copy(sprite, NullOpt, renderRect);
}
