#pragma once


namespace AlgoShiz
{
	int Factorial(int n)
	{
		int result = 1;

		while (n)
			result *= n--;

		return result;
	}
}