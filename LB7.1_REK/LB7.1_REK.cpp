#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** z, const int rowCount, const int colCount, const int Low, const int High, int i, int j);
void Print(int** z, const int rowCount, const int colCount, int i, int j);
void Sort(int** z, const int rowCount, const int colCount, int i0, int i1);
void Change(int** z, const int col1, const int col2, const int rowCount, int j);
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k, int i, int j);

int main()
{
    srand((unsigned)time(NULL));
    int Low = -34;
    int High = 26;
    int rowCount = 8;
    int colCount = 6;
    int** z = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        z[i] = new int[colCount];
    Create(z, rowCount, colCount, Low, High, 0, 0);
    cout << "Original Matrix:" << endl;
    Print(z, rowCount, colCount, 0, 0);
    Sort(z, rowCount, colCount, 0, 0);
    cout << "Sorted Matrix:" << endl;
    Print(z, rowCount, colCount, 0, 0);
    int S = 0;
    int k = 0;
    Calc(z, rowCount, colCount, S, k, 0, 0);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    cout << "Modified Matrix:" << endl;
    Print(z, rowCount, colCount, 0, 0);
    for (int i = 0; i < rowCount; i++)
        delete[] z[i];
    delete[] z;
    return 0;
}

void Create(int** z, const int rowCount, const int colCount,
    const int Low, const int High, int i, int j)
{
    z[i][j] = Low + rand() % (High - Low + 1);
    if (j < colCount - 1)
        Create(z, rowCount, colCount, Low, High, i, j + 1);
    else if (i < rowCount - 1)
        Create(z, rowCount, colCount, Low, High, i + 1, 0);
}

void Print(int** z, const int rowCount, const int colCount, int i, int j)
{
    cout << setw(4) << z[i][j];
    if (j < colCount - 1)
        Print(z, rowCount, colCount, i, j + 1);
    else if (i < rowCount - 1)
    {
        cout << endl;
        Print(z, rowCount, colCount, i + 1, 0);
    }
    else
        cout << endl << endl;
}

void Sort(int** z, const int rowCount, const int colCount, int i0, int i1)
{
    if (i0 >= colCount - 1)
        return;

    if (i1 < colCount - i0 - 1)
    {
        if ((z[0][i1] < z[0][i1 + 1])
            ||
            (z[0][i1] == z[0][i1 + 1] &&
                z[1][i1] < z[1][i1 + 1])
            ||
            (z[0][i1] == z[0][i1 + 1] &&
                z[1][i1] == z[1][i1 + 1] &&
                z[2][i1] < z[2][i1 + 1]))
            Change(z, i1, i1 + 1, rowCount, 0);

        Sort(z, rowCount, colCount, i0, i1 + 1);
    }
    else
    {
        Sort(z, rowCount, colCount, i0 + 1, 0);
    }
}

void Change(int** z, const int col1, const int col2, const int rowCount, int j = 0)
{
    int tmp;
    if (j < rowCount)
    {
        tmp = z[j][col1];
        z[j][col1] = z[j][col2];
        z[j][col2] = tmp;
        Change(z, col1, col2, rowCount, j + 1);
    }
    return;
}

void Calc(int** z, const int rowCount, const int colCount, int& S, int& k, int i = 0, int j = 0)
{
    if (i >= rowCount)
        return;

    if (j < colCount)
    {
        if (z[i][j] % 2 != 0 || (z[i][j] > 0))
        {
            S += z[i][j];
            k++;
            z[i][j] = 0;
        }
        Calc(z, rowCount, colCount, S, k, i, j + 1);
    }
    else
    {
        Calc(z, rowCount, colCount, S, k, i + 1, 0);
    }
}
