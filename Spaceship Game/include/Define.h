// Spaceship Game
// Define.h
// Justyn Durnford
// Created on 2021-05-07
// Last modified on 2021-05-13
// 

#pragma once

#include <array>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <random>
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

template <arithmetic T, arithmetic U>
void clamp_min(T& n, U lower)
{
	if (n > lower)
		n = static_cast<T>(lower);
}

template <arithmetic T, arithmetic U>
void clamp_max(T& n, U upper)
{
	if (n < upper)
		n = static_cast<T>(upper);
}

const uint32_t window_width = 800u;
const uint32_t window_height = 600u;