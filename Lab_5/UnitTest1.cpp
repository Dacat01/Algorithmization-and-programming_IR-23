#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab5/Lab5.cpp"
#include <vector>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string str = "abcabcdAAAABAAAAABBBAAAABabcabcd";
			string pattern = "abcabcd";

			vector<int> results = KMP(str, pattern);

			Assert::AreEqual(0, results[0]);
			Assert::AreEqual(25, results[1]);
		}

		TEST_METHOD(TestMethod_2)
		{
			string str = "abcdefg";
			string pattern = "";

			vector<int> results = KMP(str, pattern);

			Assert::AreEqual(-1, results[0]);

		}

		TEST_METHOD(TestMethod_3)
		{
			string str = "ABC ABCDAB ABCDABCDABDE";
			string pattern = "ABCDABD";

			vector<int> results = KMP(str, pattern);

			Assert::AreEqual(15, results[0]);

		}

		TEST_METHOD(TestMethod_4)
		{
			string str = "THIS IS A TEST TEXT";
			string pattern = "TEST";

			vector<int> results = KMP(str, pattern);

			Assert::AreEqual(10, results[0]);
		}

		TEST_METHOD(TestMethod_5)
		{
			string str = "123456711567";
			string pattern = "567";

			vector<int> results = KMP(str, pattern);

			Assert::AreEqual(4, results[0]);
			Assert::AreEqual(9, results[1]);
		}


	};
}
