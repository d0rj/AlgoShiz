#pragma once

#include <vector>
#include <iostream>


namespace AlgoShiz
{
	/// <summary> O(n^2) </summary>
	template <typename T>
	void InsertionSort(std::vector<T>* arr)
	{
		for (size_t sortedSize = 1; sortedSize < arr->size(); ++sortedSize)
			if (arr->at(sortedSize) < arr->at(sortedSize - 1))
			{
				T tmp = arr->at(sortedSize);
				size_t i = sortedSize;

				for (; i != 0 && tmp < arr->at(i - 1); --i)
					arr->at(i) = arr->at(i - 1);

				arr->at(i) = tmp;
			}
	}


	/// <summary> O(n^2) </summary>
	template <typename T>
	std::vector<T> InsertionSorted(const std::vector<T>* arr)
	{
		std::vector<T> result(*arr);

		for (size_t sortedSize = 1; sortedSize < result.size(); ++sortedSize)
			if (result[sortedSize] < result[sortedSize - 1])
			{
				T tmp = result[sortedSize];
				size_t i = sortedSize;

				for (; i != 0 && tmp < result[i - 1]; --i)
					result[i] = result[i - 1];

				result[i] = tmp;
			}

		return result;
	}
}