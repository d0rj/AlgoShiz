#include "CppUnitTest.h"
#include "../../AlgoShiz/Structures/Vector.hpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace AlgoShiz;


namespace Tests_Structures
{
	TEST_CLASS(VectorTests)
	{
	public:
		TEST_METHOD(ConstructorTest)
		{
			auto vec = Vector<int>();
			Assert::AreEqual((size_t)0, vec.Length());
			
			vec = Vector<int>(10, 2);
			Assert::AreEqual((size_t)10, vec.Length());
			for (size_t i = 0; i < vec.Length(); ++i)
				Assert::AreEqual(2, vec[i]);
		}


		TEST_METHOD(IndexTest)
		{
			auto vec = Vector<std::string>(10, "a");
			for (size_t i = 0; i < vec.Length(); ++i)
				Assert::AreEqual((std::string)"a", vec[i]);

			for (size_t i = 0; i < vec.Length(); ++i)
				Assert::AreEqual(vec[i], vec.At(i));
		}
	};
}
