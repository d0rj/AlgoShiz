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
			int* arr = new int[10]{ 2, 4, 9, 11, 1, 3, 6, 7, 5, 1 };

			auto findedIndex = search(arr, 10, 11);
			Assert::AreEqual(3, findedIndex);

			findedIndex = search(arr, 10, -10);
			Assert::AreEqual(-1, findedIndex);

			findedIndex = search(arr, 10, 1);
			Assert::AreEqual(4, findedIndex);
		}


		void testWithVector(std::function<int(std::vector<int>&, int)> search)
		{
			std::vector<int> arr = { 2, 4, 9, 11, 1, 3, 6, 7, 5, 1 };

			auto findedIndex = search(arr, 11);
			Assert::AreEqual(3, findedIndex);

			findedIndex = search(arr, -10);
			Assert::AreEqual(-1, findedIndex);

			findedIndex = search(arr, 1);
			Assert::AreEqual(4, findedIndex);
		}


		void testWithVectorPointer(std::function<int(std::vector<int>*, int)> search)
		{
			std::vector<int> arr = { 2, 4, 9, 11, 1, 3, 6, 7, 5, 1 };

			auto findedIndex = search(&arr, 11);
			Assert::AreEqual(3, findedIndex);

			findedIndex = search(&arr, -10);
			Assert::AreEqual(-1, findedIndex);

			findedIndex = search(&arr, 1);
			Assert::AreEqual(4, findedIndex);
		}

	public:
		TEST_METHOD(LinearSearchTest_Array)
		{
			auto testing = [](int* arr, size_t n, int elem) -> int
			{
				return LinearSearch(arr, n, elem);
			};

			testWithArray(testing);
		}


		TEST_METHOD(LinearSearchTest_Vector)
		{
			auto testing = [](std::vector<int>& arr, int elem) -> int
			{
				return LinearSearch(arr, elem);
			};

			testWithVector(testing);
		}


		TEST_METHOD(LinearSearchTest_VectorPointer)
		{
			auto testing = [](std::vector<int>* arr, int elem) -> int
			{
				return LinearSearch(arr, elem);
			};

			testWithVectorPointer(testing);
		}
	};
}
