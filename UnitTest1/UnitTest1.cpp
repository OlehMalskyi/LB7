#include "pch.h"
#include "CppUnitTest.h"
#include "../LB7.3_IT/LB7.3_IT.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestFirstZeroColumn)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];


			a[0][0] = 1; a[0][1] = 0; a[0][2] = 3;
			a[1][0] = 4; a[1][1] = 5; a[1][2] = 6;
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

			int result = firstZeroColumn(a, rowCount, colCount);

			Assert::AreEqual(1, result);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestRowSum)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];


			a[0][0] = -2; a[0][1] = 4; a[0][2] = -6;
			a[1][0] = 1; a[1][1] = 3; a[1][2] = 5;
			a[2][0] = -8; a[2][1] = 6; a[2][2] = -4;

			int result = rowSum(a, 0, colCount);

			Assert::AreEqual(-8, result);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}

		TEST_METHOD(TestSort)
		{
			const int rowCount = 3;
			const int colCount = 3;
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];


			a[0][0] = 1; a[0][1] = 2; a[0][2] = 3;
			a[1][0] = -2; a[1][1] = 4; a[1][2] = -6;
			a[2][0] = 7; a[2][1] = 8; a[2][2] = 9;

			Sort(a, rowCount, colCount);


			Assert::AreEqual(0, rowSum(a, 0, colCount));
			Assert::AreEqual(0, rowSum(a, 1, colCount));
			Assert::AreEqual(-8, rowSum(a, 2, colCount));

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
