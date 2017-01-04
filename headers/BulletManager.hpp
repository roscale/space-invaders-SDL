#pragma once
#include <SDL2pp/SDL2pp.hh>
#include <vector>
#include "Bullet.hpp"

using namespace SDL2pp;

class BulletManager
{
private:
	static std::vector<Bullet> bullets;

public:
	static void addBullet(Bullet bullet);
	static void update();
	static void draw();
};
