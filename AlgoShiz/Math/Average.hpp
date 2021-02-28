#pragma once

#include <cmath>


namespace AlgoShiz
{
	template<std::size_t n>
	double* MovingAverage(double (&f)[n], size_t window)
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
