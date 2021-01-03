#pragma once

#include <cmath>
#include "Utils.hpp"


namespace AlgoShiz
{
	long long int GCD(long long unsigned a, long long unsigned b)
	{
		while (a > 0 && b > 0)
		{
			if (a >= b)
				a %= b;
			else
				b %= a;
		}

		return a == 0 ? b : a;
	}


	long long int LCM(long long unsigned a, long long unsigned b)
	{
		return abs((long long)(a * (b / GCD(a, b))));
	}


	float fmod(float a, float b)
	{
		return (a - b * std::floor(a/b));
	}
}
