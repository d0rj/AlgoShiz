#pragma once


namespace AlgoShiz
{
	double Sqrt(double n)
	{
        double left = 0;
        double right = n;
        double epsilon = 1e-14;
        double mid;

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
    /// <param name="a"> Value to root </param>
    /// <param name="n"> Root degree </param>
    double Root(double a, int n)
    {
        if (n == 0)
            return 1;

        if (n < 0)
            return 1 / Root(a, -n);

        double eps = 1e-5;
        double root = a / n;
        double rn = a;

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