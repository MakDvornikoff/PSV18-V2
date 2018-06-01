
Дворников М.А. PSV18-V2

Курс «Язык программирования C»
Тема : Функции.Перегрузка функций
	Домашнее задание

Задание 1 :
Написать перегруженные функции(int, double, char) для выполнения следующих задач :
 Инициализация квадратной матрицы;
 Вывод матрицы на экран;
 Определение максимального и минимального элемента на главной диагонали матрицы;
 Сортировка элементов по возрастанию отдельно для каждой строки матрицы.

Задание 2:
Написать перегруженные функции и протестировать их в основной программе :
 Нахождения максимального значения в одномерном массиве;
 Нахождения максимального значения в двумерном массиве;
 Нахождения максимального значения в трёхмерном массиве;
 Нахождения максимального значения двух целых;
 Нахождения максимального значения трёх целых;

Задание 3:
Измените программу из первого задания с помощью шаблонов


// ДЗ 1 =================================================
#include <iostream>
#include <time.h>
using namespace std;

#define N 5  //размерность массива

void IniMas(int mas[][N], int n);
void IniMas(double mas[][N], int n);
void IniMas(char mas[][N], int n);

void PrintMas(int mas[][N], int n);
void PrintMas(double mas[][N], int n);
void PrintMas(char mas[][N], int n);

void MaxMinMasDiagonal(int mas[][N], int n);
void MaxMinMasDiagonal(double mas[][N], int n);
void MaxMinMasDiagonal(char mas[][N], int n);

void SortMasUp(int mas[][N], int n);
void SortMasUp(double mas[][N], int n);
void SortMasUp(char mas[][N], int n);



void main()
{
	srand(int(time(NULL)));

	int nMas[N][N];
	double dMas[N][N];
	char cMas[N][N];

	IniMas(nMas, N);
	IniMas(dMas, N);
	IniMas(cMas, N);

	PrintMas(nMas, N);	MaxMinMasDiagonal(nMas, N); 
	PrintMas(dMas, N);	MaxMinMasDiagonal(dMas, N);
	PrintMas(cMas, N);	MaxMinMasDiagonal(cMas, N);

	cout << "\n\nSORT\n\n";

	SortMasUp(nMas, N);
	SortMasUp(dMas, N);
	SortMasUp(cMas, N);

	PrintMas(nMas, N);	MaxMinMasDiagonal(nMas, N);
	PrintMas(dMas, N);	MaxMinMasDiagonal(dMas, N);
	PrintMas(cMas, N);	MaxMinMasDiagonal(cMas, N);

}

void IniMas(int mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas[i][j] = rand() % 21 - 10;
		}
	}
}

void IniMas(double mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas[i][j] = double(rand() % 201) / 10 - 10;
		}
	}
}

void IniMas(char mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			mas[i][j] = rand() % 26 + 65;// Заполняем только A..Z
		}
	}
}

void PrintMas(int mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "  " << mas[i][j] << "\t";
		}
		cout << "\n";
	}
}

void PrintMas(double mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "  " << mas[i][j] << "\t";
		}
		cout << "\n";
	}
}

void PrintMas(char mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "  " << mas[i][j] << "\t";
		}
		cout << "\n";
	}
}

void MaxMinMasDiagonal(int mas[][N], int n)
{
	int min, max;
	min = max = mas[0][0];
	for (int i = 1; i < n; i++)
	{
			if (mas[i][i] < min) min = mas[i][i];
			if (mas[i][i] > max) max = mas[i][i];
	}
	cout << "Min = " << min << "\t Max = " << max << "\n";
}

void MaxMinMasDiagonal(double mas[][N], int n)
{
	double min, max;
	min = max = mas[0][0];
	for (int i = 1; i < n; i++)
	{
			if (mas[i][i] < min) min = mas[i][i];
			if (mas[i][i] > max) max = mas[i][i];
	}
	cout << "Min = " << min << "\t Max = " << max << "\n";
}

void MaxMinMasDiagonal(char mas[][N], int n)
{
	char min, max;
	min = max = mas[0][0];
	for (int i = 1; i < n; i++)
	{
			if (mas[i][i] < min) min = mas[i][i];
			if (mas[i][i] > max) max = mas[i][i];
	}
	cout << "Min = " << min << "\t Max = " << max << "\n";
}

void SortMasUp(int mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int jj = 0; jj < n; jj++)
		{
			for (int j = n - 1; j > jj; j--)
				if (mas[i][j] < mas[i][j - 1])
				{
					int tmp = mas[i][j];
					mas[i][j] = mas[i][j - 1];
					mas[i][j - 1] = tmp;
				}

		}
	}
}

void SortMasUp(double mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int jj = 0; jj < n; jj++)
		{
			for (int j = n - 1; j > jj; j--)
				if (mas[i][j] < mas[i][j - 1])
				{
					double tmp = mas[i][j];
					mas[i][j] = mas[i][j - 1];
					mas[i][j - 1] = tmp;
				}
		}
	}
}

void SortMasUp(char mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int jj = 0; jj < n; jj++)
		{
			for (int j = n - 1; j>jj; j--)
				if (mas[i][j] < mas[i][j - 1])
				{
					char tmp = mas[i][j];
					mas[i][j] = mas[i][j - 1];
					mas[i][j - 1] = tmp;
				}

		}
	}
}

// ДЗ 2 =================================================
#include <iostream>
#include <time.h>
using namespace std;

