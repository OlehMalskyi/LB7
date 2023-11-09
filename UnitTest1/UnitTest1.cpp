#include "pch.h"
#include "CppUnitTest.h"
#include "../LB7.3_REK/LB7.3_REK.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(TestChangeRows)
        {

            const int rowCount = 3;
            const int colCount = 4;
            int** a = new int* [rowCount];

            for (int i = 0; i < rowCount; i++)
                a[i] = new int[colCount];

            a[0][0] = 2; a[0][1] = -4; a[0][2] = 6; a[0][3] = 8;
            a[1][0] = -1; a[1][1] = 3; a[1][2] = -5; a[1][3] = 7;
            a[2][0] = -2; a[2][1] = 4; a[2][2] = -6; a[2][3] = 8;

            changeRows(a, rowCount, colCount, 0, 0);

            Assert::AreEqual(a[0][0], -1);
            Assert::AreEqual(a[1][1], -4);
            Assert::AreEqual(a[2][1], 4);
            Assert::AreEqual(a[2][3], 8);

            for (int i = 0; i < rowCount; i++)
                delete[] a[i];
            delete[] a;
        }
	};
}
