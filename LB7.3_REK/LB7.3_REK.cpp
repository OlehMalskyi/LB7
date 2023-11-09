#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

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

int firstZeroColumn(int** a, int rowCount, int colCount, int i, int j, int colNumber)
{
    if (i < colCount && colNumber == -1)
    {
        if (a[j][i] == 0)
            colNumber = i;
        return firstZeroColumn(a, rowCount, colCount, i + 1, j, colNumber);
    }
    else if (j < rowCount - 1)
    {
        return firstZeroColumn(a, rowCount, colCount, 0, j + 1, colNumber);
    }
    else
    {
        return colNumber;
    }
}

void Change(int** a, int colCount, int row1, int row2, int i)
{
    if (i < colCount)
    {
        int temp = a[row1][i];
        a[row1][i] = a[row2][i];
        a[row2][i] = temp;
        Change(a, colCount, row1, row2, ++i);
    }
}

int rowSum(int** a, int row, int colCount, int sum, int i)
{
    if (i < colCount)
    {
        if (a[row][i] < 0 && a[row][i] % 2 == 0)
        {
            sum += a[row][i];
        }
        rowSum(a, row, colCount, sum, ++i);
    }
    else
        return sum;
}

void changeRows(int** a, int rowCount, int colCount, int j, int i)
{
    if (j < rowCount - 1)
    {
        if (i < rowCount - j - 1)
        {
            if (rowSum(a, i, colCount, 0, 0) < rowSum(a, i + 1, colCount, 0, 0))
            {
                Change(a, colCount, i, i + 1, 0);
            }
            changeRows(a, rowCount, colCount, j, ++i);
        }
        changeRows(a, rowCount, colCount, ++j, 0);
    }
}



int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int Low = -10;
    int High = 10;
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

    int zeroColumn = firstZeroColumn(a, rowCount, colCount, 0, 0, -1);
    if (zeroColumn != -1)
        cout << "Перший 0 в стовпці: " << zeroColumn + 1 << endl;
    else
        cout << "Нульових елементів у матриці немає" << endl;

    changeRows(a, rowCount, colCount, 0, 0);
    PrintRows(a, colCount, rowCount, 0);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}
