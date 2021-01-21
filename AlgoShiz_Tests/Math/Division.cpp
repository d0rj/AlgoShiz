#include "CppUnitTest.h"
#include "../../AlgoShiz/Math/Division.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace AlgoShizTests
{
	TEST_CLASS(DivisionTests)
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


		TEST_METHOD(LCMtest)
		{
			Assert::AreEqual(6, (int)LCM(2, 3));
			Assert::AreEqual(0, (int)LCM(0, 1)); // because of illegal argument 0
			Assert::AreEqual(25, (int)LCM(25, 25));
		}


		TEST_METHOD(fmodTest)
		{
			Assert::AreEqual(1.0f, AlgoShiz::fmod(10, 3));
			Assert::AreEqual(3.0f, AlgoShiz::fmod(3, 10));
			Assert::AreEqual(0.0f, AlgoShiz::fmod(0, 5));
		}
	};
}
