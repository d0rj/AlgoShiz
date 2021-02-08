#include "CppUnitTest.h"

#define ALWAYS_LOW2HIGH

#include "../../AlgoShiz/Sorts/BubbleSort.hpp"
#include "../../AlgoShiz/Sorts/BeadSort.hpp"
#include "../../AlgoShiz/Sorts/CombSort.hpp"
#include "../../AlgoShiz/Sorts/CountingSort.hpp"
#include "../../AlgoShiz/Sorts/HeapSort.hpp"
#include "../../AlgoShiz/Sorts/InsertionSort.hpp"
#include "../../AlgoShiz/Sorts/MergeSort.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace Tests_Sorts
{
	TEST_CLASS(AllSortsTests)
	{
	private:
		const size_t n = 6;
		const int* sorted = new int[6] { 1, 2, 3, 4, 5, 6 };
		const int* unsorted = new int[6] { 3, 2, 6, 1, 5, 4 };

		int* getUnsorted()
		{
			int* result = new int[6];
			std::copy(unsorted, unsorted + n, result);
			return result;
		}


		std::vector<int> getUnsortedVector()
		{
			auto res = getUnsorted();
			std::vector<int> result(res, res + n);
			return result;
		}

	public:

		TEST_METHOD(BubbleSortedTest)
		{
			auto result = getUnsortedVector();
			result = BubbleSorted(&result);

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(BubbleSortTest)
		{
			auto result = getUnsortedVector();
			BubbleSort(&result);

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(BeadSortedTest)
		{
			auto result = getUnsortedVector();
			result = BeadSorted(&result);

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(BeadSortedTest_Array)
		{
			auto unsorted = getUnsorted();
			auto result = BeadSorted(unsorted, n);

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(CombSortTest)
		{
			auto result = getUnsortedVector();
			CombSort(result);

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(CombSortTest_ref)
		{
			auto result = getUnsortedVector();
			CombSort(&result);

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(CountingSortTest)
		{
			auto result = getUnsorted();
			CountingSort(result, n);

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}
		

		TEST_METHOD(HeapSortTest)
		{
			auto result = getUnsorted();
			HeapSort(result, 6);

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(InsertionSortTest)
		{
			auto result = getUnsortedVector();

			InsertionSort(&result);
			for (size_t i = 0; i < 6; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(InsertionSortedTest)
		{
			auto result = getUnsortedVector();
			result = InsertionSorted(&result);

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(MergeSortTest_Array)
		{
			auto result = getUnsorted();
			MergeSort(result, n);

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}


		TEST_METHOD(MergeSortTest_Vector)
		{
			auto result = getUnsortedVector();
			MergeSort(&result);

			for (size_t i = 0; i < n; ++i)
				Assert::AreEqual(sorted[i], result[i]);
		}
	};
}
