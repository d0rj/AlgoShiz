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


	// TODO: test and fix
	double NewtonInterpolate(double x0, double* x, double* y, size_t n)
	{
		double newtonPolinom = y[0];
		double h = x[1] - x[0];
		int factor = 1;
		
		// create finite differenses
		double** dy = new double* [n];
		for (int i = 0; i < n; i++) 
			dy[i] = new double[n];
		// fill first 
		for (int i = 0; i < n; i++)
			dy[0][i] = y[i];
		// calculate finite differenses table
		for (int i = 1; i < n; i++)
			for (int j = 0; j < n - i; j++)
				dy[i][j] = dy[i - 1][j + 1] - dy[i - 1][j];


		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < n - i; j++)
			{
				dy[i][j] = dy[i - 1][j + 1] - dy[i - 1][j];
			}
		}

		for (size_t i = 0; i < n - 1; ++i)
		{
			for (size_t j = 0; j < i + 1; ++j)
			{
				newtonPolinom *= x0 - x[j];
			}

			newtonPolinom *= dy[0][i];
			newtonPolinom /= factor * pow(h, i);

			factor *= factor + 1;
		}

		for (int i = 0; i < n; i++) 
			delete[] dy[i];
		delete[] dy;

		return newtonPolinom;
	}
}