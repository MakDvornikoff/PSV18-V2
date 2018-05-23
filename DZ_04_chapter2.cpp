
Дворников М.А. PSV18-V2

Курс «Язык программирования C»
Тема : Функции
	Домашнее задание
	Задание 1 :	Написать функцию, которая принимает два параметра : основание степени и показатель степени, и вычисляет степень числа на основе полученных данных.
	Задание 2 :	Написать функцию, которая получает в качестве параметров 2 целых числа и возвращает сумму чисел из диапазона между ними.
	Задание 3 :	Число называется совершенным, если сумма всех его делителей равна ему самому.Напишите функцию поиска таких чисел во введенном интервале.
	Задание 4 :	Написать функцию, выводящую на экран переданную ей игральную карту.
	Задание 5 :	Написать функцию, которая определяет, является ли «счастливым» шестизначное число.
	Задание 6 :	Написать функцию, которая принимает две даты(т.е.функция принимает шесть параметров) и вычисляет разность в днях между этими датами.Для решения этой задачи необходимо также написать функцию, которая определяет, является ли год високосным.
	Задание 7 :	Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива.
	Задание 8 :	Написать функцию, определяющую количество положительных, отрицательных и нулевых элементов передаваемого ей массива.



// ДЗ 1 =================================================
#include <iostream>
#include <math.h>
using namespace std;

double Pow(double, int);

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Для выхода нажмите <Ctrl>+<C>\n\n";
	while (1)
	{
		cout << "Введите x >";
		int x; cin >> x;
		cout << "Введите y >";
		int y; cin >> y;
		cout << " x^y = " << Pow(x, y) << "\n\n";
	}

}

double Pow(double x, int y)
{
	double res = 1;
	for (int i = 0; i < abs(y); i++)
	{
		if (y < 0) res /= x;
		else res *= x;
	}
	return res;
}

// ДЗ 2 =================================================
#include <iostream>
#include <math.h>
using namespace std;

int SumDiapazon(int, int);

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	cout << "Введите Начало диапазона >";
	int s; cin >> s;
	cout << "Введите Конец диапазона  >";
	int e; cin >> e;
	cout << " Сумма внутри диапазона = " << SumDiapazon(s, e) << "\n\n";


}

int SumDiapazon(int start, int end)
{
	int res;
	if (start > end) { res = start; start = end; end = res; }

	res = 0;
	for (int i = start + 1; i < end; i++) res += i;// Сумма между start и end, исключая start и end

	return res;
}
// ДЗ 3 =================================================
#include <iostream>
#include <math.h>
using namespace std;

bool IsPerfect(int);

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Для выхода введите '0'\n\n";

	while (1)
	{
		cout << "Введите число >";
		int s; cin >> s;
		if (!s) break;

		if (IsPerfect(s)) cout << " Число Совершенное!\n\n";
		else cout << " Число Несовершенное...\n\n";

	}
}
bool IsPerfect(int n)
{
	int sum = 0;
	for (int i = 1; i <= n / 2; i++)
		if (n%i == 0) sum += i;
	return (sum == n);
}

// ДЗ 4 =================================================
#include <iostream>
#include <math.h>
using namespace std;

void Card(int, int);

void main()
{

	setlocale(LC_ALL, "RUSSIAN");
	cout << "Для выхода введите '0'\n\n";

	while (1)
	{
		cout << "Введите достоинство карты 2..14 >";
		int d; cin >> d;
		if (!d) break;

		cout << "Введите масть карты 1..4 >";
		int m; cin >> m;
		if (!m) break;

		Card(d, m);

	}
}
void Card(int dignity, int suit)
{
	if (dignity < 2 || dignity>14)
	{
		cout << "Неверное достоинство карты\n\n";
		return;
	}
	if (suit < 1 || suit>4)
	{
		cout << "Неверная масть карты\n\n";
		return;
	}

	switch (dignity)
	{
	case 11:
	{
		cout << "Валет";
		break;
	}
	case 12:
	{
		cout << "Дама";
		break;
	}
	case 13:
	{
		cout << "Король";
		break;
	}
	case 14:
	{
		cout << "Туз";
		break;
	}
	default:
		cout << dignity;
	}

	switch (suit)
	{
	case 1:
		cout << " Трефы";
		break;
	case 2:
		cout << " Бубны";
		break;
	case 3:
		cout << " Червы";
		break;
	case 4:
		cout << " Пики";
		break;
	}
	cout << "\n\n";
}
// ДЗ 5 =================================================
#include <iostream>
#include <math.h>
using namespace std;

bool IsHappy(int);

void main()
{
	setlocale(LC_ALL, "RUSSIAN");
	cout << "Для выхода введите '0'\n\n";

	while (1)
	{
		cout << "Введите шестизначное число >";
		int s; cin >> s;
		if (!s) break;

		if (IsHappy(s)) cout << " Число Счастливое!\n\n";
		else cout << " Число Простое...\n\n";

	}
}
bool IsHappy(int n)
{
	int count = 1;
	int sum = 0;
	while (n)
	{
		if (count < 4) sum += n % 10; else sum -= n % 10;
		n /= 10; ++count;
	}
	return (!sum);
}
// ДЗ 6 V.1 =================================================
//ВАРИАНТ 1 По формулам (ниже приведен Вариант2 при помощи условий)
#include <iostream>
#include <math.h>
using namespace std;

