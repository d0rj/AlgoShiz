#pragma once

#include <vector>


namespace AlgoShiz
{
	template <typename T>
	int BinarySearch(const T* arr, size_t n, const T& elem)
	{
		size_t left = 0;
		size_t right = n - 1;
		size_t middle;

		while (left < right)
		{
			middle = (left + right) / 2;

			if (arr[middle] < elem)
				left = middle + 1;
			else if (arr[middle] > elem)
				right = middle - 1;
			else 
				return middle;
		}

		if (arr[left] == elem)
			return left;
		else 
			return -1;
	}


	template <typename T>
	int BinarySearch(const std::vector<T>* arr, const T& elem)
	{
		size_t left = 0;
		size_t right = arr->size() - 1;
		size_t middle;

		while (left < right)
		{
			middle = (left + right) / 2;

			if (arr->at(middle) < elem)
				left = middle + 1;
			else if (arr->at(middle) > elem)
				right = middle - 1;
			else
				return middle;
		}

		if (arr->at(left) == elem)
			return left;
		else
			return -1;
	}


	template <typename T>
	int BinarySearch(const std::vector<T>& arr, const T& elem)
	{
		size_t left = 0;
		size_t right = arr.size() - 1;
		size_t middle;

		while (left < right)
		{
			middle = (left + right) / 2;

			if (arr[middle] < elem)
				left = middle + 1;
			else if (arr[middle] > elem)
				right = middle - 1;
			else
				return middle;
		}

		if (arr[left] == elem)
			return left;
		else
			return -1;
	}
}