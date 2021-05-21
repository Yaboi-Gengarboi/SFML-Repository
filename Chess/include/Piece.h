// Chess
// Piece.h
// Justyn Durnford
// Created on 2021-05-16
// Last modified on 2021-05-17
// Header file for the Piece class.

#pragma once

#include "Define.h"

class Piece
{
	uint8_t id_;
	string name_;
	Texture* texturePtr_;
	Sprite sprite_;

	public:

	const static uint8_t WHITE_PAWN   = 0u;
	const static uint8_t WHITE_ROOK   = 1u;
	const static uint8_t WHITE_KNIGHT = 2u;
	const static uint8_t WHITE_BISHOP = 3u;
	const static uint8_t WHITE_QUEEN  = 4u;
	const static uint8_t WHITE_KING   = 5u;
	const static uint8_t BLACK_PAWN   = 6u;
	const static uint8_t BLACK_ROOK   = 7u;
	const static uint8_t BLACK_KNIGHT = 8u;
	const static uint8_t BLACK_BISHOP = 9u;
	const static uint8_t BLACK_QUEEN  = 10u;
	const static uint8_t BLACK_KING   = 11u;

	Piece();

	Piece(uint8_t id, strref name, Texture* texturePtr);

	Piece(const Piece& other) = default;

	Piece(Piece&& other) noexcept;

	Piece& operator = (const Piece& other) = default;

	Piece& operator = (Piece&& other) noexcept;

	~Piece() = default;

	uint8_t id() const;

	strref name() const;

	Texture* texturePtr() const;

	const Sprite& sprite() const;
};