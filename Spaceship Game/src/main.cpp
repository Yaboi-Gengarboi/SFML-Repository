// Spaceship Game
// main.cpp
// Justyn Durnford
// Created on 2021-05-07
// Last modified on 2021-05-12
// Main file.

#include "Define.h"
#include "Entity.h"
#include "Game.h"

int main()
{
	if (!spaceship_texture.loadFromFile("spaceship.png"))
	{
		cout << "ERROR: Could not open file spaceship.png" << endl;
		return -1;
	}

	Entity spaceship(&spaceship_texture, 0.f, 0.f);

	Game game(800, 600);
	game.run();


	return 0;
}