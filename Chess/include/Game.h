// Chess
// Game.h
// Justyn Durnford
// Created on 2021-05-16
// Last modified on 2021-05-19
// Header file for the Game class.

#pragma once

#include "Piece.h"

extern array<Texture, 13> textures;
extern array<Piece, 6> white_pieces;
extern array<Piece, 6> black_pieces;

class Game
{
	RenderWindow window_;
	Event event_;
	map<Keyboard::Key, bool> keyboardInput_;

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