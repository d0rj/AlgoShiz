#pragma once

#include <functional>


namespace AlgoShiz 
{
	const size_t DefaultPanelCount = 1000;


	double trapezoidSquare(double base1, double base2, double height)
	{
		return (base1 + base2) * height / 2.0f;
	}


	double IntegralTrapezoidal(std::function<double(double)> f, double a, double b, double step = -1)
	{
		if (step <= 0)
			step = (b - a) / DefaultPanelCount;

		double result = 0;
		for (double i = a; i < b; i += step)
			result += trapezoidSquare(f(i), f(i + step), step);

		return result;
	}


	double paraboloidSquare(std::function<double(double)> f, double a, double b)
	{
		double m = (a + b) / 2.0f;
		return (b - a) / 6.0f * (f(a) + 4 * f(m) + f(b));
	}


	double IntegralSimpsons(std::function<double(double)> f, double a, double b, size_t fragmentation = 0)
	{
		if (fragmentation == 0)
			fragmentation = DefaultPanelCount;

		double h = (b - a) / fragmentation;
		double x_i = 0;
		double fx_i = 0;

		double result = 0;
		for (size_t i = 0; i <= fragmentation; ++i)
		{
			x_i = a + i * h;
			fx_i = f(x_i);

			if (i == 0 || i == fragmentation)
				result += fx_i;
			else if (i % 2 != 0)
				result += 4 * fx_i;
			else
				result += 2 * fx_i;
		}

		result *= (h / 3);

		return result;
	}


	double IntegralRectangle(std::function<double(double)> f, double a, double b, size_t factorization = 0)
	{
		if (factorization == 0)
			factorization = DefaultPanelCount;

		double step = (b - a) / factorization;

		double result = 0;
		for (double i = a; i < b; i += step)
			result += f((2 * i + step) / 2.0f);

		result *= step;

		return result;
	}
}