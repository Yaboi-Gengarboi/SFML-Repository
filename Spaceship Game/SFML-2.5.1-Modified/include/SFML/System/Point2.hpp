////////////////////////////////////////////////////////////
// 
// This is an added file for this modified version of SFML 2.5.1
// Modified by Justyn Durnford
// Last modified on 2021-05-11
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

#ifndef SFML_POINT2_HPP
#define SFML_POINT2_HPP

#include <cmath>
#include <string>

namespace sf
{
	template <typename T> class Point2
	{
		public:

		T x;
		T y;

		// 
		Point2()
		{
			x = static_cast<T>(0);
			y = static_cast<T>(0);
		}

		// 
		Point2(T X, T Y)
		{
			x = X;
			y = Y;
		}

		// 
		template <typename U>
		explicit Point2(const Point2<U>& other)
		{
			x = static_cast<T>(other.x);
			y = static_cast<T>(other.y);
		}

		// \brief Returns a std::string representation of the Point2.
		std::string toString() const
		{
			return '(' + std::to_string(x) + ", " + std::to_string(y) + ')';
		}
	};

	// Returns the distance between the two Point2s.
	template <typename T, typename U>
	double distance_between(const Point2<T>& A, const Point2<U>& B)
	{
		return std::sqrt(std::pow(B.x - A.x, 2) + std::pow(B.y - A.y, 2));
	}

	// Define common types
	typedef sf::Point2<char>           Point2c;
	typedef sf::Point2<unsigned char>  Point2uc;
	typedef sf::Point2<short>          Point2s;
	typedef sf::Point2<unsigned short> Point2us;
	typedef sf::Point2<int>            Point2i;
	typedef sf::Point2<unsigned int>   Point2u;
	typedef sf::Point2<float>          Point2f;
}

// Equality comparison operator.
// Returns true if:
//  - A.x == B.x AND
//  - A.y == B.y
// Returns false otherwise.
template <typename T, typename U>
bool operator == (const sf::Point2<T>& A, const sf::Point2<U>& B)
{
	return (A.x == B.x) && (A.y == B.y);
}

// Inequality comparison operator.
// Returns true if:
//  - A.x != B.x OR
//  - A.y != B.y
// Returns false otherwise.
template <typename T, typename U>
bool operator != (const sf::Point2<T>& A, const sf::Point2<U>& B)
{
	return (A.x != B.x) || (A.y != B.y);
}

#endif // SFML_POINT2_HPP