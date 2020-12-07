#include "pch.h"
#include "CppUnitTest.h"


#include "../Lab_3/Lab_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TRIBE)					// pairs & pairs count TEST
		{

			std::vector< int > test;

			ofstream MyFile("filename.txt");

			MyFile << "3\n";
			MyFile << "1 2\n";
			MyFile << "2 4\n";
			MyFile << "3 5\n";

			MyFile.close();


			Tribes Tribe;

			string path = "filename.txt";

			Tribe.tribe_main(path);

			test = Tribe.pairs;

			Assert::AreEqual(test.size() / 2, (unsigned int)4);

			Assert::AreEqual(test[0], 2);		//1 пара 
			Assert::AreEqual(test[1], 3);

			Assert::AreEqual(test[2], 2);		//2 пара
			Assert::AreEqual(test[3], 5);

			Assert::AreEqual(test[4], 4);		//3 пара
			Assert::AreEqual(test[5], 3);
		}

		TEST_METHOD(TRIBE_2)						// pairs & pairs count TEST
		{

			std::vector< int > test;

			ofstream MyFile("filename.txt");

			MyFile << "9\n";
			MyFile << "1 2\n";
			MyFile << "8 10\n";
			MyFile << "10 14\n";
			MyFile << "2 4\n";
			MyFile << "1 3\n";
			MyFile << "3 5\n";
			MyFile << "5 7\n";
			MyFile << "7 6\n";
			MyFile << "6 11";

			MyFile.close();


			Tribes Tribe;

			string path = "filename.txt";

			Tribe.tribe_main(path);
			test = Tribe.pairs;

			Assert::AreEqual(test.size() / 2, (unsigned int)15);	//Перевірка кількості отриманих пар

			Assert::AreEqual(test[0], 1);		//1 пара 
			Assert::AreEqual(test[1], 8);

			Assert::AreEqual(test[2], 1);		//2 пара 
			Assert::AreEqual(test[3], 10);

			Assert::AreEqual(test[28], 11);		//15 пара 
			Assert::AreEqual(test[29], 14);

		}

		TEST_METHOD(VERTEXES_IN_GRAPHS)				// vertexes_in_graphs TEST
		{

			std::vector< int > test;

			ofstream MyFile("filename.txt");

			MyFile << "3\n";
			MyFile << "1 2\n";
			MyFile << "2 4\n";
			MyFile << "3 5\n";

			MyFile.close();


			Tribes Tribe;

			string path = "filename.txt";

			Tribe.tribe_main(path);

			test = Tribe.vertexes_in_graphs;

			Assert::AreEqual(test[0], 3);
			Assert::AreEqual(test[1], 2);

		}


		TEST_METHOD(VISITED_VERTEXES)			// visited_vertexes_in_graphs TEST
		{

			std::vector< int > test;

			ofstream MyFile("filename.txt");

			MyFile << "3\n";
			MyFile << "1 2\n";
			MyFile << "2 4\n";
			MyFile << "3 5\n";

			MyFile.close();


			Tribes Tribe;

			string path = "filename.txt";

			Tribe.tribe_main(path);

			test = Tribe.visited_vertexes_in_graphs;

			Assert::AreEqual(test[0], 1);
			Assert::AreEqual(test[1], 2);
			Assert::AreEqual(test[2], 4);
			Assert::AreEqual(test[3], 3);
			Assert::AreEqual(test[4], 5);

		}


		TEST_METHOD(MAX_VERTEX)			// max_vertex TEST
		{

			int test;

			ofstream MyFile("filename.txt");

			MyFile << "3\n";
			MyFile << "1 2\n";
			MyFile << "2 4\n";
			MyFile << "3 5\n";

			MyFile.close();


			Tribes Tribe;

			string path = "filename.txt";

			Tribe.tribe_main(path);

			test = Tribe.max_vertex;

			Assert::AreEqual(test, 6);
		}



	};

}
