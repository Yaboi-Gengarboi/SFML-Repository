////////////////////////////////////////////////////////////
// 
// This is an added file for this modified version of SFML 2.5.1
// Modified by Justyn Durnford
// Last modified on 2021-05-20
// 
// SFML - Simple and Fast Multimedia Library
// Copyright (X) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
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

#ifndef SFML_MATRIX_HPP
#define SFML_MATRIX_HPP

#include <SFML/System/Arithmetic.hpp>

#include <algorithm>
#include <array>
#include <concepts>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace sf
{
	template <arithmetic T, std::size_t X, std::size_t Y> class Matrix
	{
		// Private member variable
		std::array<std::array<T, X>, Y> data_;

		// Private member functions

		//
		inline void checkRow(std::size_t r) const
		{
			if (r >= Y)
				throw std::out_of_range("Invalid row index");
		}

		//
		inline void checkCol(std::size_t c) const
		{
			if (c >= X)
				throw std::out_of_range("Invalid column index");
		}

		// 
		void checkBounds(std::size_t x, std::size_t y) const
		{
			checkRow(y);
			checkCol(x);
		}

		public:

		using value_type = T;
		using size_type = std::size_t;
		using reference = T&;
		using const_reference = const T&;

		// 
		Matrix() = default;

		// 
		Matrix(const T& value)
		{
			for (std::size_t r(0u); r < Y; ++r)
			{
				for (std::size_t c(0u); c < X; ++c)
					data_[r][c] = value;
			}
		}

		// 
		Matrix(std::initializer_list<std::initializer_list<T>> list)
		{
			std::size_t r(0u);

			for (const auto& row : list)
			{
				std::copy(row.begin(), row.begin() + X, data_[r].begin());
				++r;
			}
		}

		// 
		template <arithmetic U>
		explicit Matrix(const Matrix<U, X, Y>& other)
		{
			for (std::size_t r(0u); r < Y; ++r)
			{
				for (std::size_t c(0u); c < X; ++c)
					data_[r][c] = static_cast<T>(other.data_[r][c]);
			}
		}

		// 
		Matrix(const Matrix& other) = default;

		// 
		Matrix(Matrix&& other) = default;

		// 
		Matrix& operator = (std::initializer_list<std::initializer_list<T>> list)
		{
			std::size_t r(0u);

			for (const auto& row : list)
			{
				std::copy(row.begin(), row.begin() + X, data_[r].begin());
				++r;
			}

			return *this;
		}

		// 
		Matrix& operator = (const Matrix& other) = default;

		// 
		Matrix& operator = (Matrix && other) = default;

		// 
		~Matrix() = default;

		// 
		std::size_t rowCount() const
		{
			return Y;
		}

		// 
		std::size_t colCount() const
		{
			return X;
		}

		//
		std::array<T, X> getRow(std::size_t y) const
		{
			checkRow(y);
			return data_[y];
		}

		//
		std::array<T, Y> getCol(std::size_t x) const
		{
			checkRow(x);
			std::array<T, Y> arr;

			for (std::size_t r = 0; r < Y; ++r)
				arr[r] = data_[r][x];

			return arr;
		}

		// 
		T& at(std::size_t x, std::size_t y)
		{
			checkBounds(x, y);
			return data_[y][x];
		}

		// 
		const T& at(std::size_t x, std::size_t y) const
		{
			checkBounds(x, y);
			return data_[y][x];
		}

		// 
		void set(std::size_t x, std::size_t y, const T& value)
		{
			checkBounds(x, y);
			data_[y][x] = value;
		}

		// 
		T& operator () (std::size_t x, std::size_t y)
		{
			return data_[y][x];
		}

		// 
		const T& operator () (std::size_t x, std::size_t y) const
		{
			return data_[y][x];
		}

		// 
		template <arithmetic U> 
		Matrix& operator += (const Matrix<U, X, Y>& other)
		{
			for (std::size_t r(0u); r < Y; ++r)
			{
				for (std::size_t c(0u); c < X; ++c)
					data_[r][c] += static_cast<T>(other.data_[r][c]);
			}

			return *this;
		}

		// 
		template <arithmetic U>
		Matrix& operator -= (const Matrix<U, X, Y>& other)
		{
			for (std::size_t r(0u); r < Y; ++r)
			{
				for (std::size_t c(0u); c < X; ++c)
					data_[r][c] -= static_cast<T>(other.data_[r][c]);
			}

			return *this;
		}

		// 
		template <arithmetic U> 
		Matrix& operator *= (U scalar)
		{
			for (std::size_t r(0u); r < Y; ++r)
			{
				for (std::size_t c(0u); c < X; ++c)
					data_[r][c] *= scalar;
			}

			return *this;
		}

		// 
		template <arithmetic U> 
		Matrix& operator /= (U scalar)
		{
			for (std::size_t r(0u); r < Y; ++r)
			{
				for (std::size_t c(0u); c < X; ++c)
					data_[r][c] /= scalar;
			}

			return *this;
		}
	};

	template <arithmetic T> 
	inline T determinant(const Matrix<T, 2, 2>& M)
	{
		return (M(0, 0) * M(1, 1)) - (M(0, 1) * M(1, 0));
	}
	
	template <arithmetic T>
	T determinant(const Matrix<T, 3, 3>& M)
	{
		Matrix<T, 2, 2> A
		{
			{ M(1, 1), M(2, 1) },
			{ M(1, 2), M(2, 2) }
		};

		Matrix<T, 2, 2> B
		{
			{ M(0, 1), M(2, 1) },
			{ M(0, 2), M(2, 2) }
		};

		Matrix<T, 2, 2> X
		{
			{ M(0, 1), M(1, 1) },
			{ M(0, 2), M(1, 2) }
		};

		return (M(0, 0) * determinant(A)) - (M(1, 0) * determinant(B)) + (M(2, 0) * determinant(X));
	}
}

template <sf::arithmetic T, std::size_t X, std::size_t Y>
sf::Matrix<T, X, Y> operator + (const sf::Matrix<T, X, Y>& A, const sf::Matrix<T, X, Y>& B)
{
	sf::Matrix<T, X, Y> M;

	for (std::size_t r(0u); r < Y; ++r)
	{
		for (std::size_t c(0u); c < X; ++c)
			M(r, c) = A(r, c) + B(r, c);
	}

	return M;
}

template <sf::arithmetic T, std::size_t X, std::size_t Y>
sf::Matrix<T, X, Y> operator - (const sf::Matrix<T, X, Y>& A, const sf::Matrix<T, X, Y>& B)
{
	sf::Matrix<T, X, Y> M;

	for (std::size_t r(0u); r < Y; ++r)
	{
		for (std::size_t c(0u); c < X; ++c)
			M(r, c) = A(r, c) - B(r, c);
	}

	return M;
}

template <sf::arithmetic T, sf::arithmetic U, std::size_t X, std::size_t Y>
sf::Matrix<T, X, Y> operator * (const sf::Matrix<T, X, Y>& A, U scalar)
{
	sf::Matrix<T, X, Y> M(A);
	M *= scalar;

	return M;
}

template <sf::arithmetic T, sf::arithmetic U, std::size_t X, std::size_t Y>
sf::Matrix<T, X, Y> operator / (const sf::Matrix<T, X, Y>& A, U scalar)
{
	sf::Matrix<T, X, Y> M(A);
	M /= scalar;

	return M;
}

#endif // SFML_MATRIX_HPP