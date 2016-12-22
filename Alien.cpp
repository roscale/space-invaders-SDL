#include "Alien.hpp"
#include "globals.hpp"
#include <SDL2pp/SDL2pp.hh>

using namespace SDL2pp;

void Alien::move() { pos.x += dir; }

void Alien::draw()
{
	using namespace SDL2pp;
	gRenderer.Copy(sprite, NullOpt, pos);
}
