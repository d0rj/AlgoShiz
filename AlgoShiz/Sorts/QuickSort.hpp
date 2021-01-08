#pragma once

#include <vector>


namespace AlgoShiz
{
    /// <summary> O(n*log(n)) </summary>
    template<class T>
    void QuickSort(T* arr, long n)
    {
        long i = 0;
        long j = n - 1;
        T temp, p;

        p = arr[n >> 1];

        do
        {
            while (arr[i] < p) 
                ++i;
            while (arr[j] > p) 
                --j;

            if (i <= j)
                std::swap(arr[i++], arr[j--]);
        } 
        while (i <= j);

        if (j > 0) 
            QuickSort(arr, j + 1);
        if (n > i) 
            QuickSort(arr + i, n - i);
    }
}