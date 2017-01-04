#pragma once
#include <SDL2pp/SDL2pp.hh>
#include "Vector2D.hpp"

using namespace SDL2pp;

class Alien;
class Bullet
{
private:
	Vector2D pos = {-1, -1};
	Vector2D size = {6, 18};
	Vector2D vel;
	bool enemyBullet;

public:
	Bullet(Vector2D startPos, Vector2D startVel, bool isEnemy);
	void update();
	bool hits(const Alien &alien) const;
	bool isOffscreen();
	bool isEnemyBullet();
	void draw() const;

	friend class BulletManager;
};
