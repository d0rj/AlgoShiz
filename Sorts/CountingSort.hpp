#pragma once 


namespace AlgoShiz
{
    void CountingSort(int arr[], int size)
    {
        int output[10];
        int count[10];
        int max = arr[0];

        for (int i = 1; i < size; i++)
            if (arr[i] > max)
                max = arr[i];

        for (int i = 0; i <= max; ++i)
            count[i] = 0;

        for (int i = 0; i < size; i++)
            ++count[arr[i]];

        for (int i = 1; i <= max; i++)
            count[i] += count[i - 1];

        for (int i = size - 1; i >= 0; i--)
        {
            output[count[arr[i]] - 1] = arr[i];
            --count[arr[i]];
        }

        for (int i = 0; i < size; i++)
            arr[i] = output[i];
    }
}
