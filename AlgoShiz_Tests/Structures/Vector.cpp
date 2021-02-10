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


		TEST_METHOD(PushBackTest)
		{
			auto vec = Vector<int>();
			vec.PushBack(0);
			vec.PushBack(1);
			vec.PushBack(2);
			vec.PushBack(3);
			vec.PushBack(4);

			Assert::AreEqual((size_t)5, vec.Length());
			for (size_t i = 0; i < vec.Length(); ++i)
				Assert::AreEqual((int)i, vec[i]);

			vec.PushBack(5);
			vec.PushBack(6);

			Assert::AreEqual((size_t)7, vec.Length());
			for (size_t i = 0; i < vec.Length(); ++i)
				Assert::AreEqual((int)i, vec[i]);
		}


		TEST_METHOD(PushForwardTest)
		{
			auto vec = Vector<int>();
			vec.PushForward(6);
			vec.PushForward(5);
			vec.PushForward(4);
			vec.PushForward(3);

			Assert::AreEqual((size_t)4, vec.Length());
			for (size_t i = 0; i < vec.Length(); ++i)
				Assert::AreEqual((int)(i + 3), vec[i]);

			vec.PushForward(2);
			vec.PushForward(1);
			vec.PushForward(0);

			Assert::AreEqual((size_t)7, vec.Length());
			for (size_t i = 0; i < vec.Length(); ++i)
				Assert::AreEqual((int)i, vec[i]);
		}


		TEST_METHOD(PopBackTest)
		{
			auto vec = Vector<int>();
			vec.PushBack(0);
			vec.PushBack(1);
			vec.PushBack(2);
			vec.PushBack(3);
			vec.PushBack(4);

			Assert::AreEqual((size_t)5, vec.Length());
			int i = 4;
			while (vec.Length() > 0)
			{
				Assert::AreEqual(i, vec.PopBack());
				--i;
			}

			vec.PushBack(3);
			vec.PushBack(2);
			vec.PushBack(1);
			vec.PushBack(0);

			Assert::AreEqual((size_t)4, vec.Length());
			i = 0;
			while (vec.Length() > 0)
			{
				Assert::AreEqual(i, vec.PopBack());
				++i;
			}
		}


		TEST_METHOD(PopForwardTest)
		{
			auto vec = Vector<int>();
			vec.PushBack(0);
			vec.PushBack(1);
			vec.PushBack(2);
			vec.PushBack(3);
			vec.PushBack(4);
			vec.PushBack(5);

			Assert::AreEqual((size_t)6, vec.Length());
			int i = 0;
			while (vec.Length() > 0)
			{
				Assert::AreEqual(i, vec.PopForward());
				++i;
			}

			vec.PushBack(4);
			vec.PushBack(5);
			vec.PushBack(6);

			Assert::AreEqual((size_t)3, vec.Length());
			i = 4;
			while (vec.Length() > 0)
			{
				Assert::AreEqual(i, vec.PopForward());
				++i;
			}
		}


		TEST_METHOD(PlusOperatorTest)
		{
			auto vec = Vector<int>();
			vec = vec + 1;
			vec = vec + 2;
			vec = vec + 3;
			vec = vec + 4;

			Assert::AreEqual((size_t)4, vec.Length());
			for (size_t i = 0; i < vec.Length(); ++i)
				Assert::AreEqual((int)(i + 1), vec[i]);
		}


		TEST_METHOD(PlusEqualOperatorTest)
		{
			auto vec = Vector<int>();
			vec += 1;
			vec += 2;
			vec += 3;
			vec += 4;

			Assert::AreEqual((size_t)4, vec.Length());
			for (size_t i = 0; i < vec.Length(); ++i)
				Assert::AreEqual((int)(i + 1), vec[i]);
		}
	};
}
