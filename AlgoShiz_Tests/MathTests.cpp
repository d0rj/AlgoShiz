#include "pch.h"
#include "CppUnitTest.h"
#include "../AlgoShiz/Math/Division.hpp"
#include "../AlgoShiz/Math/Sqrt.hpp"


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


	TEST_CLASS(SqrtTests)
	{
	public:

		TEST_METHOD(SqrtTest)
		{
			Assert::AreEqual(32.0, Sqrt(1024));
			Assert::AreEqual(2.0, Sqrt(4));
			Assert::AreEqual(1.0, std::round(Sqrt(1)));
			Assert::AreEqual(0.0, Sqrt(0));

			Assert::AreEqual(-1.0, Sqrt(-9));
		}


		TEST_METHOD(RootTest)
		{
			Assert::AreEqual(2.0, Root(4, 2));
			Assert::AreEqual(2.0, std::round(Root(8, 3)));

			Assert::AreEqual(1.0, std::round(Root(1, 2)));
			Assert::AreEqual(1.0, std::round(Root(1, 3)));
			
			Assert::AreEqual(0.0, Root(0, 2));
			Assert::AreEqual(0.0, Root(0, 3));

			Assert::AreEqual(42.0, Root(42, 1));

			Assert::AreEqual(0.5, Root(2, -1));
			Assert::AreEqual(0.5, Root(4, -2));
		}
	};
}
