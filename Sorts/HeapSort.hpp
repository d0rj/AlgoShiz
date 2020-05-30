#pragma once


#include <vector>


namespace AlgoShiz
{
    /// <summary> O(log(n)) </summary>
    template <typename T>
    void heapify(T arr[], size_t n, size_t i)
    {
        size_t largest = i;
        size_t left = 2 * i + 1;
        size_t right = 2 * i + 2;

        if (left < n && arr[left] > arr[largest])
            largest = left;

        if (right < n && arr[right] > arr[largest])
            largest = right;

        if (largest != i)
        {
            std::swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    /// <summary> O(n*log(n)) </summary>
    template <typename T>
    void HeapSort(T arr[], size_t n)
    {
        for (int i = n / 2 - 1; i >= 0; --i)
            heapify(arr, n, i);

        for (int i = n - 1; i >= 0; --i)
        {
            std::swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
}
