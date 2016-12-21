#include "AlienSquad.hpp"
#include "Alien.hpp"
#include "globals.hpp"
#include <SDL2pp/SDL2pp.hh>

AlienSquad::AlienSquad()
{
	// I should've used static members :(
	Alien refAlien(SDL2pp::Point{-100, -100});

	const int xMargin = 20;
	const int yMargin = 20;

	for (int col = 0; col < gWindow.GetWidth() - 2*(refAlien.size.x + 20); col+=(refAlien.size.x + 20))
		for (int row = 0; row < 3*(refAlien.size.y + 20); row+=(refAlien.size.y + 20))
			squad.push_back(Alien{SDL2pp::Point{ col, row }});
}

void AlienSquad::move()
{
	bool edgeHit = false;
	for (auto &alien : squad)
	{
		alien.move();
		if (alien.pos.x < 0 || alien.pos.x + alien.size.x > gWindow.GetWidth())
			edgeHit = true;
	}

	if (edgeHit)
		for (auto &alien : squad)
			alien.dir *= -1;
}

void AlienSquad::draw()
{
	for (auto &alien : squad)
		alien.draw();
}
