#include "Bullet.hpp"
#include "globals.hpp"
#include <SDL2pp/SDL2pp.hh>
#include "Alien.hpp"

void Bullet::move() { pos.y += dir; }

bool Bullet::hits(const Alien &alien) const
{
	SDL2pp::Rect bulletRect = { pos, size };
	SDL2pp::Rect alienRect = { alien.pos, alien.size };
	return bulletRect.Intersects(alienRect);
}

void Bullet::draw() const
{
	gRenderer.SetDrawColor(255, 255, 255);
	gRenderer.FillRect(pos, pos+size);
}

SDL2pp::Point Bullet::getPos() const
{
	return pos;
}
