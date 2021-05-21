////////////////////////////////////////////////////////////
// 
// This is a modified version of the SFML 2.5.1 file Rect.hpp
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

#ifndef SFML_RECT_HPP
#define SFML_RECT_HPP

#include <algorithm>
#include <SFML/System/Vector2.hpp>

namespace sf
{
    ////////////////////////////////////////////////////////////
    /// Utility template class for manipulating 2D axis      ///
    /// aligned rectangles.                                  ///
    ////////////////////////////////////////////////////////////
    template <typename T> class Rect
    {
        public:

        T left;
        T top;
        T width;
        T height;

        // \brief Default constructor.
        // Creates a Rect(0, 0, 0, 0)).
        Rect()
        {
            left = static_cast<T>(0);
            top = static_cast<T>(0);
            width = static_cast<T>(0);
            height = static_cast<T>(0);
        }

        // \brief Constructs the Rect from its coordinates and dimensions.
        // \param Left:      Left coordinate of the top-left vertex of the Rect
        // \param Top:       Top coordinate of the top-left vertex of the Rect
        // \param Width:     Width of the Rect
        // \param Height:    Height of the Rect
        Rect(T Left, T Top, T Width, T Height)
        {
            left = Left;
            top = Top;
            width = Width;
            height = Height;
        }

        // \brief Constructs the Rect from the Point2 and dimensions.
        // \param Position:  Position of the top-left vertex of the Rect
        // \param Width:     Width of the Rect
        // \param Height:    Height of the Rect
        Rect(const Point2<T>& Position, T Width, T Height)
        {
            left = Position.x;
            top = Position.y;
            width = Width;
            height = Height;
        }

        // \brief Constructs the Rect from the Vector2 and dimensions.
        // \param Position:  Position of the top-left vertex of the Rect
        // \param Width:     Width of the Rect
        // \param Height:    Height of the Rect
        Rect(const Vector2<T>& Position, T Width, T Height)
        {
            left = Position.x;
            top = Position.y;
            width = Width;
            height = Height;
        }

        // \brief Constructs the Rect from the two Point2s.
        // \param Position:   Position of the top-left vertex of the Rect
        // \param Dimensions: Dimensions of the Rect
        Rect(const Point2<T>& Position, const Point2<T>& Dimensions)
        {
            left = Position.x;
            top = Position.y;
            width = Dimensions.x;
            height = Dimensions.y;
        }

        // \brief Constructs the Rect from the two Vector2s.
        // \param Position:   Position of the top-left vertex of the Rect
        // \param Dimensions: Dimensions of the Rect
        Rect(const Vector2<T>& Position, const Vector2<T>& Dimensions)
        {
            left = Position.x;
            top = Position.y;
            width = Dimensions.x;
            height = Dimensions.y;
        }

        // \brief Constructs the Rect from another type of Rect.
        //
        // This constructor doesn't replace the copy constructor,
        // it's called only when U != T.
        // A call to this constructor will fail to compile if U
        // is not convertible to T.
        //
        // \param other: Rect to convert
        template <typename U>
        explicit Rect(const Rect<U>& other)
        {
            top = static_cast<T>(other.top);
            left = static_cast<T>(other.left);
            width = static_cast<T>(other.width);
            height = static_cast<T>(other.height);
        }

        // \brief Scales the Rect by a factor of N.
        void scale(T N)
        {
            top *= N;
            left *= N;
            width *= N;
            height *= N;
        }

        // \brief Returns the area of the Rect.
        // \return width * height
        T area() const
        {
            return width * height;
        }

        // \brief Returns the perimeter of the Rect.
        // \return 2 * (width + height)
        T perimeter() const
        {
            return static_cast<T>(2) * (width + height);
        }

        // \brief Returns the top-left vertex of the Rect.
        // \return Point2<T>(top, left)
        Point2<T> topLeft() const
        {
            return Point2<T>(top, left);
        }

        // \brief Returns the top-right vertex of the Rect.
        // \return Point2<T>(top, left + width)
        Point2<T> topRight() const
        {
            return Point2<T>(top, left + width);
        }

        // \brief Returns the bottom-left vertex of the Rect.
        // \return Point2<T>(top + height, left)
        Point2<T> bottomLeft() const
        {
            return Point2<T>(top + height, left);
        }

        // \brief Returns the bottom-right vertex of the Rect.
        // \return Point2<T>(top + height, left + width)
        Point2<T> bottomRight() const
        {
            return Point2<T>(top + height, left + width);
        }

        // \brief Checks if the point given by (X, Y) is inside the Rect's area.
        //
        // This check is non-inclusive. If the point lies on the
        // edge of the rectangle, this function will return false.
        //
        // \param X: X coordinate of the point to test
        // \param Y: Y coordinate of the point to test
        // \return True if the point is inside the Rect, False otherwise.
        bool contains(T X, T Y) const
        {
            return (X > left) && (X < left + width) && (Y > top) && (Y < top + height);
        }

        // \brief Checks if the given Point2 is inside the rectangle's area
        //
        // This check is non-inclusive. If the point lies on the
        // edge of the rectangle, this function will return false.
        //
        // \param P: Point to test
        // \return True if the point is inside the Rect, False otherwise.
        bool contains(const Point2<T>& P) const
        {
            return (P.x > left) && (P.x < left + width) && (P.y > top) && (P.y < top + height);
        }

        // \brief Checks if the given Vector2 is inside the rectangle's area
        //
        // This check is non-inclusive. If the point lies on the
        // edge of the rectangle, this function will return false.
        //
        // \param P: Point to test
        // \return True if the point is inside the Rect, False otherwise.
        bool contains(const Vector2<T>& P) const
        {
            return (P.x > left) && (P.x < left + width) && (P.y > top) && (P.y < top + height);
        }

        // \brief Checks if the point given by (X, Y) is inside the Rect's area.
        //
        // This check is inclusive. If the point lies on the
        // edge of the rectangle, this function will return true.
        //
        // \param X: X coordinate of the point to test
        // \param Y: Y coordinate of the point to test
        // \return True if the point is inside or on the Rect, False otherwise.
        bool containsInclusive(T X, T Y) const
        {
            return (X >= left) && (X <= left + width) && (Y >= top) && (Y <= top + height);
        }

        // \brief Checks if the given Point2 is inside the rectangle's area
        //
        // This check is inclusive. If the point lies on the
        // edge of the rectangle, this function will return true.
        //
        // \param P: Point to test
        // \return True if the point is inside or on the Rect, False otherwise.
        bool containsInclusive(const Point2<T>& P) const
        {
            return (P.x > left) && (P.x < left + width) && (P.y > top) && (P.y < top + height);
        }

        // \brief Checks if the given Vector2 is inside the rectangle's area
        //
        // This check is inclusive. If the point lies on the
        // edge of the rectangle, this function will return true.
        //
        // \param P: Point to test
        // \return True if the point is inside or on the Rect, False otherwise.
        bool containsInclusive(const Vector2<T>& P) const
        {
            return (P.x > left) && (P.x < left + width) && (P.y > top) && (P.y < top + height);
        }

        ////////////////////////////////////////////////////////////
        /// \brief Check the intersection between two rectangles
        ///
        /// \param rectangle Rectangle to test
        ///
        /// \return True if rectangles overlap, false otherwise
        ///
        /// \see contains
        ///
        ////////////////////////////////////////////////////////////
        bool intersects(const Rect<T>& rectangle) const
        {
            Rect<T> intersection;
            return intersects(rectangle, intersection);
        }

        ////////////////////////////////////////////////////////////
        /// \brief Check the intersection between two rectangles
        ///
        /// This overload returns the overlapped rectangle in the
        /// \a intersection parameter.
        ///
        /// \param rectangle    Rectangle to test
        /// \param intersection Rectangle to be filled with the intersection
        ///
        /// \return True if rectangles overlap, false otherwise
        ///
        /// \see contains
        ///
        ////////////////////////////////////////////////////////////
        bool intersects(const Rect<T>& rectangle, Rect<T>& intersection) const
        {
            // Rectangles with negative dimensions are allowed, so we must handle them correctly

            // Compute the min and max of the first rectangle on both axes
            T r1MinX = std::min(left, static_cast<T>(left + width));
            T r1MaxX = std::max(left, static_cast<T>(left + width));
            T r1MinY = std::min(top, static_cast<T>(top + height));
            T r1MaxY = std::max(top, static_cast<T>(top + height));

            // Compute the min and max of the second rectangle on both axes
            T r2MinX = std::min(rectangle.left, static_cast<T>(rectangle.left + rectangle.width));
            T r2MaxX = std::max(rectangle.left, static_cast<T>(rectangle.left + rectangle.width));
            T r2MinY = std::min(rectangle.top, static_cast<T>(rectangle.top + rectangle.height));
            T r2MaxY = std::max(rectangle.top, static_cast<T>(rectangle.top + rectangle.height));

            // Compute the intersection boundaries
            T interLeft = std::max(r1MinX, r2MinX);
            T interTop = std::max(r1MinY, r2MinY);
            T interRight = std::min(r1MaxX, r2MaxX);
            T interBottom = std::min(r1MaxY, r2MaxY);

            // If the intersection is valid (positive non zero area), then there is an intersection
            if ((interLeft < interRight) && (interTop < interBottom))
            {
                intersection = Rect<T>(interLeft, interTop, interRight - interLeft, interBottom - interTop);
                return true;
            }
            else
            {
                intersection = Rect<T>(0, 0, 0, 0);
                return false;
            }
        }
    };

