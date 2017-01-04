#pragma once

#include <vector>
#include "Alien.hpp"

class AlienSquad
{
public:
	static void initSquad();
	static std::vector<Alien> squad;

	static void update();
	static void randomShoot();
	static void draw();
};
