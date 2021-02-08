#include "CppUnitTest.h"
#include "../../AlgoShiz/Math/Factorial.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace AlgoShizTests
{
	TEST_CLASS(FactorialTests)
	{
	public:
		TEST_METHOD(FactorialTest)
		{
			Assert::AreEqual(1, Factorial(0));
			Assert::AreEqual(1, Factorial(1));
			Assert::AreEqual(2, Factorial(2));
			Assert::AreEqual(6, Factorial(3));
			Assert::AreEqual(24, Factorial(4));
			Assert::AreEqual(120, Factorial(5));
		}
	};
}
