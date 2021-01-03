#pragma once

#include <cmath>


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
		return std::abs((long long)(a * (b / GCD(a, b))));
	}
}
