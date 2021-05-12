// Spaceship Game
// Define.h
// Justyn Durnford
// Created on 2021-05-07
// Last modified on 2021-05-11
// 

#ifndef SPACESHIP_GAME_DEFINE_H
#define SPACESHIP_GAME_DEFINE_H

#include <array>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Network.hpp"
#include "SFML/System.hpp"
#include "SFML/Window.hpp"

using namespace sf;

template <arithmetic T, arithmetic U, arithmetic V>
void clamp(T& n, U lower, V upper)
{
	if (n < lower)
		n = static_cast<T>(lower);
	if (n > upper)
		n = static_cast<T>(upper);
}

#endif // SPACESHIP_GAME_DEFINE_H