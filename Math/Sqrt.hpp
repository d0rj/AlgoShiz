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


    /// <summary> n-th root of a </summary>
    /// <param name="a"> Value eto root </param>
    /// <param name="n"> Root degree </param>
    long double Root(long double a, int n)
    {
        if (n == 0)
            return 1;

        if (n < 0)
            return Root(a, -n);

        long double eps = 1e-5;
        long double root = a / n;
        long double rn = a;

        while (abs(root - rn) >= eps)
        {
            rn = a;

            for (size_t i = 1; i < n; ++i)
                rn = rn / root;

            root = 0.5 * (rn + root);
        }

        return root;
    }
}