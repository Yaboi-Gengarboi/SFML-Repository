// Spaceship Game
// Game.h
// Justyn Durnford
// Created on 2021-05-07
// Last modified on 2021-05-13
// Header file for the Game class.

#pragma once

#include "Entity.h"
#include "Player.h"

extern Texture player_spaceship_texture;
extern Texture enemy_spaceship_texture;

class Game
{
	RenderWindow window_;
	Event event_;
	map<Keyboard::Key, bool> keyboardInput_;
	Player player_;

	//
	void processEvents();

	//
	void handleKeyboardInput(Keyboard::Key key, bool is_pressed);

	//
	void update(Time dt);

	//
	void render();

	public:

	//
	Game(uint32_t width, uint32_t height);

	//
	void run();
};