////////////////////////////////////////////////////////////
// 
// This is a modified version of the SFML 2.5.1 file Vector2.hpp
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

#ifndef SFML_VECTOR2_HPP
#define SFML_VECTOR2_HPP

#include <SFML/System/Point2.hpp>

namespace sf
{
    ////////////////////////////////////////////////////////////
    /// Utility template class for manipulating              ///
    /// 2-dimensional vectors.                               ///
    ////////////////////////////////////////////////////////////
    template <typename T> class Vector2
    {
        public:

        T x;
        T y;

        // \brief Default constructor.
        // Creates a Vector2(0, 0).
        Vector2()
        {
            x = static_cast<T>(0);
            y = static_cast<T>(0);
        }

        // \brief Constructs the Vector2 from the given coordinates.
        // \param X: X coordinate
        // \param Y: Y coordinate
        Vector2(T X, T Y)
        {
            x = X;
            y = Y;
        }

        // \brief Constructs the Vector2 from the given Point2.
        // \param P: Point2 to copy the coordinates from 
        Vector2(const Point2<T>& P)
        {
            x = P.x;
            y = P.y;
        }

        // \brief Constructs the Vector2 as the displacement vector of the two Point2s.
        // \param A: First Point2
        // \param B: Second Point2
        Vector2(const Point2<T>& A, const Point2<T>& B)
        {
            x = B.x - A.x;
            y = B.y - A.y;
        }

        // \brief Construct the Vector2 from another type of Vector2.
        //
        // This constructor doesn't replace the copy constructor,
        // it's called only when U != T.
        // A call to this constructor will fail to compile if U
        // is not convertible to T.
        //
        // \param other: Vector2 to convert
        template <typename U>
        explicit Vector2(const Vector2<U>& other)
        {
            x = static_cast<T>(other.x);
            y = static_cast<T>(other.y);
        }

        // \brief Assigns the Vector2 from the given Point2.
        // \param P: Point2 to copy the coordinates from 
        Vector2& operator = (const Point2<T>& P)
        {
            x = P.x;
            y = P.y;

            return *this;
        }

        // \brief Returns the magnitude of the Vector2.
        float magnitude() const
        {
            return std::sqrt(std::pow(x, 2) + std::pow(y, 2));
        }

        // \brief Returns the endpoint of the Point2.
        Point2<T> endpoint() const
        {
            return Point2<T>(x, y);
        }

        // \brief Returns a unit vector in the direction of the Vector2.
        Vector2<float> unitVector() const
        {
            float m = magnitude();
            return Vector2<float>(x / m, y / m);
        }

        // \brief Returns a std::string representation of the Vector2.
        std::string toString() const
        {
            return '<' + std::to_string(x) + ", " + std::to_string(y) + '>';
        }
    };

    // \brief Returns the dot product of the 2 given Vector2s.
    template <typename T, typename U, typename V>
    T dot_product(const Vector2<U>& A, const Vector2<V>& B)
    {
        return static_cast<T>(A.x * B.x + A.y * B.y);
    }

    // \brief Returns the scalar projection of A onto B.
    template <typename T, typename U>
    double scalar_proj(const Vector2<T>& A, const Vector2<U>& B)
    {
        return dot_product(A, B) / A.magnitude();
    }

    // \brief Returns the vector projection of A onto B.
    template <typename T, typename U>
    Vector2<float> vector_proj(const Vector2<T>& A, const Vector2<T>& B)
    {
        float f = (dot_product(A, B) * 1.f / dot_product(A, A) * 1.f);
        return Vector2<float>(A.x * f, A.y * f);
    }

    // \brief Determines if the 2 given Vector2s are orthogonal to eachother.
    // - Returns true if dot_product(A, B) == 0.
    // - Returns false otherwise.
    template <typename T, typename U>
    bool are_normal(const Vector2<T>& A, const Vector2<U>& B)
    {
        return dot_product(A, B) == 0.f;
    }

    // Define common types
    typedef sf::Vector2<char>           Vector2c;
    typedef sf::Vector2<unsigned char>  Vector2uc;
    typedef sf::Vector2<short>          Vector2s;
    typedef sf::Vector2<unsigned short> Vector2us;
    typedef sf::Vector2<int>            Vector2i;
    typedef sf::Vector2<unsigned int>   Vector2u;
    typedef sf::Vector2<float>          Vector2f;
}

// \brief Overload of unary operator -
template <typename T> 
sf::Vector2<T> operator - (const sf::Vector2<T>& A)
{
    return sf::Vector2<T>(-A.x, -A.y);
}

// \brief Overload of binary operator +
template <typename T> 
sf::Vector2<T> operator + (const sf::Vector2<T>& A, const sf::Vector2<T>& B)
{
    return sf::Vector2<T>(A.x + B.x, A.y + B.y);
}

// \brief Overload of binary operator -
template <typename T>
sf::Vector2<T> operator - (const sf::Vector2<T>& A, const sf::Vector2<T>& B)
{
    return sf::Vector2<T>(A.x - B.x, A.y - B.y);
}

// \brief Overload of binary operator *
template <typename T, typename U>
sf::Vector2<T> operator * (const sf::Vector2<T>& A, U B)
{
    return sf::Vector2<T>(A.x * B, A.y * B);
}

// \brief Overload of binary operator *
template <typename T, typename U>
sf::Vector2<T> operator * (U A, const sf::Vector2<T>& B)
{
    return sf::Vector2<T>(B.x * A, B.y * A);
}

// \brief Overload of binary operator /
template <typename T, typename U>
sf::Vector2<T> operator / (const sf::Vector2<T>& A, U B)
{
    return sf::Vector2<T>(A.x / B, A.y / B);
}

// \brief Overload of binary operator +=
template <typename T>
sf::Vector2<T>& operator += (sf::Vector2<T>& A, const sf::Vector2<T>& B)
{
    A.x += B.x;
    A.y += B.y;

    return A;
}

// \brief Overload of binary operator -=
template <typename T>
sf::Vector2<T>& operator -= (sf::Vector2<T>& A, const sf::Vector2<T>& B)
{
    A.x -= B.x;
    A.y -= B.y;

    return A;
}

// \brief Overload of binary operator *=
template <typename T, typename U>
sf::Vector2<T>& operator *= (sf::Vector2<T>& A, U B)
{
    A.x *= B;
    A.y *= B;

    return A;
}

// \brief Overload of binary operator /=
template <typename T, typename U>
sf::Vector2<T>& operator /= (sf::Vector2<T>& A, U B)
{
    A.x /= B;
    A.y /= B;

    return A;
}

// \brief Overload of binary operator ==
template <typename T, typename U>
bool operator == (const sf::Vector2<T>& A, const sf::Vector2<U>& B)
{
    return (A.x == B.x) && (A.y == B.y);
}

// \brief Overload of binary operator !=
template <typename T, typename U>
bool operator != (const sf::Vector2<T>& A, const sf::Vector2<U>& B)
{
    return (A.x != B.x) || (A.y != B.y);
}

#endif // SFML_VECTOR2_HPP