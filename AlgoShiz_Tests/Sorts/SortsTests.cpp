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
		static const size_t n = 6;
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
			auto result = getUnsortedVector();
			result = BubbleSorted(&result);
			compareVector(result);
		}


		TEST_METHOD(BubbleSortTest)
		{
			auto result = getUnsortedVector();
			BubbleSort(&result);
			compareVector(result);
		}


		TEST_METHOD(BeadSortedTest)
		{
			auto result = getUnsortedVector();
			result = BeadSorted(&result);
			compareVector(result);
		}


		TEST_METHOD(BeadSortedTest_Array)
		{
			auto unsorted = getUnsorted();
			auto result = BeadSorted(unsorted, n);
			compareVector(result);
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
			auto result = getUnsorted();
			CountingSort(result, n);
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
			auto result = getUnsortedVector();
			result = InsertionSorted(&result);
			compareVector(result);
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
	};
}
