#include "CppUnitTest.h"

#define ALWAYS_LOW2HIGH

#include "../../AlgoShiz/Sorts/BubbleSort.hpp"
#include "../../AlgoShiz/Sorts/BeadSort.hpp"
#include "../../AlgoShiz/Sorts/CombSort.hpp"
#include "../../AlgoShiz/Sorts/CountingSort.hpp"
#include "../../AlgoShiz/Sorts/HeapSort.hpp"
#include "../../AlgoShiz/Sorts/InsertionSort.hpp"


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
			auto sorted = new int[6] { 1, 2, 3, 4, 5, 6 };

			auto result = BubbleSorted(&unsorted);
			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(BubbleSortTest)
		{
			auto unsorted = std::vector<int> { 3, 2, 6, 1, 5, 4 };
			auto sorted = new int[6] { 1, 2, 3, 4, 5, 6 };

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
			auto unsorted = std::vector<int> { 3, 2, 6, 1, 5, 4 };
			auto sorted = new int[6] { 1, 2, 3, 4, 5, 6 };

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


	TEST_CLASS(CountingSortTests)
	{
	public:
		TEST_METHOD(CountingSortTest)
		{
			auto unsorted = new int[6] { 3, 2, 6, 1, 5, 4 };
			auto sorted = new int[6] { 1, 2, 3, 4, 5, 6 };

			CountingSort(unsorted, 6);
			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], unsorted[i]);
		}
	};


	TEST_CLASS(HeapSortTests)
	{
	public:
		TEST_METHOD(HeapSortTest)
		{
			auto unsorted = new int[6] { 3, 2, 6, 1, 5, 4 };
			auto sorted = new int[6] { 1, 2, 3, 4, 5, 6 };

			HeapSort(unsorted, 6);
			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], unsorted[i]);
		}
	};


	TEST_CLASS(InsertionSortTests)
	{
	public:
		TEST_METHOD(InsertionSortTest)
		{
			auto unsorted = std::vector<int> { 3, 2, 6, 1, 5, 4 };
			auto sorted = new int[6] { 1, 2, 3, 4, 5, 6 };

			InsertionSort(&unsorted);
			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], unsorted[i]);
		}


		TEST_METHOD(InsertionSortedTest)
		{
			auto unsorted = std::vector<int>{ 3, 2, 6, 1, 5, 4 };
			auto sorted = new int[6]{ 1, 2, 3, 4, 5, 6 };

			auto result = InsertionSorted(&unsorted);
			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}
	};
}
