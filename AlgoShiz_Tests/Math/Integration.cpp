#include "CppUnitTest.h"
#include "../../AlgoShiz/Math/Integration.hpp"

# define M_PI           3.14159265358979323846


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace AlgoShizTests
{
	TEST_CLASS(IntegrationTests)
	{
	public:
		TEST_METHOD(IntegralRectangleTest)
		{
			double result = IntegralRectangle([](double x) { return 2 * x; }, 1, 2);
			Assert::AreEqual(3.0, result, 0.005); // because of 3.0 == 3.004 in compiler

			result = IntegralRectangle([](double x) { return std::sin(x); }, 0, M_PI);
			Assert::AreEqual(2, result, 0.00001);

			result = IntegralRectangle([](double x) { return x / (x - 1); }, 2, 3);
			Assert::AreEqual(1 + std::log(2), result, 0.002);
		}


		TEST_METHOD(IntegralTrapezoidalTest)
		{
			double result = IntegralTrapezoidal([](double x) { return 2 * x; }, 1, 2);
			Assert::AreEqual(3.0, result, 0.005); // because of 3.0 == 3.004 in compiler

			result = IntegralTrapezoidal([](double x) { return std::sin(x); }, 0, M_PI);
			Assert::AreEqual(2, result, 0.00001);

			result = IntegralTrapezoidal([](double x) { return x / (x - 1); }, 2, 3);
			Assert::AreEqual(1 + std::log(2), result, 0.002);
		}


		TEST_METHOD(IntegralSimpsonsTest)
		{
			double result = IntegralSimpsons([](double x) { return 2 * x; }, 1, 2);
			Assert::AreEqual(3.0, result, 0.005); // because of 3.0 == 3.004 in compiler

			result = IntegralSimpsons([](double x) { return std::sin(x); }, 0, M_PI);
			Assert::AreEqual(2, result, 0.00001);

			result = IntegralSimpsons([](double x) { return x / (x - 1); }, 2, 3);
			Assert::AreEqual(1 + std::log(2), result, 0.002);
		}


		TEST_METHOD(trapezoidSquareTest)
		{
			double square = trapezoidSquare(2, 3, 4);
			Assert::AreEqual(10.0, square);

			square = trapezoidSquare(1, 1, 1);
			Assert::AreEqual(1.0, square);

			square = trapezoidSquare(1, 0, 1);
			Assert::AreEqual(0.5, square);
		}
	};
}
