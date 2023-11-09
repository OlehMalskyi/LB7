#include "pch.h"
#include "CppUnitTest.h"
#include "../LB7.1/LB7.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int S = 0;
			int k = 0;
			int** z = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				z[i] = new int[colCount];

			z[0][0] = 1;
			z[0][1] = 2;
			z[0][2] = 3;
			z[1][0] = 4;
			z[1][1] = 5;
			z[1][2] = 6;
			z[2][0] = 7;
			z[2][1] = 8;
			z[2][2] = 9;

			Calc(z, rowCount, colCount, S, k);

		
			Assert::AreEqual(45, S);
			Assert::AreEqual(9, k); 

		
			for (int i = 0; i < rowCount; i++)
				delete[] z[i];
			delete[] z;
		}
	};
}
