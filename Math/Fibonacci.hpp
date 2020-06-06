#pragma once


namespace AlgoShiz
{
	long long unsigned Fibonacci(long long unsigned n)
	{
		if (n <= 1)
			return n;

		long long unsigned prev = 0;
		long long unsigned curr = 1;
		long long unsigned newCurrent = 0;

		for (long long unsigned i = 2; i <= n; ++i)
		{
			newCurrent = prev + curr;
			prev = curr;
			curr = newCurrent;
		}

		return curr;
	}
}