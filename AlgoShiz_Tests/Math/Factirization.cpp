#include "CppUnitTest.h"
#include "../../AlgoShiz/Math/Factorization.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace AlgoShizTests
{
	TEST_CLASS(FactorizationTests)
	{
	public:

		TEST_METHOD(IsPrimeTest)
		{
			Assert::IsTrue(IsPrime(1));
			Assert::IsTrue(IsPrime(2));
			Assert::IsTrue(IsPrime(3));
			Assert::IsTrue(IsPrime(5));
			Assert::IsTrue(IsPrime(13));

			Assert::IsFalse(IsPrime(6));
			Assert::IsFalse(IsPrime(42));

			Assert::IsFalse(IsPrime(-1));
		}


		TEST_METHOD(FactorizeTest)
		{
			std::vector<int> right = { 2, 3, 5, 5 };
			int num = 2 * 3 * 5 * 5;

			Assert::IsTrue(right == Factorize(num));

			right = { 2, 2, 2, 2 };
			num = 2 * 2 * 2 * 2;

			Assert::IsTrue(right == Factorize(num));

			right = {  };
			num = 1;

			Assert::IsTrue(right == Factorize(num));

			right = { 73 };
			num = 73;

			Assert::IsTrue(right == Factorize(num));

			right = { -1, 2, 3 };
			num = -1 * 2 * 3;

			Assert::IsTrue(right == Factorize(num));
		}
	};
}
