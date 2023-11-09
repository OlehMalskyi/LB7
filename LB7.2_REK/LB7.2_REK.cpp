#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

void CreateRow(int** a, const int rowNo, const int N, const int Low, const int High, int colNo)
{
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < N - 1)
        CreateRow(a, rowNo, N, Low, High, colNo + 1);
}

void CreateRows(int** a, const int N, const int K, const int Low, const int High, int rowNo)
{
    CreateRow(a, rowNo, K, Low, High, 0);
    if (rowNo < N - 1)
        CreateRows(a, N, K, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
    cout << setw(4) << a[rowNo][colNo];
    if (colNo < N - 1)
        PrintRow(a, rowNo, N, colNo + 1);
    else
        cout << endl;
}

void PrintRows(int** a, const int N, const int K, int rowNo)
{
    PrintRow(a, rowNo, K, 0);
    if (rowNo < N - 1)
        PrintRows(a, N, K, rowNo + 1);
    else
        cout << endl;
}

void Change(int** a, int iMax, int iMin, int i)
{
    int tmp = a[i][iMax];
    a[i][iMax] = a[i][iMin];
    a[i][iMin] = tmp;
}

int findIndex(int** a, int i, int num, int k, int index, int j)
{
    if (j < k)
    {
        if (a[i][j] == num)
        {
            index = j;
            return index;
        }
        return findIndex(a, i, num, k, index, ++j);
    }
    return -1;
}

void findMinAndMaxInRow(int** a, int rowCount, int colCount, int i)
{
    if (i < rowCount)
    {
        if (i % 2 != 0) 
        {
            int maxIndex = 0;
            int minIndex = 0;

            for (int col = 1; col < colCount; col++)
            {
                if (a[i][col] > a[i][maxIndex])
                    maxIndex = col;
                if (a[i][col] < a[i][minIndex])
                    minIndex = col;
            }

            Change(a, maxIndex, minIndex, i);
        }

        findMinAndMaxInRow(a, rowCount, colCount, i + 1);
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int Low = -34;
    int High = 26;
    int rowCount;
    int colCount;

    cout << "k = ";
    cin >> rowCount;
    cout << "n = ";
    cin >> colCount;

    int** a = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    CreateRows(a, rowCount, colCount, Low, High, 0);
    PrintRows(a, colCount, rowCount, 0);

    findMinAndMaxInRow(a, rowCount, colCount, 0);
    PrintRows(a, colCount, rowCount, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}