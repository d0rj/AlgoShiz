#pragma once

#include <vector>


namespace AlgoShiz
{
	/// <summary> O(n^2) and vector copy </summary>
	template <typename T>
	std::vector<T> SelectionSorted(const std::vector<T>* arr)
	{
		std::vector<T> result(*arr);
		size_t minIndex = 0;
		T minElem;

		for (size_t i = 0; i < result.size(); ++i)
		{
			minIndex = i;
			minElem = result[i];

			for (size_t j = i + 1; j < result.size(); ++j) 
				if (result[j] < minElem)
				{
					minIndex = j;
					minElem = result[j];
				}

			result[minIndex] = result[i];
			result[i] = minElem;
		}

		return result;
	}


	/// <summary> O(n^2) </summary>
	template <typename T>
	void SelectionSort(std::vector<T>* arr)
	{
		size_t minIndex = 0;
		T minElem;

		for (size_t i = 0; i < arr->size(); ++i)
		{
			minIndex = i;
			minElem = arr->at(i);

			for (size_t j = i + 1; j < arr->size(); ++j)
				if (arr->at(j) < minElem)
				{
					minIndex = j;
					minElem = arr->at(j);
				}

			arr->at(minIndex) = arr->at(i);
			arr->at(i) = minElem;
		}
	}
}