#pragma once


namespace AlgoShiz
{
	long double Sqrt(long double n)
	{
        long double left = 0;
        long double right = n;
        long double epsilon = 1e-14;
        long double mid;

        while (left <= right)
        {
            mid = (left + right) / 2;

            if (mid * mid > n)
                right = mid;
            else
            {
                if (n - mid * mid < epsilon)
                    return mid;

                left = mid;
            }
        }

        return -1;
	}
}