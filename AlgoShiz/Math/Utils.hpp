#pragma once


namespace AlgoShiz
{
	/// <summary> Analog of std::abs </summary>
	template <typename T>
	T abs(T arg)
	{
		return arg <= 0 ? -arg : arg;
	}


	template <typename T>
	T min(T a, T b)
	{
		return a < b ? a : b;
	}


	template <typename T>
	T max(T a, T b)
	{
		return a > b ? a : b;
	}
}
