#pragma once


namespace AlgoShiz
{
	/// <summary> a^b </summary>
	long double FastPower(int64_t a, int64_t b)
	{
		if (!b)
			return 1;

		if (b < 0)
			return 1 / FastPower(a, -b);

		double result = 1;
		while (b)
		{
			if (b & 1)
				result *= a;
			a *= a;
			b >>= 1;
		}

		return result;
	}


	/// <summary> Returns (x^y) % n, but fast </summary>
	/// <param name="x"> x </param>
	/// <param name="y"> exponent </param>
	/// <param name="n"> mod </param>
	long int ModeExp(int x, int y, int n)
	{
		if (!y)
			return 1;
		
		int z = ModeExp(x, y >> 1, n);

		if (y % 2 == 0)
			return (z * z) % n;
		else
			return (x * z * z) % n;
	}
}