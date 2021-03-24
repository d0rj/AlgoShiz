#pragma once

#include <vector>
#include <functional>


template <typename T>
std::vector<T> merge(
	std::vector<T>& a,
	std::vector<T>& b,
	const std::function<bool(T, T)> compare = [](T a, T b) { return a < b; }
)
{
	std::vector<T> result;

	while (a.size() > 0 && b.size() > 0)
	{
		if (compare(a[0], b[0]))
		{
			result.push_back(a[0]);
			a.erase(a.begin());
		}
		else
		{
			result.push_back(b[0]);
			b.erase(b.begin());
		}
	}

	result.insert(result.end(), a.begin(), a.end());
	result.insert(result.end(), b.begin(), b.end());

	return result;
}


template <typename Iterator>
std::vector<typename Iterator::value_type> strandSort(
	Iterator begin,
	Iterator end,
	std::function<bool(typename Iterator::value_type, typename Iterator::value_type)> compare =
	[](Iterator::value_type a, Iterator::value_type b) { return a < b; }
)
{
	if (std::distance(begin, end) <= 1)
		return std::vector<typename Iterator::value_type>(begin, end);

	auto vec = std::vector<typename Iterator::value_type>(begin, end);
	std::vector<typename Iterator::value_type> result;
	std::vector<typename Iterator::value_type> sorted;

	while (!vec.empty())
	{
		sorted.push_back(vec.front());
		vec.erase(vec.begin());
		for (auto it = vec.begin(); it != vec.end(); )
		{
			if (compare(sorted.back(), *it))
			{
				sorted.push_back(*it);
				it = vec.erase(it);
			}
			else
				++it;
		}

		result = merge(result, sorted, compare);
		sorted = {};
	}

	return result;
}


/// <summary> Strand sort for vectors with any comparable elements </summary>
/// <typeparam name="T"> A type that has an implemented operator less for its elements </typeparam>
/// <param name="vec"> Pointer to target vector </param>
template <typename T>
void StrandSort(
	std::vector<T>* vec,
	std::function<bool(T, T)> compare = [](T a, T b) { return a < b; }
)
{
	(*vec) = strandSort(vec->begin(), vec->end(), compare);
}


/// <summary> Strand sort for vectors with any comparable elements </summary>
/// <typeparam name="T"> A type that has an implemented operator less for its elements </typeparam>
/// <param name="vec"> Pointer to target vector </param>
template <typename T>
void StrandSort(
	std::vector<T>& vec,
	std::function<bool(T, T)> compare = [](T a, T b) { return a < b; }
)
{
	vec = strandSort(vec.begin(), vec.end(), compare);
}


/// <summary> Strand sort by iterators </summary>
/// <typeparam name="Iterator"> Iterator type </typeparam>
/// <param name="begin"> Container's start </param>
/// <param name="end"> Container's end </param>
/// <param name="compare"> Two-place element comparison predicate (default is less than operator) </param>
template <typename Iterator>
void StrandSort(
	Iterator begin,
	Iterator end,
	std::function<bool(typename Iterator::value_type, typename Iterator::value_type)> compare =
	[](typename Iterator::value_type a, typename Iterator::value_type b) { return a < b; }
)
{
	auto result = strandSort(begin, end, compare);
	std::copy(result.begin(), result.end(), begin);
}
