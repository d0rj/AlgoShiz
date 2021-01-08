#pragma once

#include <vector>
#include "Sqrt.hpp"


namespace AlgoShiz
{
	/// <summary> Get all prime multipliers of number </summary>
	std::vector<int> Factorize(int n)
	{
		std::vector<int> result;
		int currentN = n;

		if (currentN < 0)
		{
			result.push_back(-1);
			currentN *= -1;
		}

		int probe = 2;

		while (currentN != 1)
			if (currentN % probe != 0)
			{
				++probe;
			}
			else
			{
				currentN /= probe;
				result.push_back(probe);
			}

		return result;
	}


	bool IsPrime(int n)
	{
		if (n < 0)
			return false;

		for (int i = 2; i <= Sqrt(n); ++i)
			if (n % i == 0)
				return false;

		return true;
	}


	std::vector<int> GetDividers(int n)
	{
		std::vector<int> result;

		if (n < 0)
		{
			result.push_back(-1);
			n *= -1;
		}

		for (int probe = 2; probe <= Sqrt(n); ++probe)
			if (n % probe == 0)
			{
				result.push_back(probe);

				if (probe != n / probe)
					result.push_back(n / probe);
			}

		return result;
	}
}