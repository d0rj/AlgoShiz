#pragma once

#include <cmath>


namespace AlgoShiz
{
	double* MovingAverage(double* f, size_t n, size_t window)
	{
		double* result = new double[n - window + 1];
        
		for (size_t i = 0; i < n - window + 1; ++i)
		{
			double sum = 0;
			for (size_t j = i; j < i + window; ++j)
				sum += f[j];

			result[i] = sum / window;
		}

		return result;
	}
}
