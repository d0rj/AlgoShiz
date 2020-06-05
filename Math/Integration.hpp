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
}