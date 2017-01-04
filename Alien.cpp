#include "Alien.hpp"
#include "globals.hpp"
#include <SDL2pp/SDL2pp.hh>
#include "BulletManager.hpp"

#include "Timer.hpp"

using namespace SDL2pp;

Alien::Alien(Vector2D startPos)
{
	pos.x = startPos.x;
	pos.y = startPos.y;
}
#include <iostream>
void Alien::update() { pos += (vel * gTimer.get_ticks() / 1000.0f ); }

void Alien::shoot()
{
	Vector2D startPos = {pos.x + size.x/2, pos.y + size.y/2};
	BulletManager::addBullet(Bullet{startPos, Vector2D{0, 6}, true});
}

void Alien::draw()
{
	Rect renderRect{ pos.x, pos.y, size.x, size.y };
	gRenderer.Copy(sprite, NullOpt, renderRect);
}
