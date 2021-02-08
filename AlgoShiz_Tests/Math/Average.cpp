#include "CppUnitTest.h"
#include "../../AlgoShiz/Math/Average.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace Tests_Math
{
	TEST_CLASS(AverageTests)
	{
	public:

		TEST_METHOD(MovingAverageTest)
		{
			double* input = new double[] { 1, 2, 3, 4 };
			size_t size = 4;

			double* expect = new double[] { 3.0 / 2, 5.0 / 2, 7.0 / 2 };
			double* output = MovingAverage(input, size, 2);
			for (size_t i = 0; i < 3; ++i)
				Assert::AreEqual(expect[i], output[i]);

			input = new double[] { 1, 2, 3, 4 };
			expect = new double[] { 2, 3 };
			output = MovingAverage(input, size, 3);
			for (size_t i = 0; i < 2; ++i)
				Assert::AreEqual(expect[i], output[i]);

			input = new double[] { 1, 2, 3, 4 };
			expect = new double[] { 5.0 / 2 };
			output = MovingAverage(input, size, 4);
			for (size_t i = 0; i < 1; ++i)
				Assert::AreEqual(expect[i], output[i]);

			input = new double[] { 0, 0, 0, 0 };
			expect = new double[] { 0, 0 };
			output = MovingAverage(input, size, 3);
			for (size_t i = 0; i < 1; ++i)
				Assert::AreEqual(expect[i], output[i]);
		}
	};
}
