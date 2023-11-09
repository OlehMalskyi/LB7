#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** z, const int rowCount, const int colCount, const int Low,
void Print(int** z, const int rowCount, const int colCount);
void Sort(int** z, const int rowCount, const int colCount);
void Change(int** z, const int row1, const int row2, const int colCount);
void Calc(int** z, const int rowCount, const int colCount, int& S, int& k);

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
	Create(z, rowCount, colCount, Low, High);
	Sort(z, rowCount, colCount);
	int S = 0;
	Calc(z, rowCount, colCount, S, k);
	cout << "k = " << k << endl;
	for (int i = 0; i < rowCount; i++)
		delete[] z[i];
	delete[] z;
	return 0;
}

void Create(int** z, const int rowCount, const int colCount, const int Low,
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			z[i][j] = Low + rand() % (High - Low + 1);

void Print(int** z, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << z[i][j];
	}
	cout << endl;

void Sort(int** z, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < colCount - 1; i0++)
		for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
			if ((z[0][i1] < z[0][i1 + 1])
				||
				(z[0][i1] == z[0][i1 + 1] &&
					z[1][i1] < z[1][i1 + 1])
				||
				(z[0][i1] == z[0][i1 + 1] &&
					z[1][i1] == z[1][i1 + 1] &&
					z[2][i1] < z[2][i1 + 1]))
}

void Change(int** z, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int j = 0; j < rowCount; j++)
	{
		tmp = z[j][col1];
	}

void Calc(int** z, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (z[i][j] % 2 != 0 || (z[i][j] > 0))
				S += z[i][j];
			}