#pragma once

#include <vector>


namespace AlgoShiz
{
	/// <summary> O(n^2) and vector copy </summary>
	template <typename T>
	std::vector<T> BubbleSorted(const std::vector<T>* arr)
	{
		std::vector<T> result(*arr);

		for (size_t i = 0; i < result.size() - 1; ++i)
			for (size_t j = i + 1; j < result.size(); ++j)
				if (result[i] > result[j])
					std::swap(result[i], result[j]);

		return result;
	}


	/// <summary> O(n^2) </summary>
	template <typename T>
	void BubbleSort(std::vector<T>* arr)
	{
		for (size_t i = 0; i < arr->size() - 1; ++i)
			for (size_t j = i + 1; j < arr->size(); ++j)
				if (arr->at(i) > arr->at(j))
					std::swap(arr->at(i), arr->at(j));
	}
}