#define X 3  //размерность массива
#define Y 4  //размерность массива
#define Z 5  //размерность массива

inline int IniN(void) { return rand() % 21 - 10; }

void IniMas(int mas[], int z) { for (int i = 0; i < z; i++) mas[i] = IniN(); }
void IniMas(int mas[][Z], int y, int z) { for (int i = 0; i < y; i++) IniMas(mas[i], z); }
void IniMas(int mas[][Y][Z], int x, int y, int z) { for (int i = 0; i < x; i++) IniMas(mas[i], y, z); }

void PrintMas(int mas[], int z) { for (int i = 0; i < z; i++) cout << "  " << mas[i] << "\t"; cout << "\n"; }
void PrintMas(int mas[][Z], int y, int z) { cout << "\n"; for (int i = 0; i < y; i++) PrintMas(mas[i], z);  }
void PrintMas(int mas[][Y][Z], int x, int y, int z) { cout << "\n"; for (int i = 0; i < x; i++) PrintMas(mas[i], y, z);  }

int Max(int a, int b) { return (a > b) ? a : b; }
int Max(int a, int b, int c) { return (a > Max(b, c)) ? a : Max(b, c); };
int Max(int mas[], int z);
int Max(int mas[][Z], int x, int y);
int Max(int mas[][Y][Z], int x, int y, int z);


void main()
{
	srand(int(time(NULL)));	
	
	int a = IniN(), b = IniN(), c = IniN();
	cout << "A = " << a << "\tB = " << b << "\tC = " << c << "\n";
	cout << "Max A, B = " << Max(a, b) << "\tMax A, B, C = " << Max(a, b, c) << "\n\n";

	int mas1[Z], mas2[Y][Z], mas3[X][Y][Z];
	IniMas(mas1, Z); IniMas(mas2, Y, Z); IniMas(mas3, X, Y, Z);
	PrintMas(mas1, Z); cout << "Max MASS [] = " << Max(mas1, Z)<<"\n\n";
	PrintMas(mas2, Y, Z); cout << "Max MASS [][] = " << Max(mas2, Y, Z) << "\n\n";
	PrintMas(mas3, X, Y, Z); cout << "Max MASS [][][] = " << Max(mas3, X, Y, Z) << "\n\n";
}

int Max(int mas[], int z)
{
	int max = mas[0];
	for (int i = 1; i < z; i++)
		if (mas[i] > max) max = mas[i];
	return max;
}

int Max(int mas[][Z], int y, int z)
{
	int max = Max(mas[0],z);	
	for (int i = 1; i < y; i++)
	{
		int maxCurrent = Max(mas[i], z);
		if (maxCurrent > max) max = maxCurrent;
	}
	return max;
}

int Max(int mas[][Y][Z], int x, int y, int z)
{
	int max = Max(mas[0], y, z);
	for (int i = 1; i < x; i++)
	{
		int maxCurrent = Max(mas[i], y, z);
		if (maxCurrent > max) max = maxCurrent;
	}
	return max;
}



// ДЗ 3 =================================================

#include <iostream>
#include <time.h>
using namespace std;

#define N 5  //размерность массива

template <typename T> void IniMas(T mas[][N], int n);
template <typename T> void PrintMas(T mas[][N], int n);
template <typename T> void MaxMinMasDiagonal(T mas[][N], int n);
template <typename T> void SortMasUp(T mas[][N], int n);

void main()
{
	srand(int(time(NULL)));

	int nMas[N][N];
	double dMas[N][N];
	char cMas[N][N];

	IniMas(nMas, N);
	IniMas(dMas, N);
	IniMas(cMas, N);

	PrintMas(nMas, N);	MaxMinMasDiagonal(nMas, N); 
	PrintMas(dMas, N);	MaxMinMasDiagonal(dMas, N);
	PrintMas(cMas, N);	MaxMinMasDiagonal(cMas, N);

	cout << "\n\nSORT\n\n";

	SortMasUp(nMas, N);
	SortMasUp(dMas, N);
	SortMasUp(cMas, N);

	PrintMas(nMas, N);	MaxMinMasDiagonal(nMas, N);
	PrintMas(dMas, N);	MaxMinMasDiagonal(dMas, N);
	PrintMas(cMas, N);	MaxMinMasDiagonal(cMas, N);

}

template <typename T> void IniMas(T mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{			
			if (std::is_same<T, char>::value) mas[i][j] = rand() % 26 + 65; // Заполняем только A..Z
			else
				mas[i][j] = T(rand() % 201) / 10 - 10;
		}
	}
}

template <typename T> void PrintMas(T mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "  " << mas[i][j] << "\t";
		}
		cout << "\n";
	}
}

template <typename T> void MaxMinMasDiagonal(T mas[][N], int n)
{
	T min, max;
	min = max = mas[0][0];
	for (int i = 1; i < n; i++)
	{
			if (mas[i][i] < min) min = mas[i][i];
			if (mas[i][i] > max) max = mas[i][i];
	}
	cout << "Min = " << min << "\t Max = " << max << "\n";
}

template <typename T> void SortMasUp(T mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int jj = 0; jj < n; jj++)
		{
			for (int j = n - 1; j > jj; j--)
				if (mas[i][j] < mas[i][j - 1])
				{
					T tmp = mas[i][j];
					mas[i][j] = mas[i][j - 1];
					mas[i][j - 1] = tmp;
				}

		}
	}
}

