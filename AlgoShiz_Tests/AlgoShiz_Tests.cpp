#include "pch.h"
#include "CppUnitTest.h"
#include "../AlgoShiz/Math/Division.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace AlgoShizTests
{
	TEST_CLASS(MathTests)
	{
	public:
		
		TEST_METHOD(GCDtest)
		{
			Assert::AreEqual(25, (int)GCD(125, 25));
			Assert::AreEqual(1, (int)GCD(7, 13));
			Assert::AreEqual(17, (int)GCD(17, 17));

			Assert::AreEqual(42, (int)GCD(42, 0));
			Assert::AreEqual(42, (int)GCD(0, 42));
		}
	};
}
