#pragma once

#include "GCD.hpp"
#include <cmath>


namespace AlgoShiz
{
	long long int LCM(long long unsigned a, long long unsigned b)
	{
		return std::abs((long long)(a * (b / GCD(a, b))));
	}
}
