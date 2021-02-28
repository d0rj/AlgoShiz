#include "CppUnitTest.h"

#define ALWAYS_LOW2HIGH

#include "../../AlgoShiz/Sorts/BubbleSort.hpp"
#include "../../AlgoShiz/Sorts/BeadSort.hpp"
#include "../../AlgoShiz/Sorts/CombSort.hpp"
#include "../../AlgoShiz/Sorts/CountingSort.hpp"
#include "../../AlgoShiz/Sorts/HeapSort.hpp"
#include "../../AlgoShiz/Sorts/InsertionSort.hpp"
#include "../../AlgoShiz/Sorts/MergeSort.hpp"
#include "../../AlgoShiz/Sorts/QuickSort.hpp"
#include "../../AlgoShiz/Sorts/RadixSort.hpp"
#include "../../AlgoShiz/Sorts/SelectionSort.hpp"
#include "../../AlgoShiz/Sorts/ShakerSort.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace Tests_Sorts
{
	TEST_CLASS(AllSortsTests)
	{
	private:
		static const size_t n = 6;
		const int sorted[6] = { 1, 2, 3, 4, 5, 6 };
		const int unsorted[6] = { 3, 2, 6, 1, 5, 4 };

		int* getUnsorted()
		{
			int* result = new int[n];
			std::copy(unsorted, unsorted + n, result);
			return result;
		}


		std::vector<int> getUnsortedVector()
		{
			auto res = getUnsorted();
			std::vector<int> result(res, res + n);
			return result;
		}


		void compareArrays(int* expected, int* actual, size_t size = n) const
		{
			for (size_t i = 0; i < size; ++i)
				Assert::AreEqual(expected[i], actual[i]);
		}


		void compareArray(int* actual) const
		{
			compareArrays((int*)sorted, actual);
		}


		void compareWithVector(int* expected, std::vector<int> actual, size_t size = n)const
		{
			Assert::AreEqual(size, actual.size());

			for (size_t i = 0; i < size; ++i)
				Assert::AreEqual(expected[i], actual[i]);
		}


		void compareVector(std::vector<int> actual) const
		{
			compareWithVector((int*)sorted, actual);
		}

	public:

		TEST_METHOD(BubbleSortedTest)
		{
			auto unsorted = getUnsortedVector();

			compareVector(BubbleSorted(&unsorted));
		}


		TEST_METHOD(BubbleSortTest)
		{
			auto result = getUnsortedVector();
			BubbleSort(&result);
			compareVector(result);
		}


		TEST_METHOD(BeadSortedTest)
		{
			auto unsorted = getUnsortedVector();

			compareVector(BeadSorted(&unsorted));
		}


		TEST_METHOD(BeadSortedTest_Array)
		{			
			compareVector(BeadSorted(unsorted));
		}


		TEST_METHOD(CombSortTest)
		{
			auto result = getUnsortedVector();
			CombSort(result);
			compareVector(result);
		}


		TEST_METHOD(CombSortTest_ref)
		{
			auto result = getUnsortedVector();
			CombSort(&result);
			compareVector(result);
		}


		TEST_METHOD(CountingSortTest)
		{
			int result[6];
			std::copy(unsorted, unsorted + n, result);
			CountingSort(result);
			compareArray(result);
		}
		

		TEST_METHOD(HeapSortTest)
		{
			auto result = getUnsorted();
			HeapSort(result, n);
			compareArray(result);
		}


		TEST_METHOD(InsertionSortTest)
		{
			auto result = getUnsortedVector();
			InsertionSort(&result);
			compareVector(result);
		}


		TEST_METHOD(InsertionSortedTest)
		{
			auto unsorted = getUnsortedVector();
			
			compareVector(InsertionSorted(&unsorted));
		}


		TEST_METHOD(MergeSortTest_Array)
		{
			auto result = getUnsorted();
			MergeSort(result, n);
			compareArray(result);
		}


		TEST_METHOD(MergeSortTest_Vector)
		{
			auto result = getUnsortedVector();
			MergeSort(&result);
			compareVector(result);
		}


		TEST_METHOD(QuickSortTest)
		{
			auto result = getUnsorted();
			QuickSort(result, n);
			compareArray(result);
		}


		TEST_METHOD(RadixSortTest)
		{
			auto result = getUnsorted();
			RadixSort(result, n);
			compareArray(result);
		}


		TEST_METHOD(SelectionSortedTest)
		{
			auto unsorted = getUnsortedVector();
			
			compareVector(SelectionSorted(&unsorted));
		}


		TEST_METHOD(SelectionSortTest)
		{
			auto result = getUnsortedVector();
			SelectionSort(&result);
			compareVector(result);
		}


		TEST_METHOD(ShakerSortTest)
		{
			auto result = getUnsorted();
			ShakerSort(result, n);
			compareArray(result);
		}


		TEST_METHOD(ShakerSortedTest)
		{
			auto unsorted = getUnsorted();

			compareArray(ShakerSorted(unsorted, n));
		}


		TEST_METHOD(ShakerSortTest_Vector)
		{
			auto result = getUnsortedVector();
			ShakerSort(&result);
			compareVector(result);
		}


		TEST_METHOD(ShakerSortedTest_Vector)
		{
			auto unsorted = getUnsortedVector();
			auto result = ShakerSorted(&unsorted);
			compareVector(*result);
		}
	};
}
