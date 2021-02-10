#include "CppUnitTest.h"
#include <functional>
#include "../../AlgoShiz/Search/LinearSearch.hpp"
#include "../../AlgoShiz/Search/BinarySearch.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace Tests_Searches
{
	TEST_CLASS(SearchesTests)
	{
	private:
		void testWithArray(std::function<int(int*, size_t, int)> search)
		{
			int* arr = new int[10] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

			auto findedIndex = search(arr, 10, 11);
			Assert::AreEqual(-1, findedIndex);

			findedIndex = search(arr, 10, 4);
			Assert::AreEqual(3, findedIndex);

			findedIndex = search(arr, 10, 1);
			Assert::AreEqual(0, findedIndex);
		}


		void testWithVector(std::function<int(std::vector<int>&, int)> search)
		{
			std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

			auto findedIndex = search(arr, 11);
			Assert::AreEqual(-1, findedIndex);

			findedIndex = search(arr, 4);
			Assert::AreEqual(3, findedIndex);

			findedIndex = search(arr, 1);
			Assert::AreEqual(0, findedIndex);
		}


		void testWithVectorPointer(std::function<int(std::vector<int>*, int)> search)
		{
			std::vector<int> arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

			auto findedIndex = search(&arr, 11);
			Assert::AreEqual(-1, findedIndex);

			findedIndex = search(&arr, 4);
			Assert::AreEqual(3, findedIndex);

			findedIndex = search(&arr, 1);
			Assert::AreEqual(0, findedIndex);
		}


		void testWithRandomArray(std::function<int(int*, size_t, int)> search)
		{
			int* arr = new int[10] { 11, 2, 7, 4, 7, 6, 3, 5, 9, 2 };

			auto findedIndex = search(arr, 10, 11);
			Assert::AreEqual(0, findedIndex);

			findedIndex = search(arr, 10, 4);
			Assert::AreEqual(3, findedIndex);

			findedIndex = search(arr, 10, 1);
			Assert::AreEqual(-1, findedIndex);
		}


		void testWithRandomVector(std::function<int(std::vector<int>&, int)> search)
		{
			std::vector<int> arr = { 11, 2, 7, 4, 7, 6, 3, 5, 9, 2 };

			auto findedIndex = search(arr, 11);
			Assert::AreEqual(0, findedIndex);

			findedIndex = search(arr, 4);
			Assert::AreEqual(3, findedIndex);

			findedIndex = search(arr, 1);
			Assert::AreEqual(-1, findedIndex);
		}


		void testWithRandomVectorPointer(std::function<int(std::vector<int>*, int)> search)
		{
			std::vector<int> arr = { 11, 2, 7, 4, 7, 6, 3, 5, 9, 2 };

			auto findedIndex = search(&arr, 11);
			Assert::AreEqual(0, findedIndex);

			findedIndex = search(&arr, 4);
			Assert::AreEqual(3, findedIndex);

			findedIndex = search(&arr, 1);
			Assert::AreEqual(-1, findedIndex);
		}

	public:
		TEST_METHOD(LinearSearchTest_Array)
		{
			auto testing = [](int* arr, size_t n, int elem) -> int
			{
				return LinearSearch(arr, n, elem);
			};

			testWithArray(testing);
			testWithRandomArray(testing);
		}


		TEST_METHOD(LinearSearchTest_Vector)
		{
			auto testing = [](std::vector<int>& arr, int elem) -> int
			{
				return LinearSearch(arr, elem);
			};

			testWithVector(testing);
			testWithRandomVector(testing);
		}


		TEST_METHOD(LinearSearchTest_VectorPointer)
		{
			auto testing = [](std::vector<int>* arr, int elem) -> int
			{
				return LinearSearch(arr, elem);
			};

			testWithVectorPointer(testing);
			testWithRandomVectorPointer(testing);
		}


		TEST_METHOD(BinarySearchTest_Array)
		{
			auto testing = [](int* arr, size_t n, int elem) -> int
			{
				return BinarySearch(arr, n, elem);
			};

			testWithArray(testing);
		}


		TEST_METHOD(BinarySearchTest_Vector)
		{
			auto testing = [](std::vector<int>& arr, int elem) -> int
			{
				return BinarySearch(arr, elem);
			};

			testWithVector(testing);
		}


		TEST_METHOD(BinarySearchTest_VectorPointer)
		{
			auto testing = [](std::vector<int>* arr, int elem) -> int
			{
				return BinarySearch(arr, elem);
			};

			testWithVectorPointer(testing);
		}
	};
}
