#pragma once


namespace AlgoShiz
{
	long long int GCD(long long unsigned a, long long unsigned b)
	{
		if (a == 0)
			return b;
		else if (b == 0)
			return a;
		else if (a >= b)
			return GCD(a % b, b);
		else 
			return GCD(a, b % a);
	}
}