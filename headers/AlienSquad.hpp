#pragma once

#include <vector>
#include "Alien.hpp"

class AlienSquad
{
public:
	AlienSquad();
	std::vector<Alien> squad;

	void move();
	void draw();
};
