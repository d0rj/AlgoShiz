#include "CppUnitTest.h"
#include "../../AlgoShiz/Math/Utils.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace AlgoShizTests
{
	TEST_CLASS(UtilsTests)
	{
	public:

		TEST_METHOD(absTest)
		{
			Assert::AreEqual(2, AlgoShiz::abs(-2));
			Assert::AreEqual(2, AlgoShiz::abs(2));
			Assert::AreEqual(0, AlgoShiz::abs(0));

			Assert::AreEqual(2.0, AlgoShiz::abs(-2.0));
			Assert::AreEqual(2.0f, AlgoShiz::abs(-2.0f));
		}


		TEST_METHOD(minTest)
		{
			Assert::AreEqual(1, AlgoShiz::min(1, 2));
			Assert::AreEqual(1, AlgoShiz::min(2, 1));

			Assert::AreEqual(-2, AlgoShiz::min(-2, -1));
			Assert::AreEqual(-2, AlgoShiz::min(-1, -2));

			Assert::AreEqual(1, AlgoShiz::min(1, 1));
		}


		TEST_METHOD(maxTest)
		{
			Assert::AreEqual(2, AlgoShiz::max(1, 2));
			Assert::AreEqual(2, AlgoShiz::max(2, 1));

			Assert::AreEqual(-1, AlgoShiz::max(-2, -1));
			Assert::AreEqual(-1, AlgoShiz::max(-1, -2));

			Assert::AreEqual(1, AlgoShiz::max(1, 1));
		}
	};
}
