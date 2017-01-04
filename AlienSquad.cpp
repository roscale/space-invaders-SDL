#include "AlienSquad.hpp"
#include "Alien.hpp"
#include "globals.hpp"
#include "Vector2D.hpp"
#include <SDL2pp/SDL2pp.hh>
#include <cstdlib>

using namespace SDL2pp;

std::vector<Alien> AlienSquad::squad;

void AlienSquad::initSquad()
{
	// I should've used static members :(
	// Or not because of a bug..
	Alien refAlien(Vector2D{-100, -100});

	const int xMargin = 20;
	const int yMargin = 20;

	for (int col = 0; col < gWindow.GetWidth() - 2*(refAlien.size.x + 20); col+=(refAlien.size.x + 20))
		for (int row = 0; row < 3*(refAlien.size.y + 20); row+=(refAlien.size.y + 20))
			squad.push_back(Alien{ Vector2D{col, row} });

	#include <iostream>
	std::cout << squad.size() << '\n';
}

void AlienSquad::update()
{
	bool edgeHit = false;
	for (auto &alien : squad)
	{
		alien.update();
		if (alien.pos.x < 0 || alien.pos.x + alien.size.x > gWindow.GetWidth())
			edgeHit = true;
	}

	if (edgeHit)
		for (auto &alien : squad)
		{
			alien.pos += Vector2D{0, 10};
			alien.vel *= -1.15;
		}
}

void AlienSquad::randomShoot()
{
	for (auto &alien : squad)
		if (rand() % 1000 == 0) { alien.shoot(); }
}

void AlienSquad::draw()
{
	for (auto &alien : squad)
		alien.draw();
}
