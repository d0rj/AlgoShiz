#pragma once

#include <vector>


namespace AlgoShiz
{
	/// <summary> Gauss method of SLAE solution </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="a"></param>
	/// <param name="b"></param>
	/// <returns></returns>
	template <typename T>
	std::vector<T>* GaussMethod(const std::vector<std::vector<T>>& a, const std::vector<T>& b)
	{
		size_t N = a.size(); // count of vectors
		size_t M = a[0].size(); // length of vector
		std::vector<T>* X = new std::vector<T>();
		X->resize(M);

		std::vector<std::vector<T>> A;
		std::copy(a.begin(), a.end(), A.begin());
		std::vector<T> B;
		std::copy(b.begin(), b.end(), B.begin());

		for (size_t i = 0; i < N - 1; ++i)
			for (size_t j = i + 1; j < N; ++j) // For all next vectors
			{
				double coeff = A[j][i] / A[i][i];

				for (size_t k = 0; k < M; ++k) // For all elements in vector
					A[j][k] -= A[i][k] * coeff;

				B[j] -= B[i] * coeff;
			}

		for (size_t k = M; k > 0; --k)
		{
			double sum = 0;
			for (size_t j = k + 1; j < M; ++j)
				sum += A[k][j] * X->at(j);

			(*X)[k] = (B[k] - sum) / A[k][k];
		}

		return X;
	}


	template <typename T, size_t n>
	double* GaussMethod(T A[][n], T B[])
	{
		double* X = new double[n];

		for (size_t i = 0; i < n - 1; ++i)
			for (size_t j = i + 1; j < n; ++j) // For all next vectors
			{
				double coeff = A[j][i] / A[i][i];

				for (size_t k = 0; k < n; ++k) // For all elements in vector
					A[j][k] -= A[i][k] * coeff;

				B[j] -= B[i] * coeff;
			}

		for (size_t k = n; k > 0; --k)
		{
			double sum = 0;
			for (size_t j = k + 1; j < n; ++j)
				sum += A[k][j] * X[j];

			X[k] = (B[k] - sum) / A[k][k];
		}

		return X;
	}
}