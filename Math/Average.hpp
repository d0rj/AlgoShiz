#pragma once

#include <cmath>


namespace AlgoShiz
{
	double* MovingAverage(double* f, size_t n, size_t window)
	{
		double* result = new double[n];
        int z, k1, k2, hw;
        double tmp;

        if (fmod(window, 2) == 0) 
            window++;

        hw = (window - 1) / 2;
        result[0] = f[0];

        for (int i = 1; i < n; ++i)
        {
            tmp = 0;
            if (i < hw)
            {
                k1 = 0;
                k2 = 2 * i;
                z = k2 + 1;
            }
            else if ((i + hw) > (n - 1))
            {
                k1 = i - n + i + 1;
                k2 = n - 1;
                z = k2 - k1 + 1;
            }
            else
            {
                k1 = i - hw;
                k2 = i + hw;
                z = window;
            }

            for (int j = k1; j <= k2; j++)
                tmp = tmp + f[j];

            result[i] = tmp / z;
        }

        return result;
	}
}
