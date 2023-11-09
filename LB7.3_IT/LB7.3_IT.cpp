#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
    for (int i = 0; i < rowCount; i++)
        for (int j = 0; j < colCount; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int rowCount, const int colCount)
{
    cout << endl;
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < colCount; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Change(int** a, int colCount, int row1, int row2)
{
    for (int i = 0; i < colCount; ++i)
    {
        int temp = a[row1][i];
        a[row1][i] = a[row2][i];
        a[row2][i] = temp;
    }
}

int firstZeroColumn(int** a, int rowCount, int colCount)
{
    for (int i = 0; i < colCount; i++)
    {
        for (int j = 0; j < rowCount; j++)
        {
            if (a[j][i] == 0)
                return i;
        }
    }
    return -1;
}

int rowSum(int** a, int row, int colCount)
{
    int sum = 0;
    for (int i = 0; i < colCount; i++)
    {
        if (a[row][i] < 0 && a[row][i] % 2 == 0)
        {
            sum += a[row][i];
        }
    }
    return sum;
}

void Sort(int** a, int rowCount, int colCount)
{
    for (int j = 0; j < rowCount - 1; j++)
        for (int i = 0; i < rowCount - j - 1; i++)
        {
            if (rowSum(a, i, colCount) < rowSum(a, i + 1, colCount))
            {
                Change(a, colCount, i, i + 1);
            }
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

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    int zeroColumn = firstZeroColumn(a, rowCount, colCount);
    if (zeroColumn != -1)
        cout << "Перший 0 в стовпці: " << zeroColumn + 1 << endl;
    else
        cout << "Нульових елементів у матриці немає" << endl;

    Sort(a, rowCount, colCount);
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}