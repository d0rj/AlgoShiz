#pragma once

#include <vector>
#include "../Arrays/Utils.hpp"
#include "Utils.hpp"


namespace Algoshiz
{
	/// <summary> Measures similarity between finite sample sets </summary>
	/// <param name="a"> Total number of first set attributes  </param>
	/// <param name="b"> Total number of second set attributes </param>
	/// <param name="c"> Total number of common attributes </param>
	double JaccardIndex(size_t a, size_t b, size_t c)
	{
		return c / (a + b - c);
	}


	template <typename T>
	double JaccardIndex(const std::vector<T> first, const std::vector<T> second)
	{
		size_t a = first.size();
		size_t b = second.size();
		int c = 0;
		
		std::vector<T>* minArr = (a >= b) ? &b : &a;
		std::vector<T>* maxArr = (a >= b) ? &a : &b;
		for (size_t i = 0; i < min(a, b); ++i)
			if (ElementIn(minArr->at(i), *maxArr))
				++c;

		return JaccardIndex(a, b, c);
	}
}
