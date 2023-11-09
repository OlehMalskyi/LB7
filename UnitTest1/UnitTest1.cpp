#include "pch.h"
#include "CppUnitTest.h"
#include "../LB7.2_ITER/LB7.2_IT.cpp"

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
			int** a = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			a[0][0] = 1;
			a[0][1] = 2;
			a[0][2] = 3;
			a[1][0] = 4;
			a[1][1] = 5;
			a[1][2] = 6;
			a[2][0] = 7;
			a[2][1] = 8;
			a[2][2] = 9;

			int result = findIndex(a, 2, 8, 3);

			Assert::AreEqual(1, result);

			for (int i = 0; i < rowCount; i++)
				delete[] a[i];
			delete[] a;
		}
	};
}
