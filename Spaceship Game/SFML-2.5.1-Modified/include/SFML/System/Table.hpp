////////////////////////////////////////////////////////////
// 
// This is an added file for this modified version of SFML 2.5.1
// Modified by Justyn Durnford
// Last modified on 2021-05-19
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

#ifndef SFML_TABLE_HPP
#define SFML_TABLE_HPP

#include <algorithm>
#include <concepts>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <vector>

namespace sf
{
	template <std::semiregular T> class Table
	{
		std::vector<std::vector<T>> data_;

		//
		inline void checkRow(std::size_t r) const
		{
			if (r >= data_.size())
				throw std::out_of_range("Invalid row index");
		}

		//
		inline void checkCol(std::size_t r, std::size_t c) const
		{
			if (c >= data_[r].size())
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
		Table() = default;

		// 
		Table(std::size_t rows, std::size_t cols)
		{
			data_.resize(rows);
			data_.shrink_to_fit();

			for (std::size_t r = 0; r < rows; ++r)
			{
				data_[r].resize(cols);
				data_[r].shrink_to_fit();
			}
		}

		// 
		Table(std::size_t rows, std::size_t cols, const T& value)
		{
			data_.resize(rows);
			data_.shrink_to_fit();

			for (std::size_t r = 0; r < rows; ++r)
			{
				data_[r].resize(cols, value);
				data_[r].shrink_to_fit();
			}
		}

		// 
		Table(std::initializer_list<std::initializer_list<T>> list)
		{
			data_.resize(list.size());
			data_.shrink_to_fit();
			
			std::size_t r = 0;

			for (const auto& row : list)
			{
				data_[r].resize(row.size());
				data_[r].shrink_to_fit();

				std::copy(row.begin(), row.end(), data_[r].begin());
				++r;
			}
		}

		// 
		Table(const Table& other) = default;

		// 
		Table(Table&& other) = default;

		// 
		Table& operator = (std::initializer_list<std::initializer_list<T>> list)
		{
			data_.resize(list.size());
			data_.shrink_to_fit();

			std::size_t r = 0;

			for (const auto& row : list)
			{
				data_[r].resize(row.size());
				data_[r].shrink_to_fit();

				std::copy(row.begin(), row.end(), data_[r].begin());
				++r;
			}

			return *this;
		}

		// 
		Table& operator = (const Table& other) = default;

		// 
		Table& operator = (Table && other) = default;

		// 
		~Table() = default;

		//
		std::size_t rowCount() const
		{
			return data_.size();
		}

		// 
		std::size_t rowSize(std::size_t y) const
		{
			checkRow(y);
			return data_[y].size();
		}

		// 
		std::vector<T> getRow(std::size_t y) const
		{
			checkRow(y);
			return data_[y];
		}

		// 
		std::vector<T> getCol(std::size_t x) const
		{
			std::vector<T> vec(data_.size());

			for (std::size_t r = 0; r < data_.size(); ++r)
			{
				checkCol(r, x);
				vec[r] = data_[r][x];
			}

			return vec;
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
	};
}

#endif // SFML_TABLE_HPP