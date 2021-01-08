#pragma once

#include <vector>


namespace AlgoShiz
{
	template <typename T>
	void Flip(std::vector<T>* arr)
	{
		for (size_t i = 0; i < arr->size() / 2; ++i)
			std::swap(arr->at(i), arr->at(arr->size() - i - 1));
	}


	template <typename T>
	std::vector<T> Fliped(const std::vector<T>* arr)
	{
		std::vector<T> result(*arr);
			
		for (size_t i = 0; i < result.size() / 2; ++i)
			std::swap(result[i], result[result.size() - i - 1]);

		return result;
	}


	template <typename T>
	void Flip(T* arr, size_t n)
	{
		for (size_t i = 0; i < n / 2; ++i)
			std::swap(arr[i], arr[n - i - 1]);
	}


	template <typename T>
	T* Fliped(const T* arr, size_t n)
	{
		T* result = new T[sizeof(T) * n];
		std::copy(arr, arr + n, result);

		for (size_t i = 0; i < n / 2; ++i)
			std::swap(result[i], result[n - i - 1]);

		return result;
	}


	template <typename T>
	bool ElementIn(const T elem, const std::vector<T> arr)
	{
		for (size_t i = 0; i < arr.size(); ++i)
			if (arr.at(i) == elem)
				return true;
		return false;
	}
}