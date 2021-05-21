// Chess
// main.cpp
// Justyn Durnford
// Created on 2021-05-16
// Last modified on 2021-05-20
// Main source file

#include "Game.h"

template <typename T, std::size_t X, std::size_t Y>
void print(const Matrix<T, X, Y>& M)
{
	for (std::size_t r(0u); r < Y; ++r)
	{
		cout << "{ ";
		for (std::size_t c(0u); c < X - 1; ++c)
			cout << M(c, r) << ", ";
		cout << M(X - 1, r) << " }" << endl;
	}
}

int main()
{
	Matrix<int, 3, 3> A
	{
		{ -2, -1, 2 },
		{ 2, 1, 4 },
		{ -3, 3, -1 }
	};

	print(A);
	cout << determinant(A) << endl;

	return 0;
}