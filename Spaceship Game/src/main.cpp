// Spaceship Game
// main.cpp
// Justyn Durnford
// Created on 2021-05-07
// Last modified on 2021-05-13
// Main file.

#include "Define.h"
#include "Entity.h"
#include "Player.h"
#include "Game.h"

int main()
{
	if (!player_spaceship_texture.loadFromFile("player_spaceship.png"))
	{
		cout << "ERROR: Could not open file player_spaceship.png" << endl;
		return -1;
	}

	Player spaceship(&player_spaceship_texture, 0.f, 0.f);

	Game game(800, 600);
	game.run();


	return 0;
}