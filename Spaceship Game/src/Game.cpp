// Pokemon Revolution
// Game.cpp
// Justyn Durnford
// Created on 2021-05-03
// Last modified on 2021-05-12
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
		default:
			break;
	}
}

void Game::update(Time dt)
{
	player_.velocity.x = 0.f;
	player_.velocity.y = 0.f;

	if (keyboardInput_[Keyboard::Key::W])
		player_.velocity.y = -400.f;
	if (keyboardInput_[Keyboard::Key::A])
		player_.velocity.x = -400.f;
	if (keyboardInput_[Keyboard::Key::S])
		player_.velocity.y = 400.f;
	if (keyboardInput_[Keyboard::Key::D])
		player_.velocity.x = 400.f;

	player_.update(dt);
	Vector2f player_pos(player_.sprite.getPosition());

	clamp(player_pos.x, 0.f, windowWidth() - 32.f);
	clamp(player_pos.y, 0.f, windowHeight() - 32.f);

	player_.sprite.setPosition(player_pos.x, player_pos.y);
}

void Game::render()
{
	window_.clear();
	window_.draw(player_.sprite);
	window_.display();
}

Game::Game(uint16_t width, uint16_t height)
	: window_(VideoMode(width, height), "Spaceship Game"),
	  player_(&player_spaceship_texture, windowWidth() / 2.f, windowHeight() / 2.f)
{
	keyboardInput_[Keyboard::Key::W] = false;
	keyboardInput_[Keyboard::Key::A] = false;
	keyboardInput_[Keyboard::Key::S] = false;
	keyboardInput_[Keyboard::Key::D] = false;

	window_.setFramerateLimit(60);
}

uint16_t Game::windowWidth() const
{
	return window_.getSize().x;
}

uint16_t Game::windowHeight() const
{
	return window_.getSize().y;
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