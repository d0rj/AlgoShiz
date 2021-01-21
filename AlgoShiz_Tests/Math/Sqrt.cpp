#include "CppUnitTest.h"
#include "../../AlgoShiz/Math/Sqrt.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace AlgoShizTests
{
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
