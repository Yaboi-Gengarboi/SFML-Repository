// Spaceship Game
// Game.h
// Justyn Durnford
// Created on 2021-05-07
// Last modified on 2021-05-12
// Header file for the Game class.

#ifndef SPACESHIP_GAME_GAME_H
#define SPACESHIP_GAME_GAME_H

#include "Entity.h"

extern Texture spaceship_texture;

class Game
{
	RenderWindow window_;
	Event event_;
	map<Keyboard::Key, bool> keyboardInput_;
	Entity player_;

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
	Game(uint16_t width, uint16_t height);

	//
	uint16_t windowWidth() const;

	//
	uint16_t windowHeight() const;

	//
	void run();
};

#endif // SPACESHIP_GAME_GAME_H