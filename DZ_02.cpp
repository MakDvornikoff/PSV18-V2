Домашнее задание № 2

Курс «Язык программирования C»
Тема : Циклы
	Домашнее задание
	Задание 1. Напишите программу, которая вычисляет сумму целых чисел от а до 500 (значение a
		вводится с клавиатуры).
	Задание 2. Напишите программу, которая запрашивает два целых числа x и y, после чего
	вычисляет и выводит значение x в степени y.
	Задание 3. Найти среднее арифметическое всех целых чисел от 1 до 1000.
	Задание 4. Найти произведение всех целых чисел от a до 20 (значение a вводится с клавиатуры :
1 <= a <= 20).
Задание 5. Написать программу, которая выводит на экран таблицу умножения на k, где k –
номер варианта.Например, для 7 - го варианта :
7 x 2 = 14
7 x 3 = 21
Задание 6. Вывести на экран все числа от нуля до введенного пользователем числа.
Задание 7. Пользователь вводит две границы диапазона, вывести на экран все числа из этого
диапазона.Предусмотреть, чтобы пользователь мог вводить границы диапазона в произвольном
порядке.
вывести все четные числа из диапазона.
вывести все нечетные числа из диапазона.
вывести все числа, кратные семи.
Задание 8. Пользователь вводит две границы диапазона.Посчитать сумму всех чисел
диапазона.
Задание 9. Пользователь с клавиатуры вводит числа.Посчитать их сумму и вывести на экран,
как только пользователь введет ноль.


ДЗ 1 == == == == == == == == == == == == == == == == == == == == == == == == ==

#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	int a;
	double sum = 0;
	cout << "Enter the <a> = ";
	cin >> a;

	for (; a <= 500; a++) sum += a;

	cout << "Summa = " << sum << "\n";
}




ДЗ 2 == == == == == == == == == == == == == == == == == == == == == == == == ==

#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	int x, y;

	cout << "Enter the <X> = ";
	cin >> x;
	cout << "Enter the <Y> = ";
	cin >> y;

	double z = 1;
	for (int i = 1; i <= abs(y); i++)
	{
		if (y < 0) z /= x; else z *= x;
	}

	cout << "X^Y = " << z << "\n";
}




ДЗ 3 == == == == == == == == == == == == == == == == == == == == == == == == ==

#include <iostream>
#include <math.h>
using namespace std;

void main()
{

	double z = 0;
	for (int i = 1; i <= 1000; z += i++); // операция сложения и инкремента одновременно внутри инициализации цикла.

	z /= 1000;

	cout << "Srednee arifmeticheskoe = " << z << "\n";
}

ДЗ 4 == == == == == == == == == == == == == == == == == == == == == == == == ==

#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	int a;
	double rez = 1;
	bool flag;
	do
	{
		cout << "Enter the <a> 1..20 = ";
		cin >> a;
		if ((a <= 20) && (a >= 1)) flag = 0;
		else
		{
			flag = true;
			cout << "Ne pravilno vveli <a>\n\n";
		}
	} while (flag);

	for (; a <= 20; a++)
	{
		rez *= a;
	}
	cout << "Proizvedenie = " << rez << "\n";
}

ДЗ 5 == == == == == == == == == == == == == == == == == == == == == == == == ==

#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	int k;
	bool flag;
	do
	{
		cout << "Enter the <K> 1..10 = ";
		cin >> k;
		if ((k <= 10) && (k >= 1)) flag = 0;
		else
		{
			flag = true;
			cout << "Ne pravilno vveli <k>\n\n";
		}
	} while (flag);

	for (int i = 1; i <= 10; i++)  cout << k << " x " << i << " = " << k*i << "\n";

}


ДЗ 6 == == == == == == == == == == == == == == == == == == == == == == == == ==

#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	int a;
	cout << "Enter the <a> = ";
	cin >> a;

	for (int i = 0; i <= a; i++) cout << i << "\n";

}

ДЗ 7 == == == == == == == == == == == == == == == == == == == == == == == == ==

#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	int a, b, c;

	cout << "Enter the <a> = ";
	cin >> a;
	cout << "Enter the <b> = ";
	cin >> b;

	if (a > b) { c = a; a = b; b = c; }

	cout << "\nVse chisla iz diapazona\n";
	for (c = a; c <= b; c++) cout << c << "\n";

	cout << "\nChetnie chisla\n";
	for (c = a; c <= b; c++) if ((c % 2) == 0) cout << c << "\n";

	cout << "\nNEChetnie chisla\n";
	for (c = a; c <= b; c++) if ((c % 2) != 0) cout << c << "\n";

	cout << "\nKratnie 7 chisla\n";
	for (c = a; c <= b; c++) if ((c % 7) == 0) cout << c << "\n";
}


ДЗ 8 == == == == == == == == == == == == == == == == == == == == == == == == ==

#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	int a, b, c;
	double sum = 0;

	cout << "Enter the <a> = ";
	cin >> a;
	cout << "Enter the <b> = ";
	cin >> b;

	if (a > b) { c = a; a = b; b = c; }

	for (c = a; c <= b; c++) sum += c;

	cout << "\nSumma = " << sum << "\n";

}

ДЗ 9 == == == == == == == == == == == == == == == == == == == == == == == == ==

﻿#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	int a;
	double sum = 0;

	do
	{
		cout << "Vvedite chislo = ";
		cin >> a;
		sum += a;
	} while (a != 0);

	cout << "Summa = " << sum << "\n";
}



