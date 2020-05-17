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
}