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

			for (size_t i = 0; i < vec.Length(); ++i)
				Assert::AreEqual((int)i, vec[i]);

			vec.PushBack(5);
			vec.PushBack(6);

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

			for (size_t i = 0; i < vec.Length(); ++i)
				Assert::AreEqual((int)(i + 3), vec[i]);

			vec.PushForward(2);
			vec.PushForward(1);
			vec.PushForward(0);

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

			int i = 0;
			while (vec.Length() > 0)
			{
				Assert::AreEqual(i, vec.PopForward());
				++i;
			}

			vec.PushBack(4);
			vec.PushBack(5);
			vec.PushBack(6);

			i = 4;
			while (vec.Length() > 0)
			{
				Assert::AreEqual(i, vec.PopForward());
				++i;
			}
		}
	};
}
