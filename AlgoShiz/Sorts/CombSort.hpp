#pragma once

#include <vector>


namespace AlgoShiz
{
	/// <summary> From O(n*log(n)) to O(n^2) </summary>
	template <typename T>
	void CombSort(std::vector<T>& arr)
	{
		double fakt = 1.2473309;
		double step = arr.size() - 1;

		while (step >= 1)
		{
			for (size_t i = 0; i + step < arr.size(); ++i)
				if (arr[i] > arr[i + step])
					std::swap(arr[i], arr[i + step]);

			step /= fakt;
		}

		bool swapped = false;
		// Bubble sort
		for (size_t i = 0; i < arr.size() - 1; ++i)
		{			
			for (size_t j = i; j < arr.size() - 1; ++j)
				if (arr[j] > arr[j + 1])
				{
					std::swap(arr[j], arr[j + 1]);
					swapped = true;
				}

			if (!swapped)
				break;
		}
	}


	/// <summary> From O(n*log(n)) to O(n^2) </summary>
	template <typename T>
	void CombSort(std::vector<T>* arr)
	{
		double fakt = 1.2473309;
		double step = arr->size() - 1;

		while (step >= 1)
		{
			for (size_t i = 0; i + step < arr->size(); ++i)
				if (arr->at(i) > arr->at(i + step))
					std::swap(arr->at(i), arr->at(i + step));

			step /= fakt;
		}

		bool swapped = false;
		// Bubble sort
		for (size_t i = 0; i < arr->size() - 1; ++i)
		{
			for (size_t j = i; j < arr->size() - 1; ++j)
				if (arr->at(j) > arr->at(j + 1))
				{
					std::swap(arr->at(j), arr->at(j + 1));
					swapped = true;
				}

			if (!swapped)
				break;
		}
	}
}