float CountDay(int[3], int[3]);
float DaysFrom1Year(int[3]);
int DayInMonth(int Month, int Year);
bool isLeapYear(int);

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int  Day1[3]{ 17,5,2018 };// Дата 1 - день/месяц/год
	int  Day2[3]{ 1,1,2017 }; // Дата 2 - день/месяц/год

	cout << CountDay(Day1, Day2) << "\n";
	//cout << DaysFrom1Year(Day1) << "\n"; //используется при тестировании для проверки всего диапазона
	//cout << DaysFrom1Year(Day2) << "\n"; //используется при тестировании для проверки всего диапазона
}

float CountDay(int Date1[3], int Date2[3])
{
	return abs(DaysFrom1Year(Date1) - DaysFrom1Year(Date2));
}
float DaysFrom1Year(int Date[3])// количество дней от 1.1.1
{
	double res = 0;
	for (int i = 1; i<Date[2]; i++) res += 365 + 1 * isLeapYear(i);
	for (int i = 1; i<Date[1]; i++)res += DayInMonth(i, Date[2]);
	res += Date[0] - 1;
	return res;
}
int DayInMonth(int Month, int Year) // количество дней в месяце // использованы формулы из источника https://habr.com/post/261773/
{
	return (28 + ((Month + (Month / 8)) % 2) + 2 % Month + ((1 + isLeapYear(Year)) / Month) + (1 / Month) - (isLeapYear(Year) / Month));
}
bool isLeapYear(int Year) // использованы формулы из источника https://habr.com/post/261773/
{
	return ((1 - (Year % 4 + 2) % (Year % 4 + 1)) * ((Year % 100 + 2) % (Year % 100 + 1)) + (1 - (Year % 400 + 2) % (Year % 400 + 1)));
}

// ДЗ 6 V.2 =================================================
//ВАРИАНТ 2 При помощи условий 
#include <iostream>
#include <math.h>
using namespace std;

float CountDay(int[3], int[3]);
float DaysFrom1Year(int[3]);
int DayInMonth(int Month, int Year);
bool isLeapYear(int);

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	int  Day1[3]{ 17,5,2018 };// Дата 1 - день/месяц/год
	int  Day2[3]{ 1,1,2017 }; // Дата 2 - день/месяц/год

	cout << CountDay(Day1, Day2) << "\n";
	//cout << DaysFrom1Year(Day1) << "\n"; //используется при тестировании для проверки всего диапазона
	//cout << DaysFrom1Year(Day2) << "\n"; //используется при тестировании для проверки всего диапазона
}


float CountDay(int Date1[3], int Date2[3])
{
	return abs(DaysFrom1Year(Date1) - DaysFrom1Year(Date2));
}
float DaysFrom1Year(int Date[3])
{
	double res = 0;
	for (int i = 1; i<Date[2]; i++) res += 365 + isLeapYear(i);
	for (int i = 1; i<Date[1]; i++)res += DayInMonth(i, Date[2]);
	res += Date[0] - 1;
	return res;
}
int DayInMonth(int Month, int Year) // количество дней в месяце
{
	return (Month == 2) ? (28 + isLeapYear(Year)) : (Month < 8) ? (30 + Month % 2) : (30 + (Month + 1) % 2);
}
bool isLeapYear(int Year)
{
	return ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0);
}


// ДЗ 7 =================================================
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

double Average(int[][10], int, int);

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUSSIAN");

	const int  DiapazonRnd = 51; // максимальное значение для генерации Rand() 
	const int CountRow = 5;//размер  массива - количество строк
	const int CountCol = 10;//размер  массива - количество столбцов
	int arr[CountRow][CountCol];

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

	//===
	cout << "Среднее арифметическое = " << Average(arr, CountRow, CountCol) << "\n\n";
}
double Average(int a[][10], int cRow, int cCol)
{
	double sum = 0;
	for (int i = 0; i < cRow*cCol; i++) sum += a[0][i];
	return (sum / cRow / cCol);
}
// ДЗ 8 =================================================
#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

void Mix(int[][10], int, int);

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "RUSSIAN");

	const int  DiapazonRnd = 101; // максимальное значение для генерации Rand() -50..+50 
	const int CountRow = 2;//размер  массива - количество строк
	const int CountCol = 10;//размер  массива - количество столбцов
	int arr[CountRow][CountCol];

	//заполнение массива RND
	for (int i = 0; i < CountRow*CountCol; i++) arr[0][i] = -DiapazonRnd / 2 + rand() % DiapazonRnd;

	//вывод на экран
	cout << "\n";
	for (int i = 0; i < CountRow; i++)
	{
		for (int j = 0; j < CountCol; j++)
		{
			cout << " " << arr[i][j] << "\t |";
		}
		cout << "\n";
	}

	//сумма===
	Mix(arr, CountRow, CountCol);
}

void Mix(int a[][10], int cRow, int cCol)
{
	int cPlus = 0, cMinus = 0, cNull = 0;
	for (int i = 0; i < cRow*cCol; i++)
	{
		if (a[0][i] < 0) ++cMinus;
		else if (a[0][i] > 0) ++cPlus;
		else ++cNull;
	}
	cout << "\nКоличество положительных элементов : " << cPlus << "\nКоличество отрицательных элементов : " << cMinus << "\nКоличество нулевых элементов : " << cNull << "\n\n";
}

