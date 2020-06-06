#pragma once

#include <vector>


namespace AlgoShiz
{
	template <typename T>
	int LinearSearch(const T* arr, size_t n, const T& elem)
	{
		for (size_t i = 0; i < n; ++i)
			if (arr[i] == elem)
				return i;
		return -1;
	}


	template <typename T>
	int LinearSearch(const std::vector<T>* container, const T& elem)
	{
		for (auto iterator = container->begin(); iterator != container->end(); ++iterator)
			if (*iterator == elem)
				return iterator - container->begin();
		return -1;
	}


	template <typename T>
	int LinearSearch(const std::vector<T>& container, const T& elem)
	{
		for (auto iterator = container.begin(); iterator != container.end(); ++iterator)
			if (*iterator == elem)
				return iterator - container.begin();
		return -1;
	}
}