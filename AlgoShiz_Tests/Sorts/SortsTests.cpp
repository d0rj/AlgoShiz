#include "CppUnitTest.h"
#include "../../AlgoShiz/Sorts/BubbleSort.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace Tests_Sorts
{
	TEST_CLASS(SortsTests)
	{
	public:
		TEST_METHOD(BubbleSortedTest)
		{
			auto unsorted = std::vector<int>{ 3, 2, 6, 1, 5, 4 };
			auto sorted = std::vector<int>{ 1, 2, 3, 4, 5, 6 };
			std::vector<int> result = BubbleSorted(&unsorted);

			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(BubbleSortTest)
		{
			auto unsorted = std::vector<int>{ 3, 2, 6, 1, 5, 4 };
			auto sorted = std::vector<int>{ 1, 2, 3, 4, 5, 6 };
			BubbleSort(&unsorted);

			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], unsorted[i]);
		}
	};
}
