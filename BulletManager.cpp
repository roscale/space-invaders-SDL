#include "BulletManager.hpp"
#include <SDL2pp/SDL2pp.hh>
#include <vector>
#include "Bullet.hpp"
#include "Ship.hpp"
#include "AlienSquad.hpp"

using namespace SDL2pp;

std::vector<Bullet> BulletManager::bullets;


void BulletManager::addBullet(Bullet bullet)
{
	bullets.push_back(bullet);
}

void BulletManager::update()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		Rect bulletRect = {
			bullets[i].pos.x,
			bullets[i].pos.y,
			bullets[i].size.x,
			bullets[i].size.y };

		bullets[i].update();
		// On screen check
		if (bullets[i].isOffscreen())
		{
			bullets.erase(bullets.begin() + i);
			continue;
		}

		// Alien hit check
		for (int j = 0; j < AlienSquad::squad.size(); j++)
		{
			Rect alienRect = {
				AlienSquad::squad[j].pos.x,
				AlienSquad::squad[j].pos.y,
				AlienSquad::squad[j].size.x,
				AlienSquad::squad[j].size.y };

			if (!BulletManager::bullets[i].isEnemyBullet() && bulletRect.Intersects(alienRect))
			{
				BulletManager::bullets.erase(BulletManager::bullets.begin() + i);
				AlienSquad::squad.erase(AlienSquad::squad.begin() + j);
			}
		}
	}
}

void BulletManager::draw()
{
	for (const auto &bullet : bullets)
		bullet.draw();
}
