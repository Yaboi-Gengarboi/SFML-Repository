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

#ifndef SFML_POINT3_HPP
#define SFML_POINT3_HPP

#include <cmath>
#include <string>

namespace sf
{
	template <typename T> class Point3
	{
		public:

		T x;
		T y;
		T z;

		// 
		Point3()
		{
			x = static_cast<T>(0);
			y = static_cast<T>(0);
			z = static_cast<T>(0);
		}

		// 
		Point3(T X, T Y, T Z)
		{
			x = X;
			y = Y;
			z = Z;
		}

		// 
		template <typename U>
		explicit Point3(const Point3<U>& other)
		{
			x = static_cast<T>(other.x);
			y = static_cast<T>(other.y);
			z = static_cast<T>(other.z);
		}

		// \brief Returns a std::string representation of the Point3.
		std::string toString() const
		{
			return '(' + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ')';
		}
	};

	// Returns the distance between the two Point3s.
	template <typename T, typename U>
	double distance_between(const Point3<T>& A, const Point3<U>& B)
	{
		return std::sqrt(std::pow(B.x - A.x, 2) + std::pow(B.y - A.y, 2) + std::pow(B.z - A.z, 2));
	}

	// Define common types
	typedef sf::Point3<char>           Point3c;
	typedef sf::Point3<unsigned char>  Point3uc;
	typedef sf::Point3<short>          Point3s;
	typedef sf::Point3<unsigned short> Point3us;
	typedef sf::Point3<int>            Point3i;
	typedef sf::Point3<unsigned int>   Point3u;
	typedef sf::Point3<float>          Point3f;
}

// Equality comparison operator.
// Returns true if:
//  - A.x == B.x AND
//  - A.y == B.y AND
//  - A.z == B.z
// Returns false otherwise.
template <typename T, typename U>
bool operator == (const sf::Point3<T>& A, const sf::Point3<U>& B)
{
	return (A.x == B.x) && (A.y == B.y) && (A.z == B.z);
}

// Inequality comparison operator.
// Returns true if:
//  - A.x != B.x OR
//  - A.y != B.y OR
//  - A.z != B.z
// Returns false otherwise.
template <typename T, typename U>
bool operator != (const sf::Point3<T>& A, const sf::Point3<U>& B)
{
	return (A.x != B.x) || (A.y != B.y) || (A.z != B.z);
}

#endif // SFML_POINT3_HPP