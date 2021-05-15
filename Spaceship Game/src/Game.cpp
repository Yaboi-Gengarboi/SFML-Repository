// Pokemon Revolution
// Game.cpp
// Justyn Durnford
// Created on 2021-05-03
// Last modified on 2021-05-15
// Source file for the Game class.

#include "Game.h"

Texture player_spaceship_texture;
Texture enemy_spaceship_texture;

void Game::processEvents()
{
	while (window_.pollEvent(event_))
	{
		switch (event_.type)
		{
			case Event::Closed:
				window_.close();
				break;

			case Event::KeyPressed:
				handleKeyboardInput(event_.key.code, true);
				break;

			case Event::KeyReleased:
				handleKeyboardInput(event_.key.code, false);
				break;

			default:
				break;
		}
	}
}

void Game::handleKeyboardInput(Keyboard::Key key, bool is_pressed)
{
	switch (key)
	{
		case Keyboard::Key::W:
			keyboardInput_[key] = is_pressed;
			break;
		case Keyboard::Key::A:
			keyboardInput_[key] = is_pressed;
			break;
		case Keyboard::Key::S:
			keyboardInput_[key] = is_pressed;
			break;
		case Keyboard::Key::D:
			keyboardInput_[key] = is_pressed;
			break;
		case Keyboard::Key::Escape:
			window_.close();
			break;
		default:
			break;
	}
}

void Game::update(Time dt)
{
	player_.velocity.x = 0.f;
	player_.velocity.y = 0.f;

	if (keyboardInput_[Keyboard::Key::W])
		player_.velocity.y -= 400.f;
	if (keyboardInput_[Keyboard::Key::A])
		player_.velocity.x -= 400.f;
	if (keyboardInput_[Keyboard::Key::S])
		player_.velocity.y += 400.f;
	if (keyboardInput_[Keyboard::Key::D])
		player_.velocity.x += 400.f;

	player_.update(dt);
}

void Game::render()
{
	window_.clear();
	window_.draw(player_.sprite);
	window_.display();
}

Game::Game(uint32_t width, uint32_t height)
	: window_(VideoMode(width, height), "Spaceship Game", Style::Titlebar | Style::Close),
	  player_(&player_spaceship_texture, window_width / 2.f, window_height / 2.f)
{
	keyboardInput_[Keyboard::Key::W] = false;
	keyboardInput_[Keyboard::Key::A] = false;
	keyboardInput_[Keyboard::Key::S] = false;
	keyboardInput_[Keyboard::Key::D] = false;

	window_.setFramerateLimit(60);
}

void Game::run()
{
	Clock clock;

	while (window_.isOpen())
	{
		processEvents();
		update(clock.restart());
		render();
	}
}