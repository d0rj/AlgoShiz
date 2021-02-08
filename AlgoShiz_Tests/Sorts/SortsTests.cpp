#include "CppUnitTest.h"

#define ALWAYS_LOW2HIGH

#include "../../AlgoShiz/Sorts/BubbleSort.hpp"
#include "../../AlgoShiz/Sorts/BeadSort.hpp"
#include "../../AlgoShiz/Sorts/CombSort.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace Tests_Sorts
{
	TEST_CLASS(BubbleSortTests)
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


	TEST_CLASS(BeadSortTests)
	{
	public:
		TEST_METHOD(BeadSortedTest)
		{
			auto unsorted = std::vector<int>{ 3, 2, 6, 1, 5, 4 };
			auto sorted = std::vector<int>{ 1, 2, 3, 4, 5, 6 };
			auto result = BeadSorted(&unsorted);

			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(BeadSortedTest_Array)
		{
			auto unsorted = new int[6] { 3, 2, 6, 1, 5, 4 };
			auto sorted = new int[6] { 1, 2, 3, 4, 5, 6 };
			auto result = BeadSorted(unsorted, 6);

			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}
	};


	TEST_CLASS(CombSortTests)
	{
	public:
		TEST_METHOD(BucketSortTest)
		{
			auto unsorted = std::vector<int> { 3, 2, 6, 1, 5, 4 };
			auto sorted = new int[6] { 1, 2, 3, 4, 5, 6 };
			CombSort(unsorted);

			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], unsorted[i]);
		}


		TEST_METHOD(BucketSortTest_ref)
		{
			auto unsorted = std::vector<int>{ 3, 2, 6, 1, 5, 4 };
			auto sorted = new int[6]{ 1, 2, 3, 4, 5, 6 };
			CombSort(&unsorted);

			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], unsorted[i]);
		}
	};
}
