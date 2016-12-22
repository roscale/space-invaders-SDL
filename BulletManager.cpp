#include "BulletManager.hpp"
#include <SDL2pp/SDL2pp.hh>
#include <vector>
#include "Bullet.hpp"
#include "Ship.hpp"
#include "AlienSquad.hpp"

using namespace SDL2pp;

std::vector<Bullet> BulletManager::bullets;

void BulletManager::addBullet(Point startPos, int startDir)
{
	bullets.push_back(Bullet{ startPos, startDir });
}

void BulletManager::update()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i].move();

		// On screen check
		if (bullets[i].getPos().y < 0)
		{
			bullets.erase(bullets.begin() + i);
			continue;
		}
		// Alien hit check
		for (int j = 0; j < AlienSquad::squad.size(); j++)
			if (BulletManager::bullets[i].hits(AlienSquad::squad[j]))
			{
				BulletManager::bullets.erase(BulletManager::bullets.begin() + i);
				AlienSquad::squad.erase(AlienSquad::squad.begin() + j);
			}
	}
}

void BulletManager::draw()
{
	for (const auto &bullet : bullets)
		bullet.draw();
}
