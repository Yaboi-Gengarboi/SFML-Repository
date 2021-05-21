// Chess
// Piece.cpp
// Justyn Durnford
// Created on 2021-05-17
// Last modified on 2021-05-17
// Source file for the Piece class.

#include "Piece.h"

Piece::Piece()
{
	id_ = 0;
	name_ = "";
	texturePtr_ = nullptr;
	sprite_.setTexture(*texturePtr_);
}

Piece::Piece(uint8_t id, strref name, Texture* texturePtr)
{
	id_ = id;
	name_ = name;
	texturePtr_ = texturePtr;
	sprite_.setTexture(*texturePtr_);
}

Piece::Piece(Piece&& other) noexcept
{
	id_ = other.id_;
	other.id_ = 0u;

	name_ = move(other.name_);

	texturePtr_ = other.texturePtr_;
	other.texturePtr_ = nullptr;

	sprite_.setTexture(*texturePtr_);
}

Piece& Piece::operator = (Piece&& other) noexcept
{
	id_ = other.id_;
	other.id_ = 0u;

	name_ = move(other.name_);

	texturePtr_ = other.texturePtr_;
	other.texturePtr_ = nullptr;

	sprite_.setTexture(*texturePtr_);

	return *this;
}

uint8_t Piece::id() const
{
	return id_;
}

strref Piece::name() const
{
	return name_;
}

Texture* Piece::texturePtr() const
{
	return texturePtr_;
}

const Sprite& Piece::sprite() const
{
	return sprite_;
}