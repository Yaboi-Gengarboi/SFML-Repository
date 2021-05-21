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

#ifndef SFML_FRACTION_HPP
#define SFML_FRACTION_HPP

#include <compare>
#include <concepts>
#include <string>

namespace sf
{
	// This class provides an "exact" representation of the quotient of two 
	// integers by storing them and allowing fraction arithmetic with them. 
	// Use the member function evaluate() to obtain the result of the fraction.
	template <std::integral T> class Fraction
	{
		public:

		T numer;
		T denom;

		// Default constructor.
		Fraction()
		{
			numer = static_cast<T>(0);
			denom = static_cast<T>(1);
		}

		// 1-int constructor.
		// Sets the numerator of the Fraction to numer.
		// Sets the denominator of the Fraction to 1.
		Fraction(T new_numer)
		{
			numer = new_numer;
			denom = static_cast<T>(1);
		}

		// 2-int constructor.
		// Sets the numerator of the Fraction to numer.
		// Sets the denominator of the Fraction to denom.
		Fraction(T new_numer, T new_denom)
		{
			numer = new_numer;
			denom = new_denom;
		}

		// Copy constructor.
		// Copies the values from the passed Fraction into the new Fraction.
		Fraction(const Fraction& other) = default;

		// Move constructor.
		// Moves the passed Fraction into the new Fraction.
		Fraction(Fraction&& other) = default;

		// 1-int assignment operator.
		// Sets the numerator of the Fraction to numer.
		// Sets the denominator of the Fraction to 1.
		Fraction& operator = (T new_numer)
		{
			numer = new_numer;
			denom = static_cast<T>(1);
			return *this;
		}

		// Copy assignment operator.
		// Copies the values from the passed Fraction into the new Fraction.
		Fraction& operator = (const Fraction & other) = default;

		// Move assignment operator.
		// Moves the passed Fraction into the new Fraction.
		Fraction& operator = (Fraction && other) = default;

		// Destructor.
		// Destroys the Fraction and its data.
		~Fraction() = default;

		// Sets the numerator of the Fraction to numer.
		// Sets the denominator of the Fraction to denom.
		void setAll(T new_numer, T new_denom)
		{
			numer = new_numer;
			denom = new_denom;
		}

		// Raises both the numerator and denominator of the Fraction to the nth power.
		template <std::unsigned_integral U> void pow(U n)
		{
			if (n == 1)
				return;

			if (n == 0)
			{
				numer = static_cast<U>(1);
				denom = static_cast<U>(1);
				return;
			}

			T old_numer = numer;
			T old_denom = denom;

			for (U i = 0; i < n; ++i)
			{
				numer *= old_numer;
				denom *= old_denom;
			}
		}

		// Returns the result of the Fraction as a float.
		// This function may throw if a division by 0 is attempted.
		float evaluate() const
		{
			return (1.f * numer) / (1.f * denom);
		}

		// Returns true if the denominator of the Fraction is NOT 0.
		bool isValid() const
		{
			return (denom != 0);
		}

		// Returns true if the denominator of the Fraction is NOT 0.
		operator bool() const
		{
			return (denom != 0);
		}

		// Returns a std::string representation of the Fraction.
		std::string toString() const
		{
			return std::to_string(numer) + " / " + std::to_string(denom);
		}

		// Preincrement operator.
		// Adds 1 onto the Fraction.
		Fraction& operator ++ ()
		{
			numer += denom;
			return *this;
		}

		// Postincrement operator.
		// Adds 1 onto the Fraction.
		Fraction operator ++ (int)
		{
			Fraction fr(*this);
			++(*this);

			return fr;
		}

		// Predecrement operator.
		// Subtracts 1 from the Fraction.
		Fraction& operator -- ()
		{
			numer -= denom;
			return *this;
		}

		// Postdecrement operator.
		// Subtracts 1 from the Fraction.
		Fraction operator -- (int)
		{
			Fraction fr(*this);
			--(*this);

			return fr;
		}

		// Addition assignment operator.
		// Adds the components of the given Fraction onto the
		// corresponding components of this Fraction.
		Fraction& operator += (const Fraction & other)
		{
			if (denom == other.denom)
			{
				numer += other.numer;
				return *this;
			}

			numer *= other.denom;
			denom *= other.denom;

			numer += other.numer * denom;
			return *this;
		}

		// Addition assignment operator.
		// Adds the given value onto this Fraction.
		template <std::integral U> Fraction& operator += (U value)
		{
			numer += value * denom;
			return *this;
		}

		// Subtraction assignment operator.
		// Subtracts the components of the given Fraction from the
		// corresponding components of this Fraction.
		Fraction& operator -= (const Fraction & other)
		{
			if (denom == other.denom)
			{
				numer -= other.numer;
				return *this;
			}

			numer *= other.denom;
			denom *= other.denom;

			numer -= other.numer * denom;
			return *this;
		}

		// Subtraction assignment operator.
		// Subtracts the given value from this Fraction.
		template <std::integral Ty> Fraction& operator -= (Ty value)
		{
			numer -= value * denom;
			return *this;
		}

		// Multiplication assignment operator.
		// Multiplies the components of this Fraction by the
		// corresponding components of the given Fraction.
		Fraction& operator *= (const Fraction & other)
		{
			numer *= other.numer;
			denom *= other.denom;

			return *this;
		}

		// Multiplication assignment operator.
		// Multiplies the numerator of this Fraction by the given value.
		template <std::integral U> Fraction& operator *= (U value)
		{
			numer *= value;
			return *this;
		}

		// Division assignment operator.
		// Divides the components of this Fraction by the
		// corresponding components of the given Fraction.
		Fraction& operator /= (const Fraction & other)
		{
			numer *= other.denom;
			denom *= other.numer;

			return *this;
		}

		// Division assignment operator.
		// Divides the numerator of this Fraction by the given value.
		template <std::integral U> Fraction& operator /= (U value)
		{
			denom *= value;
			return *this;
		}
	};
}

