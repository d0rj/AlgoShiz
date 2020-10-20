#pragma once

#include <functional>


namespace AlgoShiz
{
	/// <summary> Python-like array generator for range [a, b) </summary>
	/// <param name="f"> Function that generate each element </param>
	/// <param name="a"> First number, including </param>
	/// <param name="b"> Last number, excluding </param>
	/// <returns> Returns array of T with size |b - a| </returns>
	template <typename T>
	T* ArrayWhere(std::function<T(int)> f, int a, int b)
	{
		if (a >= b)
			return nullptr;

		size_t n = std::abs(b - a);
		T* result = new T[n];
		for (size_t i = 0; i < n; ++i)
		{
			result[i] = f(a + i);
		}

		return result;
	}


	/// <summary> Python-like array generator for range [0, n) </summary>
	/// <param name="f"> Function that generate each element </param>
	/// <param name="n"> Last number, excluding </param>
	/// <returns> Returns array of T with size n </returns>
	template <typename T>
	T* ArrayWhere(std::function<T(int)> f, size_t n)
	{
		return ArrayWhere(f, 0, n);
	}
}
