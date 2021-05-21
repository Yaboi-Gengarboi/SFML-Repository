////////////////////////////////////////////////////////////
// 
// This is a modified version of the SFML 2.5.1 file Vector3.hpp
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

#ifndef SFML_VECTOR3_HPP
#define SFML_VECTOR3_HPP

#include <SFML/System/Point3.hpp>

namespace sf
{
    ////////////////////////////////////////////////////////////
    /// Utility template class  for manipulating             ///
    /// 2-dimensional vectors.                               ///
    ////////////////////////////////////////////////////////////
    template <typename T> class Vector3
    {
        public:

        T x;
        T y;
        T z;

        // \brief Default constructor.
        // Creates a Vector3(0, 0, 0).
        Vector3()
        {
            x = static_cast<T>(0);
            y = static_cast<T>(0);
            z = static_cast<T>(0);
        }

        // \brief Constructs the Vector3 from the given coordinates.
        // \param X: X coordinate
        // \param Y: Y coordinate
        // \param Z: Z coordinate
        Vector3(T X, T Y, T Z)
        {
            x = X;
            y = Y;
            z = Z;
        }

        // \brief Constructs the Vector3 from the given Point3.
        // \param P: Point3 to copy the coordinates from 
        Vector3(const Point3<T>& P)
        {
            x = P.x;
            y = P.y;
            z = P.z;
        }

        // \brief Constructs the Vector3 as the displacement vector of the two Point3s.
        // \param A: First Point3
        // \param B: Second Point3
        Vector3(const Point3<T>& A, const Point3<T>& B)
        {
            x = B.x - A.x;
            y = B.y - A.y;
            z = B.z - A.z;
        }

        // \brief Construct the Vector3 from another type of Vector3.
        //
        // This constructor doesn't replace the copy constructor,
        // it's called only when U != T.
        // A call to this constructor will fail to compile if U
        // is not convertible to T.
        //
        // \param other: Vector3 to convert
        template <typename U>
        explicit Vector3(const Vector3<U>& other)
        {
            x = static_cast<T>(other.x);
            y = static_cast<T>(other.y);
            z = static_cast<T>(other.z);
        }

        // \brief Assigns the Vector3 from the given Point3.
        // \param P: Point3 to copy the coordinates from 
        Vector3& operator = (const Point3<T>& P)
        {
            x = P.x;
            y = P.y;
            z = P.z;

            return *this;
        }

        // \brief Returns the magnitude of the Vector3.
        float magnitude() const
        {
            return std::sqrt(std::pow(x, 2) + std::pow(y, 2) + std::pow(z, 2));
        }

        // \brief Returns the endpoint of the Point3.
        Point3<T> endpoint() const
        {
            return Point3<T>(x, y, z);
        }

        // \brief Returns a unit vector in the direction of the Vector3.
        Vector3<float> unitVector() const
        {
            float m = magnitude();
            return Vector3<float>(x / m, y / m, z / m);
        }

        // \brief Returns a std::string representation of the Vector3.
        std::string toString() const
        {
            return '<' + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + '>';
        }
    };

    // \brief Returns the dot product of the 2 given Vector3s.
    template <typename T, typename U, typename V>
    T dot_product(const Vector3<U>& A, const Vector3<V>& B)
    {
        return static_cast<T>(A.x * B.x + A.y * B.y + A.z * B.z);
    }

    // \brief Returns the scalar projection of A onto B.
    template <typename T, typename U>
    float scalar_proj(const Vector3<T>& A, const Vector3<U>& B)
    {
        return dot_product(A, B) / A.magnitude();
    }

    // \brief Returns the vector projection of A onto B.
    template <typename T, typename U>
    Vector3<float> vector_proj(const Vector3<T>& A, const Vector3<T>& B)
    {
        float f = (dot_product(A, B) * 1.f / dot_product(A, A) * 1.f);
        return Vector3<double>(A.x * f, A.y * f, A.z * f);
    }

    // \brief Determines if the 2 given Vector3s are orthogonal to eachother.
    // - Returns true if dot_product(A, B) == 0.
    // - Returns false otherwise.
    template <typename T, typename U>
    bool are_normal(const Vector3<T>& A, const Vector3<U>& B)
    {
        return dot_product(A, B) == 0.f;
    }

    // Define common types
    typedef sf::Vector3<char>           Vector3c;
    typedef sf::Vector3<unsigned char>  Vector3uc;
    typedef sf::Vector3<short>          Vector3s;
    typedef sf::Vector3<unsigned short> Vector3us;
    typedef sf::Vector3<int>            Vector3i;
    typedef sf::Vector3<unsigned int>   Vector3u;
    typedef sf::Vector3<float>          Vector3f;
}

// \brief Overload of unary operator -
template <typename T>
sf::Vector3<T> operator - (const sf::Vector3<T>& A)
{
    return sf::Vector3<T>(-A.x, -A.y, -A.z);
}

// \brief Overload of binary operator +
template <typename T>
sf::Vector3<T> operator + (const sf::Vector3<T>& A, const sf::Vector3<T>& B)
{
    return sf::Vector3<T>(A.x + B.x, A.y + B.y, A.z + B.z);
}

// \brief Overload of binary operator -
template <typename T>
sf::Vector3<T> operator - (const sf::Vector3<T>& A, const sf::Vector3<T>& B)
{
    return sf::Vector3<T>(A.x - B.x, A.y - B.y, A.z - B.z);
}

// \brief Overload of binary operator *
template <typename T, typename U>
sf::Vector3<T> operator * (const sf::Vector3<T>& A, U B)
{
    return sf::Vector3<T>(A.x * B, A.y * B, A.z * B);
}

// \brief Overload of binary operator *
template <typename T, typename U>
sf::Vector3<T> operator * (U A, const sf::Vector3<T>& B)
{
    return sf::Vector3<T>(B.x * A, B.y * A, B.z * A);
}

// \brief Overload of binary operator /
template <typename T, typename U>
sf::Vector3<T> operator / (const sf::Vector3<T>& A, U B)
{
    return sf::Vector3<T>(A.x / B, A.y / B, A.z / B);
}

// \brief Overload of binary operator +=
template <typename T>
sf::Vector3<T>& operator += (sf::Vector3<T>& A, const sf::Vector3<T>& B)
{
    A.x += B.x;
    A.y += B.y;
    A.z += B.z;

    return A;
}

// \brief Overload of binary operator -=
template <typename T>
sf::Vector3<T>& operator -= (sf::Vector3<T>& A, const sf::Vector3<T>& B)
{
    A.x -= B.x;
    A.y -= B.y;
    A.z -= B.z;

    return A;
}

// \brief Overload of binary operator *=
template <typename T, typename U>
sf::Vector3<T>& operator *= (sf::Vector3<T>& A, U B)
{
    A.x *= B;
    A.y *= B;
    A.z *= B;

    return A;
}

// \brief Overload of binary operator /=
template <typename T, typename U>
sf::Vector3<T>& operator /= (sf::Vector3<T>& A, U B)
{
    A.x /= B;
    A.y /= B;
    A.z /= B;

    return A;
}

// \brief Overload of binary operator ==
template <typename T, typename U>
bool operator == (const sf::Vector3<T>& A, const sf::Vector3<U>& B)
{
    return (A.x == B.x) && (A.y == B.y) && (A.z == B.z);
}

// \brief Overload of binary operator !=
template <typename T, typename U>
bool operator != (const sf::Vector3<T>& A, const sf::Vector3<U>& B)
{
    return (A.x != B.x) || (A.y != B.y) || (A.z != B.z);
}

#endif // SFML_VECTOR3_HPP