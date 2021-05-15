////////////////////////////////////////////////////////////
// 
// This is an added file for this modified version of SFML 2.5.1
// Modified by Justyn Durnford
// Last modified on 2021-05-15
// 
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef SFML_FIXEDMATRIX_HPP
#define SFML_FIXEDMATRIX_HPP

#include <algorithm>
#include <array>
#include <concepts>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace sf
{
	template <std::semiregular T, std::size_t R, std::size_t C> class FixedMatrix
	{
		std::array<std::array<T, C>, R> matrix_;

		// 
		void checkBounds(std::size_t x, std::size_t y)
		{
			if (y >= R)
				throw std::out_of_range("Invalid row index");
			if (x >= C)
				throw std::out_of_range("Invalid column index");
		}

		public:

		// 
		FixedMatrix() = default;

		// 
		FixedMatrix(const T& value)
		{
			for (std::size_t r = 0u; r < R; ++r)
			{
				for (std::size_t c = 0u; c < C; ++c)
					matrix_[r][c] = value;
			}
		}

		// 
		FixedMatrix(std::initializer_list<std::initializer_list<T>> list)
		{
			std::size_t i = 0;

			for (auto row : list)
			{
				std::copy(row.begin(), row.end(), matrix_[i].begin());
				++i;
			}
		}

		// 
		FixedMatrix(const FixedMatrix& other) = default;

		// 
		FixedMatrix(FixedMatrix&& other) = default;

		// 
		FixedMatrix& operator = (std::initializer_list<std::initializer_list<T>> list)
		{
			std::size_t i = 0;

			for (auto row : list)
			{
				std::copy(row.begin(), row.end(), matrix_[i].begin());
				++i;
			}

			return *this;
		}

		// 
		FixedMatrix& operator = (const FixedMatrix& other) = default;

		// 
		FixedMatrix& operator = (FixedMatrix && other) = default;

		// 
		~FixedMatrix() = default;

		// 
		std::size_t rowSize() const
		{
			return R;
		}

		// 
		std::size_t colSize() const
		{
			return C;
		}

		// 
		bool isEmpty() const
		{
			return (R == 0u) || (C == 0u);
		}

		// 
		T& at(std::size_t x, std::size_t y)
		{
			checkBounds(x, y);
			return matrix_[y][x];
		}

		// 
		const T& at(std::size_t x, std::size_t y) const
		{
			checkBounds(x, y);
			return matrix_[y][x];
		}

		// 
		void set(std::size_t x, std::size_t y, const T& value)
		{
			checkBounds(x, y);
			matrix_[y][x] = value;
		}

		// 
		T& operator () (std::size_t x, std::size_t y)
		{
			return matrix_[y][x];
		}

		// 
		const T& operator () (std::size_t x, std::size_t y) const
		{
			return matrix_[y][x];
		}
	};
}

#endif // SFML_FIXEDMATRIX_HPP