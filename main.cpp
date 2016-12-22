#include <SDL2pp/SDL2pp.hh>
#include <SDL2/SDL_image.h>
#include "globals.hpp"
#include "Ship.hpp"
#include <vector>
#include "Alien.hpp"
#include "AlienSquad.hpp"
#include "BulletManager.hpp"

using namespace SDL2pp;

SDL sdl(SDL_INIT_VIDEO);
Window gWindow("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
Renderer gRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

int main()
{
	// Game init
	Ship ship;
	AlienSquad::initSquad();

	while (true)
	{
		SDL_Event e;
		if (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				break;

			else if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
				switch (e.key.keysym.sym)
				{
					case SDLK_LEFT:
						ship.setDir(-2); break;
					case SDLK_RIGHT:
						ship.setDir(2); break;
					case SDLK_SPACE:
						ship.shoot(); break;
				}

			else if (e.type == SDL_KEYUP)
				switch (e.key.keysym.sym) {
					case SDLK_LEFT:
					case SDLK_RIGHT:
						ship.setDir(0);
				}
		}

		gRenderer.SetDrawColor(0, 0, 0);
		gRenderer.Clear();

		ship.move();
		AlienSquad::move();
		BulletManager::update();

		BulletManager::draw();
		ship.draw();
		AlienSquad::draw();

		gRenderer.Present();
		SDL_Delay(10);
	}

	return 0;
}
