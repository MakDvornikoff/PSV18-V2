
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

void main();

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
			mas[i][j] = (rand() % 25) + 65;
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

#define N 5  //размерность массива

void main();

template <typename T> void IniMas(T mas[][N], int n);


void PrintMas(int mas[][N], int n);
void PrintMas(double mas[][N], int n);
void PrintMas(char mas[][N], int n);

void MaxMinMas(int mas[][N], int n);
void MaxMinMas(double mas[][N], int n);
void MaxMinMas(char mas[][N], int n);

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

	PrintMas(nMas, N);
	PrintMas(dMas, N);
	PrintMas(cMas, N);

	MaxMinMas(nMas, N);
	MaxMinMas(dMas, N);
	MaxMinMas(cMas, N);

	SortMasUp(nMas, N);
	SortMasUp(dMas, N);
	SortMasUp(cMas, N);

	PrintMas(nMas, N);
	PrintMas(dMas, N);
	PrintMas(cMas, N);

}

template <typename T> void IniMas(T mas[][N], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			if (T is char) { mas[i][j] = T(rand() % 25) + 65; } //заполняем только прописными английскими буквами
			else 
				mas[i][j] = T(rand() % 201) / 10 - 10;
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

void MaxMinMas(int mas[][N], int n)
{
	int min, max;
	min = max = mas[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[i][j] < min) min = mas[i][j];
			if (mas[i][j] > max) max = mas[i][j];
		}
	}
	cout << "Min = " << min << "\t Max = " << max << "\n";
}

void MaxMinMas(double mas[][N], int n)
{
	double min, max;
	min = max = mas[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[i][j] < min) min = mas[i][j];
			if (mas[i][j] > max) max = mas[i][j];
		}
	}
	cout << "Min = " << min << "\t Max = " << max << "\n";
}

void MaxMinMas(char mas[][N], int n)
{
	char min, max;
	min = max = mas[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mas[i][j] < min) min = mas[i][j];
			if (mas[i][j] > max) max = mas[i][j];
		}
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
			if (std::is_same<T, char>::value) mas[i][j] = (rand() % 25) + 65; // Заполняем только A..Z
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

