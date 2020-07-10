#pragma once

#include <vector>
#include <cmath>


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
}