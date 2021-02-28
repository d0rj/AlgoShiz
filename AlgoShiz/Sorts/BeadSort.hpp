#pragma once

#include <vector>
#ifdef ALWAYS_LOW2HIGH
#include "../Arrays/Utils.hpp"
#endif


namespace AlgoShiz
{
    void distribute(size_t dist, std::vector<int>& arr)
    {
        if (dist > arr.size())
            arr.resize(dist);

        for (int i = 0; i < dist; ++i)
            ++arr[i];
    }


    /// <summary> Complexity - O(S), where S = sum(elements); memory - O(n^2). </summary>
    /// <remarks> Returns sorted vector high to low. </remarks>
    std::vector<int> BeadSorted(const std::vector<int>* arr)
    {
        std::vector<int> list, list2, fifth(*arr);

        for (size_t i = 0; i < fifth.size(); ++i)
            distribute(fifth[i], list);

        for (size_t i = 0; i < list.size(); ++i)
            distribute(list[i], list2);
#ifdef ALWAYS_LOW2HIGH
        Flip(&list2);
#endif
        return list2;
    }


    /// <summary> Complexity - O(S), where S = sum(elements); memory - O(n^2). </summary>
    /// <remarks> Returns sorted vector high to low. Use <c>ALWAYS_LOW2HIGH</c> to fix. </remarks>
    template <std::size_t n>
    std::vector<int> BeadSorted(const int (&myints)[n])
    {
        std::vector<int> list, list2, fifth(myints, myints + n);

        for (size_t i = 0; i < fifth.size(); ++i)
            distribute(fifth[i], list);

        for (size_t i = 0; i < list.size(); ++i)
            distribute(list[i], list2);
#ifdef ALWAYS_LOW2HIGH
        Flip(&list2);
#endif
        return list2;
    }
}