#define SDL2PP_WITH_IMAGE

#include <SDL2pp/SDL2pp.hh>
#include <SDL2/SDL_image.h>
#include "globals.hpp"
#include "Ship.hpp"
#include <vector>
#include "Alien.hpp"
#include "AlienSquad.hpp"

using namespace SDL2pp;

SDL sdl(SDL_INIT_VIDEO);
Window gWindow("Space Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
Renderer gRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);

Ship ship;
AlienSquad alienSquad;

int main()
{
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

		// Bullets
		for (int i = 0; i < ship.bullets.size(); i++)
		{
			ship.bullets[i].move();

			// On screen check
			if (ship.bullets[i].getPos().y < 0)
			{
				ship.bullets.erase(ship.bullets.begin() + i);
				continue;
			}

			// Alien hit check
			for (int j = 0; j < alienSquad.squad.size(); j++)
				if (ship.bullets[i].hits(alienSquad.squad[j]))
				{
					ship.bullets.erase(ship.bullets.begin() + i);
					alienSquad.squad.erase(alienSquad.squad.begin() + j);
				}

			#include <iostream>
			std::cout << "Bullet: " << ship.bullets[i].getPos() << '\n' << std::flush;
		}
		ship.move();
		alienSquad.move();


		for (const auto &bullet : ship.bullets)
			bullet.draw();
		ship.draw();
		alienSquad.draw();

		gRenderer.Present();
		SDL_Delay(10);
	}

	return 0;
}
