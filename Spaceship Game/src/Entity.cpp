// Spaceship Game
// Entity.cpp
// Justyn Durnford
// Created on 2021-05-07
// Last modified on 2021-05-12
// Source file for the Entity class.

#include "Entity.h"

Entity::Entity() : texturePtr(nullptr) {}

Entity::Entity(Texture* texture_ptr)
{
	texturePtr = texture_ptr;
	sprite.setTexture(*texturePtr);
}

Entity::Entity(Texture* texture_ptr, float x_pos, float y_pos)
{
	texturePtr = texture_ptr;
	sprite.setTexture(*texturePtr);
	sprite.setPosition(x_pos, y_pos);
}

Entity::Entity(Texture* texture_ptr, const Point2f& pos)
{
	texturePtr = texture_ptr;
	sprite.setTexture(*texturePtr);
	sprite.setPosition(pos);
}

Entity::Entity(Texture* texture_ptr, const IntRect& sprite_rect)
{
	texturePtr = texture_ptr;
	sprite.setTexture(*texturePtr);
	sprite.setTextureRect(sprite_rect);
}

Entity::Entity(Texture* texture_ptr, const IntRect& sprite_rect, float x_pos, float y_pos)
{
	texturePtr = texture_ptr;
	sprite.setTexture(*texturePtr);
	sprite.setTextureRect(sprite_rect);
	sprite.setPosition(x_pos, y_pos);
}

Entity::Entity(Texture* texture_ptr, const IntRect& sprite_rect, const Point2f& pos)
{
	texturePtr = texture_ptr;
	sprite.setTexture(*texturePtr);
	sprite.setTextureRect(sprite_rect);
	sprite.setPosition(pos);
}

void Entity::update(Time dt)
{
	float s = dt.asSeconds();
	Point2f pos(sprite.getPosition().x, sprite.getPosition().y);
	sprite.setPosition(pos.x + velocity.x * s, pos.y + velocity.y * s);
}