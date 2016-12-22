#include "Bullet.hpp"
#include "globals.hpp"
#include <SDL2pp/SDL2pp.hh>
#include "Alien.hpp"

using namespace SDL2pp;

void Bullet::move() { pos.y += dir; }

bool Bullet::hits(const Alien &alien) const
{
	Rect bulletRect = { pos, size };
	Rect alienRect = { alien.pos, alien.size };
	return bulletRect.Intersects(alienRect);
}

void Bullet::draw() const
{
	gRenderer.SetDrawColor(255, 255, 255);
	gRenderer.FillRect(pos, pos+size);
}

Point Bullet::getPos() const
{
	return pos;
}
