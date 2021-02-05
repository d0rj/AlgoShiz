#include "CppUnitTest.h"
#include "../../AlgoShiz/Math/Fibonacci.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace AlgoShizTests
{
	TEST_CLASS(FibonacciTests)
	{
	public:
		TEST_METHOD(FibonacciTest)
		{
			size_t n = 11;
			int* right = new int[n] { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55 };

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(right[i], Fibonacci(i));
		}


		TEST_METHOD(FibonacciTest_Negative)
		{
			size_t n = 11;
			int* right = new int[n] { 0, 1, -1, 2, -3, 5, -8, 13, -21, 34, -55 };

			for (int i = 0; i < n; ++i)
				Assert::AreEqual(right[i], Fibonacci(-i));
		}
	};
}
