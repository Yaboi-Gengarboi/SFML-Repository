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

#ifndef SFML_MATRIX_HPP
#define SFML_MATRIX_HPP

#include <algorithm>
#include <concepts>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>

namespace sf
{
	template <std::semiregular T> class Matrix
	{
		T** matrix_;
		std::size_t rows_;
		std::size_t cols_;

		// 
		void allocate(std::size_t rows, std::size_t cols)
		{
			rows_ = rows;
			cols_ = cols;

			try
			{
				matrix_ = new T*[rows_];
				for (std::size_t r = 0u; r < rows_; ++r)
					matrix_[r] = new T[cols_];
			}
			catch (const std::bad_alloc& exc)
			{
				null();
				throw exc;
				return;
			}
		}

		// 
		void deallocate() noexcept
		{
			for (std::size_t r = 0u; r < rows_; ++r)
				delete[] matrix_[r];
			delete[] matrix_;
		}

		// 
		void reallocate(std::size_t rows, std::size_t cols)
		{
			if (rows != rows_ || cols != cols_)
			{
				deallocate();
				allocate(rows, cols);
			}
		}

		// 
		void null() noexcept
		{
			for (std::size_t r = 0u; r < rows_; ++r)
				matrix_[r] = nullptr;
			matrix_ = nullptr;
		}

		// 
		void checkBounds(std::size_t x, std::size_t y)
		{
			if (y >= rows_)
				throw std::out_of_range("Invalid row index");
			if (x >= cols_)
				throw std::out_of_range("Invalid column index");
		}

		public:

		// 
		Matrix()
		{
			matrix_ = nullptr;
			rows_ = std::size_t(0u);
			cols_ = std::size_t(0u);
		}

		// 
		Matrix(std::size_t rows, std::size_t cols)
		{
			allocate(rows, cols);
		}

		// 
		Matrix(std::size_t rows, std::size_t cols, const T& val)
		{
			allocate(rows, cols);

			for (std::size_t r = 0u; r < rows_; ++r)
			{
				for (std::size_t c = 0u; c < cols_; ++c)
					matrix_[r][c] = val;
			}
		}

		// 
		Matrix(std::initializer_list<std::initializer_list<T>> list)
		{
			std::size_t c(0u);
			for (auto row : list)
			{
				if (row.size() > c)
					c = row.size();
			}

			allocate(list.size(), c);

			std::size_t r(0u);
			c = 0u;
			auto row_iter(list.begin());

			while (row_iter != list.end())
			{
				auto col_iter(row_iter->begin());

				while (col_iter != row_iter->end())
				{
					matrix_[r][c] = *col_iter;
					++c;
					++col_iter;
				}

				c = 0u;
				++r;
				++row_iter;
			}
		}

		// 
		Matrix(const Matrix& other)
		{
			allocate(other.rows_, other.cols_);

			for (std::size_t r = 0u; r < rows_; ++r)
			{
				for (std::size_t c = 0u; c < cols_; ++c)
					matrix_[r][c] = other.matrix_[r][c];
			}
		}

		// 
		Matrix(Matrix&& other) noexcept
		{
			matrix_ = other.matrix_;
			rows_ = other.rows_;
			cols_ = other.cols_;

			other.null();
		}

		// 
		Matrix& operator = (std::initializer_list<std::initializer_list<T>> list)
		{
			deallocate();

			std::size_t c(0u);
			for (auto row : list)
			{
				if (row.size() > c)
					c = row.size();
			}

			allocate(list.size(), c);

			std::size_t r(0u);
			c = 0u;
			auto row_iter(list.begin());

			while (row_iter != list.end())
			{
				auto col_iter(row_iter->begin());

				while (col_iter != row_iter->end())
				{
					matrix_[r][c] = *col_iter;
					++c;
					++col_iter;
				}

				c = 0u;
				++r;
				++row_iter;
			}

			return *this;
		}

		// 
		Matrix& operator = (const Matrix& other)
		{
			deallocate();
			allocate(other.rows_, other.cols_);

			for (std::size_t r = 0u; r < rows_; ++r)
			{
				for (std::size_t c = 0u; c < cols_; ++c)
					matrix_[r][c] = other.matrix_[r][c];
			}

			return *this;
		}

		// 
		Matrix& operator = (Matrix&& other) noexcept
		{
			deallocate();

			matrix_ = other.matrix_;
			rows_ = other.rows_;
			cols_ = other.cols_;

			other.null();
			return *this;
		}

		// 
		~Matrix() noexcept
		{
			deallocate();
		}

		// 
		std::size_t rowSize() const
		{
			return rows_;
		}

		// 
		std::size_t colSize() const
		{
			return cols_;
		}

		// 
		bool isEmpty() const
		{
			return (rows_ == 0u) || (cols_ == 0u);
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

#endif // SFML_MATRIX_HPP