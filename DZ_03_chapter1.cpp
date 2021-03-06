﻿
Дворников М.А. PSV18-V2

Курс «Язык программирования C»
Тема: Циклы
Домашнее задание
Задание 1. Вывести на экран фигуры заполненные звездочками. Диалог с пользователем реализовать при помощи меню.
Задание 2: Подсчитать количество целых чисел в диапазоне от 100 до 999 у которых есть две одинаковые цифры
Задание 3: Подсчитать количество целых чисел в диапазоне от 100 до 999 у которых все цифры разные
Задание 4: Пользователь вводит любое целое число. Необходимо из этого целого числа удалить все цифры 3 и 6 и вывести обратно на экран.
Задание 5: Пользователь вводит любое целое число А. Необходимо вывести все целые числа В, для которых А делиться без остатка на В*В и не делиться без остатка на В*В*В
Задание 6: Пользователь вводит целое число А. Программа должна определить, что куб суммы цифр этого числа равен А*А
Задание 7: Пользователь вводит целое число. Необходимо вывести все целые числа, на которое заданное число делиться без остатка.
Задание 8: Пользователь вводит два целых числа. Необходимо вывести все целые числа, на которые оба введенных числа делятся без остатка.
Задание 9: Пользователь вводит число. Определить количество цифр в этом числе, посчитать их сумму и среднее арифметическое. Определить количество нулей в этом числе. Общение с пользователем организовать через меню.
Задание 10: Написать программу, которая выводит на экран шахматную доску с заданным размером клеточки. Например,
***---***---***---***--- 
***---***---***---***--- 
***---***---***---***--- 
---***---***---***---*** 
---***---***---***---*** 
---***---***---***---***


// ДЗ 1 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	// для вариантов используем кодировку в двоичном виде.квадрат представляет из себя 4 закрашенных сектора.сектор - есть треугольник.
	// для варианта "в" закрашен верхний треугольник, для "г" закрашен нижний треугольник, для "ж" левый, для "з" правый. 
	// для каждого варианта выделено по одному биту. Начало - верхний треугольник. Ему соответствует бит "0". далее по часовой стрелке,
	// так, что 3 бит соответствует левому треугольнику и варианту "ж".
	// создаём массив с содержанием закрашенных треугольников.	
	char const CountVariants = 10; //число вариантов                    
	char Variant[CountVariants]{  //массив с кодировками вариантов      
		0b0011, // Вариант "а"
		0b1100, // Вариант "б"
		0b0001, // Вариант "в"
		0b0100, // Вариант "г"
		0b0101, // Вариант "д"
		0b1010, // Вариант "е"
		0b1000, // Вариант "ж"
		0b0010, // Вариант "з"
		0b1001, // Вариант "и"
		0b0110  // Вариант "й" (в задании "к"), т.к. привязываю к последовательности ASCII кодов
	};
	const int n = 5;//размер квадратного массива. обязательно нечетное число >0

	while (1)
	{
		// ================= МЕНЮ ==================
		cout << "Выберите вариант (цифру):\n";
		for (int i = 0; i< CountVariants; i++) cout << "Вариант '" << (char)(i + 224) << "'  (" << i + 1 << ")\n";
		cout << "Выход        (0)\n------------->";
		int var;  cin >> var;
		if (var < 1 || var>10) break;
		--var;

		//=======Вывод на экран и обработка ========
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (((j>i - 1 && j<n - i)     && (Variant[var] & 0b0001)) ||		// верхний треугольник
					((j>i - 1 && j>n - i - 2) && (Variant[var] & 0b0010)) ||		// правый треугольник		
					((j<i + 1 && j>n - i - 2) && (Variant[var] & 0b0100)) ||		// нижний треугольник
					((j<i + 1 && j<n - i)     && (Variant[var] & 0b1000)))	    	// левый треугольник
					cout << "*";
				else cout << " ";
			}
			cout << "\n";
		}
	}
}


// ДЗ 2 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int n = 0;
	for (int i = 100; i < 1000; i++)
	{
		int a, b, c;
		a = i % 10; b = i / 10 % 10; c = i / 100 % 10;
		if (a == b || b == c || a == c) ++n	;
	}
	cout << n << "\n";
}

// ДЗ 3 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int n = 0;
	for (int i = 100; i < 1000; i++)
	{
		int a, b, c;
		a = i % 10; b = i / 10 % 10; c = i / 100 % 10;
		if (a != b  && b != c && a != c) ++n	;
	}
	cout << n << "\n";
}
// ДЗ 4 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int n, t = 0;
	cout << "Введите целое число: >";
	cin >> n;
	while (n)
	{
		int d = n % 10;
		if (d != 3 && d != 6) t = t * 10 + d;
		n /= 10;
	}
	while (t)
	{
		cout << t % 10 ;
		t /= 10;
	}
	cout << "\n";
}
// ДЗ 5 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int a;
	cout << "Введите целое число: >";
	cin >> a;
	for (int b = 1; b <= sqrt(a); b++)
	{
		if ((a % (b*b) == 0) && (a%(b*b*b) != 0)) cout << b << "\n";
	}
}
// ДЗ 6 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int a, t, sum = 0;
	cout << "Введите целое число: >";
	cin >> a;
	t = a;
	while (t)
	{
		sum += t % 10; t /= 10;
	}
	if (sum*sum*sum == a*a) cout << "То самое число!\n"; else cout << "Не угадал!\n";
}
// ДЗ 7 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int a;
	cout << "Введите целое число: >";
	cin >> a;
	for (int i = 1; i <= a / 2; i++)
		if (a%i == 0) cout << i << "\n";
}
// ДЗ 8 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int a,b;
	cout << "Введите 2 целых числа: >\n";
	cin >> a; cin >> b;
	int t;
	if (a > b) { t = a; a = b; b = t; }
	for (int i = 1; i <= a / 2; i++)
		if (a%i == 0 && b%i==0) cout << i << "\n";
}
// ДЗ 9 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	while (1)
	{
		// ================= МЕНЮ ==================
		cout << "Выберите вариант :\n";
		cout << " 1 - количество цифр\n";
		cout << " 2 - сумма цифр\n";
		cout << " 3 - среднее арифметическое цифр\n";
		cout << " 4 - количество нулей\n";
		cout << " 0 - Выход\n>";
		int var;  cin >> var;
		if (var < 1 || var>4) break;
		cout << "Введите число >";
		int n;
		cin >> n;

		double x = 0; // результат для любого пункта меню
		switch (var)
		{
		case 1:
		{
			while (n) { ++x; n /= 10; }
			break;
		}
		case 2:
		{
			while (n) { x += n % 10; n /= 10; }
			break;
		}
		case 3:
		{
			int count = 0;
			while (n) { x += n % 10; ++count; n /= 10; }
			if (count) x /= count;
			break;
		}
		case 4:
		{
			if (n)
			while (n) { if (n % 10 == 0) ++x; n /= 10; }
			else x = 1;					// если ввели "0", то количество нулей = 1
			break;
		}
		}
		cout << "Результат = " << x<<"\n\n";
	}
}
// ДЗ 10 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	const int SizeDesk = 8;
	const int SizeCell = 3;

	for (int i = 0; i < SizeDesk; i++)
	{
		for (int cy = 0; cy < SizeCell; cy++)
		{
			for (int j = 0; j < SizeDesk; j++)
			{
				for (int cx = 0; cx < SizeCell; cx++)
				{
					if ((j % 2 == 0 && i % 2 == 0)|| (j % 2 != 0 && i % 2 != 0))cout << "*"; else cout << "-";
				}
				
			}
			cout << "\n";
		}
	}
}
