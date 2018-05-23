
Дворников М.А. PSV18-V2

Курс «Язык программирования C»
Тема : Многомерные массивы
	Домашнее задание
	Задание 1 :	Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу : пользователь вводит число(например, 3) первый элемент массива принимает значение этого числа, последующий элемент массива принимает значение этого числа умноженного на 2 (т.е. 6 для нашего примера), третий элемент массива предыдущий элемент, умноженный на 2 (т.е. 6 * 2 = 12 для нашего примера).Созданный массив вывести на экран.
	Задание 2 :	Напишите программу, которая создает двухмерный массив и заполняет его по следующему принципу : пользователь вводит число(например, 3) первый элемент массива принимает значение этого числа, последующий элемент массива принимает значение этого числа + 1 (т.е. 4 для нашего примера), третий элемент массива предыдущий элемент + 1 (т.е. 5 для нашего примера).Созданный массив вывести на экран.
	Задание 3 :	Создайте двухмерный массив.Заполните его случайными числами и покажите на экран.Пользователь выбирает количество сдвигов и положение(влево, вправо, вверх, вниз).Выполнить сдвиг массива и показать на экран полученный результат.Сдвиг циклический.
	Например, если мы имеем следующий массив
	1 2 0 4 5 3
	4 5 3 9 0 1
	и пользователь выбрал сдвиг на 2 разряда вправо, то мы получим
	5 3 1 2 0 4
	0 1 4 5 3 9
	Задание 4:В двумерном массиве целых числе посчитать :
		 Сумму всех элементов массива
		 Среднее арифметическое всех элементов массива
		 Минимальный элемент
		 Максимальный элемент
Задание 5 :	В двумерном массиве целых чисел посчитать сумму элементов : в каждой строке; в каждом столбце; одновременно по всем строкам и всем столбцам.Оформить следующим образом :
3 5 6 7 | 21
12 1 1 1 | 15
0 7 12 1 | 20
-------------------- -
15 3 19 9 | 56
Задание 6:Напишите программу, в которой объявляется массив размером 5х10 и массив размером 5х5.Первый массив заполняется случайными числами, в диапазоне от 0 до 50. Второй массив заполняется по следующему принципу : первый элемент второго массива равен сумме первого и второго элемента первого массива, второй элемент второго массива равен сумму третьего и четвертого элемента первого массива.




// ДЗ 1 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	cout << "Введите значение первого элемента массива >";
	float a;
	cin >> a;

	const int n = 4;//размерность  массива n*n
	int arr[n][n];

	//заполнение массива 
	for (int i = 0; i < n*n; i++, a *= 2) arr[0][i] = a;

	//вывод на экран
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t | \t";
		}
		cout << "\n";
	}
}