    // Define common types
    typedef Rect<char>           CharRect;
    typedef Rect<unsigned char>  UCharRect;
    typedef Rect<short>          ShortRect;
    typedef Rect<unsigned short> UShortRect;
    typedef Rect<int>            IntRect;
    typedef Rect<unsigned int>   UIntRect;
    typedef Rect<float>          FloatRect;

    // \brief Checks for an intersection between two Rects.
    // \param A: First Rect
    // \param B: Second Rect
    // \return True if the Rects overlap, False otherwise
    template <typename T, typename U>
    bool is_intersection(const Rect<T>& A, const Rect<U>& B)
    {
        if ((A.left < B.left) && (A.left + A.width < B.left))
            return false;
        if ((A.top > B.top) && (A.top > B.top + B.height))
            return false;

        if ((B.left < A.left) && (B.left + B.width < A.left))
            return false;
        if ((B.top > A.top) && (B.top > A.top + A.width))
            return false;

        return true;
    }
}

// \brief Overload of binary operator ==
template <typename T, typename U>
bool operator == (const sf::Rect<T>& A, const sf::Rect<T>& B)
{
    return (A.left == B.left) && (A.width == B.width) && (A.top == B.top) && (A.height == B.height);
}

// \brief Overload of binary operator !=
template <typename T, typename U>
bool operator != (const sf::Rect<T>& A, const sf::Rect<T>& B)
{
    return (A.left != B.left) || (A.width != B.width) || (A.top != B.top) || (A.height != B.height);
}

#endif // SFML_RECT_HPP