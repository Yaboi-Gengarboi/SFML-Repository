// Spaceship Game
// Enemy.cpp
// Justyn Durnford
// Created on 2021-05-13
// Last modified on 2021-05-13
// Source file for the Enemy class.

#include "Enemy.h"

random_device rand_dev;
default_random_engine rand_engine(rand_dev());
uniform_int_distribution<uint32_t> rand_dist(0u, 9999u);

Enemy::Enemy(Texture* texture_ptr)
	: Entity(texture_ptr), turnChance_(0u) {}

Enemy::Enemy(Texture* texture_ptr, float x_pos, float y_pos)
	: Entity(texture_ptr, x_pos, y_pos), turnChance_(0u) {}

Enemy::Enemy(Texture* texture_ptr, const Point2f& pos)
	: Entity(texture_ptr, pos), turnChance_(0u) {}

Enemy::Enemy(Texture* texture_ptr, const IntRect& sprite_rect)
	: Entity(texture_ptr, sprite_rect), turnChance_(0u) {}

Enemy::Enemy(Texture* texture_ptr, const IntRect& sprite_rect, float x_pos, float y_pos)
	: Entity(texture_ptr, sprite_rect, x_pos, y_pos), turnChance_(0u) {}

Enemy::Enemy(Texture* texture_ptr, const IntRect& sprite_rect, const Point2f& pos)
	: Entity(texture_ptr, sprite_rect, pos), turnChance_(0u) {}

void Enemy::update(Time dt)
{
	turnChance_ += 5u;
	clamp_max(turnChance_, 9999u);

	if (turnChance_ > rand_dist(rand_engine))
	{

	}
}