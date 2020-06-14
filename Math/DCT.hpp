#pragma once
#define _USE_MATH_DEFINES

#include <cmath>
#include <vector>


/* TODO: not tested!!! */
namespace AlgoShiz
{
	/// <summary> Discrete cosine transform II for one-dimentional array. O(n^2) </summary>
	double* DCT_1d(const double* input, size_t n)
	{
		double* result = new double[n];

		double coeff = M_PI / (2*n);
		double z = 0;

		for (size_t u = 0; u < n; ++u)
		{
			z = 0;

			for (size_t x = 0; x < n; ++x)
				z += input[x] * cos(coeff * (double)u * (double)(2*x + 1));

			if (u == 0) 
				z *= 1.0 / sqrt(2.0);

			result[u] = z;
		}

		return result;
	}


	/// <summary> Discrete cosine transform II for one-dimentional array. O(n^2) </summary>
	std::vector<double> DCT_1d(const std::vector<double>* input)
	{
		std::vector<double> result;
		size_t n = input->size();
		result.reserve(n);

		double coeff = M_PI / (2*n);
		double z = 0;

		for (size_t u = 0; u < n; ++u)
		{
			z = 0;

			for (size_t x = 0; x < n; ++x)
				z += input->at(x) * cos(coeff * (double)u * (double)(2*x + 1));

			if (u == 0)
				z *= 1.0 / sqrt(2.0);

			result.push_back(z);
		}

		return result;
	}
}