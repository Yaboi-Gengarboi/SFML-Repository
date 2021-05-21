// This is an added file for this modified version of SFML 2.5.1
// Modified by Justyn Durnford
// Last modified on 2021-05-03
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

#ifndef SFML_ARITHMETIC_HPP
#define SFML_ARITHMETIC_HPP

#include <concepts>

namespace sf
{
	#ifndef SFML_ARITHMETIC
	#define SFML_ARITHMETIC

	template <typename T> concept arithmetic = std::is_arithmetic_v<T>;

	#endif // SFML_ARITHMETIC
}

#endif // SFML_ARITHMETIC_HPP