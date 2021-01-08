#pragma once

#include <cmath>
#include <string.h>


namespace AlgoShiz
{
	/// <summary> O(n) </summary>
	void RadixSort(int a[], int n)
	{
		int count[10];
		int* output = new int[n];

		memset(output, 0, sizeof(output));
		memset(count, 0, sizeof(count));

		int max = 0;
		for (int i = 0; i < n; ++i)
			if (a[i] > max)
				max = a[i];

		int maxdigits = 0;
		while (max)
		{
			++maxdigits;
			max /= 10;
		}

		for (size_t j = 0; j < maxdigits; ++j)
		{
			for (size_t i = 0; i < n; ++i)
			{
				int t = (int)std::pow(10, j);
				++count[(a[i] % (10 * t)) / t];
			}

			int k = 0;
			for (int p = 0; p < 10; ++p)
			{
				for (int i = 0; i < n; ++i)
				{
					int t = (int)std::pow(10, j);

					if ((a[i] % (10 * t)) / t == p)
						output[k++] = a[i];
				}
			}

			memset(count, 0, sizeof(count));

			for (int i = 0; i < n; ++i)
				a[i] = output[i];
		}
	}
}
