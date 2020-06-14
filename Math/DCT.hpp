#pragma once
#define _USE_MATH_DEFINES

#include <cmath>


/* TODO: not tested!!! */
namespace AlgoShiz
{
	/// <summary> Discrete cosine transform for one-dimentional array. O(n^2) </summary>
	double* DCT_1d(const double* input, size_t n)
	{
		double* result = new double[n];

		for (size_t u = 0; u < n; ++u)
		{
			double z = 0;

			for (size_t x = 0; x < n; ++x)
				z += input[x] * cos(M_PI * (double)u * (double)(2*x + 1) / (double)(2*n));

			if (u == 0) 
				z *= 1.0 / sqrt(2.0);

			result[u] = z / 2.0;
		}
	}
}