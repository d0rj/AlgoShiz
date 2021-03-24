#pragma once

#include <algorithm>
#include <iterator>
#include <vector>
#include <functional>


template <typename T>
void GnomeSort(std::vector<T>& vec)
{
	for (size_t i = 1; i < vec.size(); )
	{
		if (vec.at(i - 1) < vec.at(i))
			++i;
		else
		{
			std::swap(vec.at(i - 1), vec.at(i));
			--i;
			if (i == 0)
				i = 1;
		}
	}
}


template <typename Iterator>
void GnomeSort(
	Iterator begin,
	Iterator end,
	std::function<bool(typename Iterator::value_type, typename Iterator::value_type)> compare
	= [](typename Iterator::value_type a, typename Iterator::value_type b) { return a < b; }
)
{
	int current = 0;
	int before_current;
	size_t step = 1;

	while (current != std::distance(begin, end))
	{
		if (current == 0 || compare(*(begin + before_current), *(begin + current)))
		{
			current += step;
			step = 1;
		}
		else
		{
			std::iter_swap(begin + before_current, begin + current);
			--current;
			++step;
		}

		before_current = current;
		--before_current;
	}
}
