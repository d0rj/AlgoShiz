#pragma once

#include <vector>


namespace AlgoShiz
{
    template <typename T>
    void merge(T* arr, size_t left, size_t middle, size_t right)
    {
        int nLeft = middle - left + 1;
        int nRight = right - middle;
        T* lArr = new T[nLeft];
        T* rArr = new T[nRight];

        int i, j, k;
        for (i = 0; i < nLeft; ++i)
            lArr[i] = arr[left + i];
        for (j = 0; j < nRight; ++j)
            rArr[j] = arr[middle + j + 1];

        i = 0; j = 0; k = left;
        while (i < nLeft && j < nRight)
        {
            if (lArr[i] <= rArr[j])
            {
                arr[k] = lArr[i];
                ++i;
            }
            else
            {
                arr[k] = rArr[j];
                ++j;
            }
            ++k;
        }

        while (i < nLeft)
        {
            arr[k] = lArr[i];
            ++i; 
            ++k;
        }

        while (j < nRight)
        {
            arr[k] = rArr[j];
            ++j; 
            ++k;
        }
    }


    template <typename T>
    void merge(std::vector<T>* arr, size_t left, size_t middle, size_t right)
    {
        int nLeft = middle - left + 1;
        int nRight = right - middle;
        std::vector<T> lArr(nLeft, 0);
        std::vector<T> rArr(nRight, 0);

        int i, j, k;
        for (i = 0; i < nLeft; ++i)
            lArr[i] = arr->at(left + i);
        for (j = 0; j < nRight; ++j)
            rArr[j] = arr->at(middle + j + 1);

        i = 0; j = 0; k = left;
        while (i < nLeft && j < nRight)
        {
            if (lArr[i] <= rArr[j])
            {
                arr->at(k) = lArr[i];
                ++i;
            }
            else
            {
                arr->at(k) = rArr[j];
                ++j;
            }
            ++k;
        }

        while (i < nLeft)
        {
            arr->at(k) = lArr[i];
            ++i;
            ++k;
        }

        while (j < nRight)
        {
            arr->at(k) = rArr[j];
            ++j;
            ++k;
        }
    }


    /// <summary> O(n*log(n)) </summary>
    template <typename T>
    void MergeSort(T* arr, size_t left, size_t right)
    {
        if (left < right)
        {
            size_t middle = left + (right - left) / 2;

            MergeSort(arr, left, middle);
            MergeSort(arr, middle + 1, right);

            merge(arr, left, middle, right);
        }
    }


    /// <summary> O(n*log(n)) </summary>
    template <typename T>
    void MergeSort(T* arr, size_t n)
    {
        MergeSort(arr, 0, n - 1);
    }


    /// <summary> O(n*log(n)) </summary>
    template <typename T>
    void MergeSort(std::vector<T>* arr, size_t left, size_t right)
    {
        if (left < right)
        {
            size_t middle = left + (right - left) / 2;

            MergeSort(arr, left, middle);
            MergeSort(arr, middle + 1, right);

            merge(arr, left, middle, right);
        }
    }


    /// <summary> O(n*log(n)) </summary>
    template <typename T>
    void MergeSort(std::vector<T>* arr)
    {
        MergeSort(arr, 0, arr->size() - 1);
    }
}