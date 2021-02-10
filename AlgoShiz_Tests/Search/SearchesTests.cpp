#include "CppUnitTest.h"
#include "../../AlgoShiz/Search/LinearSearch.hpp"
#include "../../AlgoShiz/Search/BinarySearch.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace Tests_Searches
{
	TEST_CLASS(SearchesTests)
	{
	public:
		TEST_METHOD(LinearSearchTest_Array)
		{
			int* arr = new int[10] { 2, 4, 9, 11, 1, 3, 6, 7, 5, 1 };

			auto findedIndex = LinearSearch(arr, 10, 11);
			Assert::AreEqual(3, findedIndex);

			findedIndex = LinearSearch(arr, 10, -10);
			Assert::AreEqual(-1, findedIndex);

			findedIndex = LinearSearch(arr, 10, 1);
			Assert::AreEqual(4, findedIndex);
		}


		TEST_METHOD(LinearSearchTest_Vector)
		{
			std::vector<int> arr = { 2, 4, 9, 11, 1, 3, 6, 7, 5, 1 };

			auto findedIndex = LinearSearch(arr, 11);
			Assert::AreEqual(3, findedIndex);

			findedIndex = LinearSearch(arr, -10);
			Assert::AreEqual(-1, findedIndex);

			findedIndex = LinearSearch(arr, 1);
			Assert::AreEqual(4, findedIndex);
		}


		TEST_METHOD(LinearSearchTest_VectorPointer)
		{
			std::vector<int> arr = { 2, 4, 9, 11, 1, 3, 6, 7, 5, 1 };

			auto findedIndex = LinearSearch(&arr, 11);
			Assert::AreEqual(3, findedIndex);

			findedIndex = LinearSearch(&arr, -10);
			Assert::AreEqual(-1, findedIndex);

			findedIndex = LinearSearch(&arr, 1);
			Assert::AreEqual(4, findedIndex);
		}
	};
}
