
Дворников М.А. PSV18-V2

Тема: Массивы одномерные
Домашнее задание
Задание 1: В одномерном массиве, заполненном случайными числами, определить минимальный и максимальный элементы.
Задание 2: Пользователь вводит прибыль фирмы за год (12 месяцев). Затем пользователь вводит диапазон (например, 3 и 6 – поиск между 3-м и 6-м месяцем). Необходимо определить месяц, в котором прибыль была максимальна и месяц, в котором прибыль была минимальна с учетом выбранного диапазона.
Задание 3: В одномерном массиве, состоящем из N вещественных чисел вычислить:
• Сумму отрицательных элементов.
• Произведение элементов, находящихся между min и max элементами.
• Произведение элементов с четными номерами.
• Сумму элементов, находящихся между первым и последним отрицательными элементами.
Задание 4:Написать программу, копирующую последовательно элементы одного массива размером 10 элементов в 2 массива размером 5 элементов каждый.
Задание 5:Напишите программу, которая выполняет поэлементную сумму двух массивов и результат заносит в третий массив.


// ДЗ 1 =================================================
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUSSIAN");

	const int  DiapazonRnd = 101; // максимальное значение для генерации Rand()
	const int n = 10;//размер  массива
	int arr[n];

	//заполнение массива RND
	for (int i = 0; i < n; i++) arr[i] = rand() % DiapazonRnd;

	int max, min;
	max = min = arr[0];
	for (int i = 1; i < n; i++) 
	{
		cout << arr[i] << " | ";
		if (min > arr[i]) min = arr[i];
		if (max < arr[i]) max = arr[i];
	}

	cout << "\nMin = " << min << "\nMax = " << max << "\n\n";
}
// ДЗ 2 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{

	setlocale(LC_ALL, "RUSSIAN");

	const int n = 12;//размер  массива. обязательно нечетное число >0
	double arr[n];

	//заполнение массива
	cout << "Введите прибыль по месяцам :\n";
	for (int i = 0; i < n; i++)
	{
		cout << "Месяц " << i + 1 << " >";
		cin>>arr[i];
	}
	cout << "\nВведите начальный месяц диапазона >";
	int s; cin >> s;
	cout << "\nВведите конечный месяц диапазона >" ;
	int e; cin >> e;

	int max, min;
	max = min = s;
	for (int i = s-1; i < e; i++)
	{		
		if (arr[min] > arr[i]) min = i;
		if (arr[max] < arr[i]) max = i;
	}
	min++; max++;
	cout << "\nМинимальная прибыль в месяце - " << min << "\nМаксимальная прибыль в месяце - " << max << "\n\n";
}
// ДЗ 3 =================================================
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUSSIAN");

	const int  Ra = -100; // A*10 для формулы генерации Rand()
	const int  Rb = 100; // B*10 для формулы генерации Rand()
	const int n = 10;//размер  массива
	double arr[n];

	//заполнение массива RND
	for (int i = 0; i < n; i++)
	{
		arr[i] = (Ra + rand() % (Rb - Ra + 1)) / 10; // делим на 10 для генерации вещественных чисел
		cout << arr[i] << " | "; //Выводим на экран массив
	}



	//Сумма отрицательных элементов
	{
		double res = 0;
		for (int i = 0; i < n; i++)	if (arr[i] < 0) res += arr[i];
		cout << "\n\nСумма отрицательных элементов = " << res;
	}

	//Произведение элементов Между min и max элементами, Исключая элементы с номерами min и max
	{
		double res = 1;
		int max, min,t;
		max = min = 0;
		for (int i = 1; i < n; i++)
		{
			if (arr[min] > arr[i]) min = i;
			if (arr[max] < arr[i]) max = i;
		}
		if (min > max) { t = min; min = max; max = t; }
		for (int i = min+1; i < max; i++) res *= arr[i];
		cout << "\nПроизведение элементов между min и max элементами = " << res;
	}

	//Произведение элементов с чётными номерами
	{
		double res = 1;
		for (int i = 1; i < n; i++, i++) res *= arr[i];
		cout << "\nПроизведение элементов с чётными номерами = " << res;
	}

	//Сумма элементов Между первым и последним отрицательным элементом, Исключая первый и последний отрицательный элемент
	{
		double res = 0;
		int first=-1, last=-1,i;
		i = 0;
		for ( i = 1; i < n; i++) if (arr[i] < 0) break;
		first = i;
		i = 0;
		for (i = n-1; i >= 0; i--) if (arr[i] < 0) break;
		last = i;

		if (first==-1 && last==-1)	cout << "В массиве нет отрицательных элементов";
		else {
			if (first < last)
			{
				for (i = first + 1; i < last; i++) res += arr[i];
				cout << "\nСумма элементов между первым и последним отрицательным элементом = " << res;
			}
			else cout << "\nВ массиве только один отрицательный элемент...";
		}
	}
	cout << "\n\n";
}
// ДЗ 4 =================================================
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUSSIAN");

	const int  r = 20; // максимальное значение для генерации Rand() -10..10
	const int n = 10;//размер  массива
	int arr[n];
	int a[n / 2], b[n / 2];

	//заполнение массива RND
	for (int i = 0; i < n; i++) arr[i] = -r / 2 + rand() % (r + 1);

	//Заполнение двух массивов
	for (int i = 0; i < n; i++)
	{
		if (i < (n / 2)) a[i] = arr[i];
		else b[i - n / 2] = arr[i];
	}

	//Вывод на экран всех массивов
	for (int i = 0; i < n; i++) cout << arr[i] << " | ";
	cout << "\n\n";
	for (int i = 0; i < n/2; i++) cout << a[i] << " | ";
	cout << "\n\n";
	for (int i = 0; i < n / 2; i++) cout << b[i] << " | ";
	cout << "\n\n";
}
// ДЗ 5 =================================================
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUSSIAN");

	const int  r = 20; // максимальное значение для генерации Rand() -10..10
	const int n = 10;//размер  массива
	int a[n], b[n];
	int sum[n];

	//заполнение массива RND
	for (int i = 0; i < n; i++)
	{
		a[i] = -r / 2 + rand() % (r + 1);
		b[i] = -r / 2 + rand() % (r + 1);
	}

	//Суммирование
	for (int i = 0; i < n; i++) sum[i] = a[i] + b[i];

	//Вывод на экран всех массивов
	for (int i = 0; i < n; i++) cout << a[i] << " | ";
	cout << "\n\n";
	for (int i = 0; i < n; i++) cout << b[i] << " | ";
	cout << "\n\n";
	for (int i = 0; i < n; i++) cout << sum[i] << " | ";
	cout << "\n\n";
}
