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
			double input[] = { 1, 2, 3, 4 };
			size_t size = 4;

			double expect[] = { 3.0 / 2, 5.0 / 2, 7.0 / 2 };
			double* output = MovingAverage(input, 2);
			for (size_t i = 0; i < 3; ++i)
				Assert::AreEqual(expect[i], output[i]);

			double input2[] = { 1, 2, 3, 4 };
			double expect2[] = { 2, 3 };
			output = MovingAverage(input2, 3);
			for (size_t i = 0; i < 2; ++i)
				Assert::AreEqual(expect2[i], output[i]);

			double input3[] = { 1, 2, 3, 4 };
			double expect3[] = { 5.0 / 2 };
			output = MovingAverage(input3, 4);
			for (size_t i = 0; i < 1; ++i)
				Assert::AreEqual(expect3[i], output[i]);

			double input4[] = { 0, 0, 0, 0 };
			double expect4[] = { 0, 0 };
			output = MovingAverage(input4, 3);
			for (size_t i = 0; i < 1; ++i)
				Assert::AreEqual(expect4[i], output[i]);
		}
	};
}
