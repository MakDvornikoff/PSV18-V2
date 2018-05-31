
Дворников М.А. PSV18-V2

Курс «Язык программирования C»
Тема: Сортировка массивов

Домашнее задание

Задание №1:
Написать программу, выполняющую сортировку одномерного массива целых чисел методом пузырьковой сортировки.

Задание №2.
Написать программу, выполняющую сортировку одномерного массива целых чисел методом вставок.

Задание №3.
Написать программу «успеваемость». Пользователь вводит 10 оценок студента. Реализовать меню для пользователя
 Вывод оценок (вывод содержимого массива)
 Пересдача экзамена (пользователь вводит номер элемента массива и новую оценку)
 Выходит ли стипендия (стипендия выходит, если средний бал не ниже 10.7)

Задание №4.
Необходимо отсортировать первые две трети массива в порядке возрастания, если среднее арифметическое всех элементов больше нуля; иначе - лишь первую треть. Остальную часть массива не сортировать, а расположить в обратном порядке.


// ДЗ 1 =================================================
#include <iostream>
#include <time.h>
using namespace std;

#define N 5  //размерность массива

void IniMas(int mas[], int n);
void PrintMas(int mas[], int n);
void SortMasBubbleUp(int mas[], int n); //ДЗ 1
void SortMasInsertUp(int mas[], int n); //ДЗ 2

void main()
{
	srand(int(time(NULL)));

	int Mas[N];

	cout << "\n\nSORT BUBBLE\n\n";
	IniMas(Mas, N);
	PrintMas(Mas, N);	
	SortMasBubbleUp(Mas, N);
	PrintMas(Mas, N);	
	
	cout << "\n\nSORT INSERT\n\n";
	IniMas(Mas, N);
	PrintMas(Mas, N);
	SortMasInsertUp(Mas, N);
	PrintMas(Mas, N);
}

void IniMas(int mas[], int n)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 21 - 10;
	}
}

void PrintMas(int mas[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "  " << mas[i] << "\t";
	}
	cout << "\n";
}

void SortMasBubbleUp(int mas[], int n) //ДЗ 1
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j > i; j--)
			if (mas[j] < mas[j - 1])
			{
				int tmp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = tmp;
			}
	}
}

void SortMasInsertUp(int mas[], int n) //ДЗ 2
{
	for (int i = 1; i < n; i++)
	{
		int j = i;
		int tmp = mas[i];
		while (j > 0 && tmp < mas[j - 1])
		{
			mas[j] = mas[j - 1];
			j--;
		}
		mas[j] = tmp;
	}
}


// ДЗ 2 =================================================
ДЗ 2  находится внутри ДЗ 1

// ДЗ 3 =================================================

// ДЗ 4 =================================================