// Addition operator.
template <std::integral T, std::integral U, std::integral V>
sf::Fraction<T> operator + (const sf::Fraction<U>& A, const sf::Fraction<V>& B)
{
	sf::Fraction<T> new_fr(A);
	new_fr += B;
	return new_fr;
}

// Addition operator.
template <std::integral T, std::integral U, std::integral V>
sf::Fraction<T> operator + (const sf::Fraction<U>& fr, V value)
{
	sf::Fraction<T> new_fr(fr);
	new_fr += value;
	return new_fr;
}

// Subtraction operator.
template <std::integral T, std::integral U, std::integral V>
sf::Fraction<T> operator - (const sf::Fraction<U>& A, const sf::Fraction<V>& B)
{
	sf::Fraction<T> new_fr(A);
	new_fr -= B;
	return new_fr;
}

// Subtraction operator.
template <std::integral T, std::integral U, std::integral V>
sf::Fraction<T> operator - (const sf::Fraction<U>& fr, V value)
{
	sf::Fraction<T> new_fr(fr);
	new_fr -= value;
	return new_fr;
}

// Multiplication operator.
template <std::integral T, std::integral U, std::integral V>
sf::Fraction<T> operator * (const sf::Fraction<U>& A, const sf::Fraction<V>& B)
{
	sf::Fraction<T> new_fr(A);
	new_fr *= B;
	return new_fr;
}

// Multiplication operator.
template <std::integral T, std::integral U, std::integral V>
sf::Fraction<T> operator * (const sf::Fraction<U>& fr, V value)
{
	sf::Fraction<T> new_fr(fr);
	new_fr *= value;
	return new_fr;
}

// Division operator.
template <std::integral T, std::integral U, std::integral V>
sf::Fraction<T> operator / (const sf::Fraction<U>& A, const sf::Fraction<V>& B)
{
	sf::Fraction<T> new_fr(A);
	new_fr /= B;
	return new_fr;
}

// Division operator.
template <std::integral T, std::integral U, std::integral V>
sf::Fraction<T> operator / (const sf::Fraction<U>& fr, V value)
{
	sf::Fraction<T> new_fr(fr);
	new_fr /= value;
	return new_fr;
}

