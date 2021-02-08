#include "CppUnitTest.h"
#include "../../AlgoShiz/Math/Power.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace Tests_Math
{
	TEST_CLASS(PowerTests)
	{
	public:
		TEST_METHOD(FastPowerTest)
		{
			Assert::AreEqual(8.0, FastPower(2, 3));
			Assert::AreEqual(9.0, FastPower(3, 2));

			Assert::AreEqual(1.0, FastPower(3, 0));

			Assert::AreEqual(0.125, FastPower(2, -3));
		}


		TEST_METHOD(ModeExpTest)
		{
			Assert::AreEqual(445, ModeExp(4, 13, 497));
			Assert::AreEqual(342, ModeExp(595, 703, 991));
			Assert::AreEqual(3, ModeExp(175, 235, 257));
		}
	};
}
