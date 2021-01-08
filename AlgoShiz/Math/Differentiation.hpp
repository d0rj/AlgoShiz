#pragma once

#include <functional>


namespace AlgoShiz
{
	const double DefaultDelta = 1e-10;


	double BilateralDiffer(std::function<double(double)> f, double x0, double delta = DefaultDelta)
	{
		return (f(x0 + delta) - f(x0 - delta)) / 2.0 * delta;
	}


	double BilateralDiffer2(std::function<double(double)> f, double x0, double delta = DefaultDelta)
	{
		return (f(x0 + delta) - 2.0 * f(x0) + f(x0 - delta)) / (4.0 * delta * delta);
	}
}