#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_4/Lab_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(Fantazer_1)
		{
			Fantazer fantazerObj;

			fantazerObj.sequence = "101110011";
			//						101 11001 1
			fantazerObj.number = 5;

			fantazerObj.count_power(fantazerObj.sequence.length());
			fantazerObj.check_string();
			
			Assert::AreEqual(fantazerObj.result,3);
		}


		TEST_METHOD(Fantazer_2)
		{
			Fantazer fantazerObj;

			fantazerObj.sequence = "101101101";
			//						101 101 101
			fantazerObj.number = 5;

			fantazerObj.count_power(fantazerObj.sequence.length());
			fantazerObj.check_string();

			Assert::AreEqual(fantazerObj.result, 3);
		}


		TEST_METHOD(Fantazer_3)
		{
			Fantazer fantazerObj;

			fantazerObj.sequence = "11010001000000001001000011001";
			//						1  101000100000000  10010000  1100	1				
			fantazerObj.number = 12;
			
			fantazerObj.count_power(fantazerObj.sequence.length());
			fantazerObj.check_string();

			Assert::AreEqual(fantazerObj.result, 5);
		}

		TEST_METHOD(Fantazer_4)
		{
			Fantazer fantazerObj;

			fantazerObj.sequence = "110011111010000100110111110101111000011";
			//						11001 11110100001001 1011111010111100001 1
			fantazerObj.number = 25;

			fantazerObj.count_power(fantazerObj.sequence.length());
			fantazerObj.check_string();

			Assert::AreEqual(fantazerObj.result, 4);
		}

		TEST_METHOD(Fantazer_5)
		{
			Fantazer fantazerObj;

			fantazerObj.sequence = "10011100110100001101110001011110010001010010011000000110111111000110100100001101011101000001";
			//						1001 1100110100001 10111000101111001000101001001 10000001101111110001 10100100001101011101000001	
			fantazerObj.number = 9;

			fantazerObj.count_power(fantazerObj.sequence.length());
			fantazerObj.check_string();

			Assert::AreEqual(fantazerObj.result, 5);
		}
	
		TEST_METHOD(Fantazer_6)
		{
			Fantazer fantazerObj;

			fantazerObj.sequence = "010000001";
			//						0 1000000 1
			fantazerObj.number = 4;

			fantazerObj.count_power(fantazerObj.sequence.length());
			fantazerObj.check_string();

			Assert::AreEqual(fantazerObj.result, -1);
		}

	};

};

