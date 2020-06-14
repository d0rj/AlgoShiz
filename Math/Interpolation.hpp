#pragma once 

#include <vector>


namespace AlgoShiz
{
	/// <summary> Returns Lagrange's polinomial interpolation </summary>
	/// <param name="x0"> Argument, where we need to calculate </param>
	/// <param name="x"> Arguments </param>
	/// <param name="y"> Function values </param>
	/// <param name="n"> Count of arguments </param>
	double LagrangeInterpolate(double x0, double* x, double* y, size_t n)
	{
		double lagrangePolinom = 0;

		for (size_t i = 0; i < n; ++i)
		{
			double basisPolinom = 1;

			for (size_t j = 0; j < n; ++j)
				if (i != j)
					basisPolinom *= (x0 - x[j]) / (x[i] - x[j]);

			lagrangePolinom += y[i] * basisPolinom;
		}

		return lagrangePolinom;
	}

	/// <summary> Returns Lagrange's polinomial interpolation </summary>
	/// <param name="x0"> Argument, where we need to calculate </param>
	/// <param name="x"> Arguments </param>
	/// <param name="y"> Function values </param>
	double LagrangeInterpolate(double x0, const std::vector<double>* x, const std::vector<double>* y)
	{
		double lagrangePolinom = 0;

		for (size_t i = 0; i < x->size(); ++i)
		{
			double basisPolinom = 1;

			for (size_t j = 0; j < x->size(); ++j)
				if (i != j)
					basisPolinom *= (x0 - x->at(j)) / (x->at(i) - x->at(j));

			lagrangePolinom += y->at(i) * basisPolinom;
		}

		return lagrangePolinom;
	}
}