// Equality comparison operator.
// Returns true if A.evaluate() == B.evaluate().
template <std::integral T, std::integral U>
bool operator == (const sf::Fraction<T>& A, const sf::Fraction<U>& B)
{
	return A.evaluate() == B.evaluate();
}

// Equality comparison operator.
// - Returns true if fr.evaluate() == f.
// - Returns false otherwise.
template <std::integral T>
bool operator == (const sf::Fraction<T>& fr, float f)
{
	return fr.evaluate() == f;
}

// Inequality comparison operator.
// - Returns true if A.evaluate() != B.evaluate().
// - Returns false otherwise.
template <std::integral T, std::integral U>
bool operator != (const sf::Fraction<T>& A, const sf::Fraction<U>& B)
{
	return A.evaluate() != B.evaluate();
}

// Inequality comparison operator.
// - Returns true if fr.evaluate() != f.
// - Returns false otheriwse.
template <std::integral T>
bool operator != (const sf::Fraction<T>& fr, float f)
{
	return fr.evaluate() != f;
}

// Greater than comparison operator.
// - Returns true if A.evaluate() > B.evaluate().
// - Returns false otherwise.
template <std::integral T, std::integral U>
bool operator > (const sf::Fraction<T>& A, const sf::Fraction<U>& B)
{
	return A.evaluate() > B.evaluate();
}

// Greater than comparison operator.
// - Returns true if fr.evaluate() > f.
// - Returns false otherwise.
template <std::integral T>
bool operator > (const sf::Fraction<T>& fr, float f)
{
	return fr.evaluate() > f;
}

// Greater than or equal to comparison operators.
// - Returns true if A.evaluate() >= B.evaluate().
// - Returns false otherwise.
template <std::integral T, std::integral U>
bool operator >= (const sf::Fraction<T>& A, const sf::Fraction<U>& B)
{
	return A.evaluate() >= B.evaluate();
}

// Greater than or equal to comparison operators.
// - Returns true if fr.evaluate() >= f.
// - Returns false otherwise.
template <std::integral T>
bool operator >= (const sf::Fraction<T>& fr, float f)
{
	return fr.evaluate() >= f;
}

// Less than comparison operator.
// - Returns true if A.evaluate() < B.evaluate().
// - Returns false otherwise.
template <std::integral T, std::integral U>
bool operator < (const sf::Fraction<T>& A, const sf::Fraction<U>& B)
{
	return A.evaluate() < B.evaluate();
}

// Less than comparison operator.
// - Returns true if fr.evaluate() < f.
// - Returns false otherwise.
template <std::integral T>
bool operator < (const sf::Fraction<T>& fr, float f)
{
	return fr.evaluate() < f;
}

// Less than or equal to comparison operator.
// - Returns true if A.evaluate() <= B.evaluate().
// - Returns false otherwise.
template <std::integral T, std::integral U>
bool operator <= (const sf::Fraction<T>& A, const sf::Fraction<U>& B)
{
	return A.evaluate() <= B.evaluate();
}

// Less than or equal to comparison operator.
// - Returns true if fr.evaluate() <= f.
// - Returns false otherwise.
template <std::integral T>
bool operator <= (const sf::Fraction<T>& fr, float f)
{
	return fr.evaluate() <= f;
}

// Three-way comparison operator.
template <std::integral T, std::integral U>
std::strong_ordering operator <=> (const sf::Fraction<T>& A, const sf::Fraction<U>& B)
{
	if (A.evaluate() < B.evaluate())
		return std::strong_ordering::less;

	if (A.evaluate() > B.evaluate())
		return std::strong_ordering::greater;

	return std::strong_ordering::equal;
}

// Three-way comparison operator.
template <std::integral T>
std::strong_ordering operator <=> (const sf::Fraction<T>& fr, float f)
{
	if (fr.evaluate() < f)
		return std::strong_ordering::less;

	if (fr.evaluate() > f)
		return std::strong_ordering::greater;

	return std::strong_ordering::equal;
}

#endif // SFML_FRACTION_HPP