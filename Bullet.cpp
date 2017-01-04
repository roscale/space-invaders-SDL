#include "Bullet.hpp"
#include "globals.hpp"
#include <SDL2pp/SDL2pp.hh>
#include "Alien.hpp"

using namespace SDL2pp;

Bullet::Bullet(Vector2D startPos, Vector2D startVel, bool isEnemy)
{
	pos.x = startPos.x;
	pos.y = startPos.y;
	vel = startVel;
	enemyBullet = isEnemy;
}

void Bullet::update() { pos += vel; }

bool Bullet::isOffscreen()
{
	Rect rect{ pos.x, pos.y, size.x, size.y };
	return (rect.x < 0 || rect.x > gWindow.GetWidth() || rect.y < 0 || rect.y > gWindow.GetHeight());
}

bool Bullet::isEnemyBullet() { return enemyBullet; }

void Bullet::draw() const
{
	gRenderer.SetDrawColor(255, 255, 255);

	Rect renderRect{ pos.x, pos.y, size.x, size.y };
	gRenderer.FillRect(renderRect);
}
