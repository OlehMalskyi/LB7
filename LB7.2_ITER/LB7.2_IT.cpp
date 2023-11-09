#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High);
void Print(int** a, const int rowCount, const int colCount);
void findMinAndMaxInRow(int** a, int rowCount, int colCount, int low, int high);


int main()
{
    srand((unsigned)time(NULL));

    int Low = -34;
    int High = 26;
    int rowCount;
    int colCount;
    cout << "k = "; cin >> rowCount;
    cout << "n = "; cin >> colCount;

    int** a = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        a[i] = new int[colCount];

    Create(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    findMinAndMaxInRow(a, rowCount, colCount, Low, High);
    Print(a, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}


void Create(int** a, const int rowCount, const int colCount, const int Low,
    const int High)
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

void Change(int** a, int iMax, int iMin, int i)
{
    int tmp = a[i][iMax];
    a[i][iMax] = a[i][iMin];
    a[i][iMin] = tmp;
}

int findIndex(int** a, int i, int num, int k)
{
    int index = 0;
    for (int j = 0; j < k; j++)
    {
        if (a[i][j] == num)
        {
            index = j;
            return index;
            break;
        }
    }
}

void findMinAndMaxInRow(int** a, int rowCount, int colCount, int low, int high)
{
    int max = low;
    int min = high;
    int iMax = 0;
    int iMin = 0;

    for (int i = 0; i < rowCount; i++)
    {
        max = low;
        min = high;
        if (i % 2 != 0) {
            for (int j = 0; j < colCount; j++)
            {
                if (max < a[i][j]) {
                    max = a[i][j];
                    iMax = findIndex(a, i, max, colCount);
                }
                if (min > a[i][j])
                {
                    min = a[i][j];
                    iMin = findIndex(a, i, min, colCount);
                }
            }
            Change(a, iMax, iMin, i);
            cout << "Max " << i << ' ' << max << ' ' << iMax << endl;
            cout << "min " << i << ' ' << min << ' ' << iMin << endl;
        }
    }
}
