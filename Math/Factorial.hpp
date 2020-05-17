#pragma once

#include <cstdint>


namespace AlgoShiz
{
	int64_t Factorial(int64_t n)
	{
		int64_t result = 1;

		while (n)
			result *= n--;

		return result;
	}
}