// ДЗ 2 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	cout << "Введите значение первого элемента массива >";
	int a;
	cin >> a;

	const int n = 4;//размерность  массива n*n
	int arr[n][n];

	//заполнение массива 
	for (int i = 0; i < n*n; i++, a++) arr[0][i] = a;

	//вывод на экран
	cout << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << "\t | \t";
		}
		cout << "\n";
	}
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

	const int  DiapazonRnd = 10; // максимальное значение для генерации Rand() 
	const int CountRow = 6;//размер  массива - количество строк
	const int CountCol = 4;//размер  массива - количество столбцов
	int arr[CountRow][CountCol];

	//заполнение массива RND
	for (int i = 0; i < CountRow*CountCol; i++) arr[0][i] = rand() % DiapazonRnd;

	//вывод на экран
	cout << "\n";
	for (int i = 0; i < CountRow; i++)
	{
		for (int j = 0; j < CountCol; j++)
		{
			cout << arr[i][j] << "\t | \t";
		}
		cout << "\n";
	}

	while (1)
	{
		cout << "Введите количество сдвигов (<0> выход)";
		int Offset; cin >> Offset;
		if (!Offset) break;
		cout << "Выберите направление (<U> Up / <D> Down / <L> Left / <R> Right)";
		char Direct; cin >> Direct;


		switch (Direct)

		{
			// ===========UP===============
		case 'U', 'u':
		{
			Offset %= CountRow;
			if (!Offset) break;
			for (int j = 0; j < CountCol; j++)
			{
				for (int of = 0; of < Offset; of++)
				{
					int temp = arr[0][j];
					for (int i = 0; i < CountRow - 1; i++)
					{
						arr[i][j] = arr[i + 1][j];
					}
					arr[CountRow - 1][j] = temp;
				}
			}
			break;
		}

		// ===========DOWN===============
		case 'D', 'd':
		{
			Offset %= CountRow;
			if (!Offset) break;
			for (int j = 0; j < CountCol; j++)
			{
				for (int of = 0; of < Offset; of++)
				{
					int temp = arr[CountRow - 1][j];
					for (int i = CountRow - 1; i > 0; i--)
					{
						arr[i][j] = arr[i - 1][j];
					}
					arr[0][j] = temp;
				}
			}
			break;
		}

		// ===========LEFT===============
		case 'L', 'l':
		{
			Offset %= CountCol;
			if (!Offset) break;
			for (int i = 0; i < CountRow; i++)
			{
				for (int of = 0; of < Offset; of++)
				{
					int temp = arr[i][0];
					for (int j = 0; j < CountCol - 1; j++)
					{
						arr[i][j] = arr[i][j + 1];
					}
					arr[i][CountCol - 1] = temp;
				}
			}
			break;
		}

		// ===========RIGHT===============
		case 'R', 'r':
		{
			Offset %= CountCol;
			if (!Offset) break;
			for (int i = 0; i < CountRow; i++)
			{
				for (int of = 0; of < Offset; of++)
				{
					int temp = arr[i][CountCol - 1];
					for (int j = CountCol - 1; j >0; j--)
					{
						arr[i][j] = arr[i][j - 1];
					}
					arr[i][0] = temp;
				}
			}
			break;
		}

		}





		//вывод на экран
		cout << "\n";
		for (int i = 0; i < CountRow; i++)
		{
			for (int j = 0; j < CountCol; j++)
			{
				cout << arr[i][j] << "\t | \t";
			}
			cout << "\n";
		}
		cout << "\n\n";

	}
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

	const int  DiapazonRnd = 10; // максимальное значение для генерации Rand() 
	const int CountRow = 4;//размер  массива - количество строк
	const int CountCol = 4;//размер  массива - количество столбцов
	int arr[CountRow][CountCol];

	//заполнение массива RND
	for (int i = 0; i < CountRow*CountCol; i++) arr[0][i] = rand() % DiapazonRnd;

	//вывод на экран
	cout << "\n";
	for (int i = 0; i < CountRow; i++)
	{
		for (int j = 0; j < CountCol; j++)
		{
			cout << arr[i][j] << "\t | \t";
		}
		cout << "\n";
	}

	//===================Вычисления=============
	int sum = 0;
	for (int i = 0; i < CountRow*CountCol; i++) sum += arr[0][i];
	cout << "\n\n Сумма всех элементов = " << sum;
	cout << "\n Среднее арифметическое = " << sum / CountRow / CountCol;

	int min = arr[0][0];
	for (int i = 0; i < CountRow*CountCol; i++) if (min > arr[0][i]) min = arr[0][i];
	cout << "\n\n Min = " << min;

	int max = arr[0][0];
	for (int i = 0; i < CountRow*CountCol; i++) if (max < arr[0][i]) max = arr[0][i];
	cout << "\n\n Max = " << max << "\n\n";
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

	const int  DiapazonRnd = 10; // максимальное значение для генерации Rand() 
	const int CountRow = 4;//размер  массива - количество строк
	const int CountCol = 4;//размер  массива - количество столбцов
	int arr[CountRow][CountCol];

	//заполнение массива RND
	for (int i = 0; i < CountRow*CountCol; i++) arr[0][i] = rand() % DiapazonRnd;

	//===================Вычисления=============

	cout << "\n";
	for (int i = 0; i < CountRow; i++)
	{
		int sum = 0;
		for (int j = 0; j < CountCol; j++)
		{
			cout << arr[i][j] << "\t | \t";
			sum += arr[i][j];
		}
		cout << sum << "\n";
	}

	//горизонтальная линия
	for (int i = 0; i < CountCol * 17; i++) cout << "-"; cout << "\n";

	int sumall = 0;
	for (int j = 0; j < CountCol; j++)
	{
		int sum = 0;
		for (int i = 0; i < CountRow; i++)
		{
			sum += arr[i][j];
		}
		sumall += sum;
		cout << sum << "\t | \t";
	}
	cout << sumall << "\n";

}
// ДЗ 6 =================================================
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUSSIAN");

	const int  DiapazonRnd = 51; // максимальное значение для генерации Rand() 
	const int CountRow = 5;//размер  массива - количество строк
	const int CountCol = 10;//размер  массива - количество столбцов
	int arr[CountRow][CountCol];
	int arr2[CountRow][CountCol / 2];

	//заполнение массива RND
	for (int i = 0; i < CountRow*CountCol; i++) arr[0][i] = rand() % DiapazonRnd;

	//вывод на экран
	cout << "\n";
	for (int i = 0; i < CountRow; i++)
	{
		for (int j = 0; j < CountCol; j++)
		{
			cout << "   " << arr[i][j] << "\t |";
		}
		cout << "\n";
	}


	//Заполнение arr2

	for (int i = 0; i < CountRow*(CountCol / 2); i++) arr2[0][i] = arr[0][i * 2] + arr[0][i * 2 + 1];


	//вывод на экран
	cout << "\n";
	for (int i = 0; i < CountRow; i++)
	{
		for (int j = 0; j < CountCol / 2; j++)
		{
			cout << "   " << arr2[i][j] << "\t |";
		}
		cout << "\n";
	}
}