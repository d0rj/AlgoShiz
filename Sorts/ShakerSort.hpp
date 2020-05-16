#pragma once

#include <vector>


namespace AlgoShiz
{
	/// <summary> O(n^2) </summary>
	template <typename T>
	void ShakerSort(T* arr, size_t size)
	{
		for (size_t i = 0; i < size / 2; ++i)
		{
			bool swapped = false;

			for (size_t j = i; j < size - i - 1; ++j)
				if (arr[j] > arr[j + 1])
				{
					std::swap(arr[j], arr[j + 1]);
					swapped = true;
				}

			for (size_t j = size - 2 - i; j > i; --j)
				if (arr[j] < arr[j - 1])
				{
					std::swap(arr[j], arr[j - 1]);
					swapped = true;
				}

			if (!swapped) 
				break;
		}
	}


	/// <summary> O(n^2) </summary>
	template <typename T>
	T* ShakerSorted(const T* arr, size_t size)
	{
		T* result = new T[size];
		std::copy(arr, arr + size, result);

		ShakerSort(result, size);

		return result;
	}

	
	/// <summary> O(n^2) </summary>
	template <typename T>
	void ShakerSort(std::vector<T>* arr)
	{
		for (size_t i = 0; i < arr->size() / 2; ++i)
		{
			bool swapped = false;

			for (size_t j = i; j < arr->size() - i - 1; ++j)
				if (arr->at(j) > arr->at(j + 1))
				{
					std::swap(arr->at(j), arr->at(j + 1));
					swapped = true;
				}

			for (size_t j = arr->size() - 2 - i; j > i; --j)
				if (arr->at(j) < arr->at(j - 1))
				{
					std::swap(arr->at(j), arr->at(j - 1));
					swapped = true;
				}

			if (!swapped)
				break;
		}
	}


	/// <summary> O(n^2) </summary>
	template <typename T>
	std::vector<T>* ShakerSorted(const std::vector<T>* arr)
	{
		std::vector<T>* result = new std::vector<T>(arr->size());
		std::copy(arr->begin(), arr->end(), result->begin());

		ShakerSort(result);

		return result;
	}
}
