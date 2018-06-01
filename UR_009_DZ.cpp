
Дворников М.А.PSV18 - V2

Курс «Язык программирования C»
Домашнее задание из методички "Урок 9"

1.Написать шаблон функции для поиска среднего арифме-
тического значений массива.
2.Написать перегруженные шаблоны функций для
нахождения корней линейного (a*x + b = 0) и квадрат-
ного (a*x2+b*x + c = 0) уравнений. Замечание: в функции
передаются коэффициенты уравнений.
3.Написать функцию, которая принимает в качестве
параметров вещественное число и количество знаков
после десятичной точки, которые должны остаться. За-
дачей функции является округление вышеуказанного
вещественного числа с заданной точностью


// ДЗ 1 =================================================

#include <iostream>
#include <time.h>
using namespace std;

#define N 10 // размерность массива
#define MyType double //тип массива int, double, float

template <typename T> T SrArifm(T mas[], int n) {
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += mas[i];
	return sum / n;
}

template <typename T> void Init(T mas[], int n) {
	for (int i = 0; i < n; i++) 
		mas[i] = T(rand() % 201) / 10 - 10;
}

template <typename T> void Print(T mas[], int n) { 
	cout << "\n"; 
	for (int i = 0; i < n; i++)
		cout << "  " << mas[i] << "\t"; 
	cout << "\n"; 
}

void main()
{
	srand(int(time(NULL)));
	setlocale(LC_ALL, "RUSSIAN");

	MyType mas[N];
	Init(mas, N);
	Print(mas, N);
	cout << "Среднее арифметическое = " << SrArifm(mas, N)<<"\n";
}


// ДЗ 2 =================================================

#include <iostream>
#include <math.h>
using namespace std;

template <typename T1, typename T2> void Koren(T1 a, T2 b);
template <typename T1, typename T2, typename T3> void Koren(T1 a, T2 b, T3 c);
template <typename T1, typename T2, typename T3> void PrintAndKoren(T1 a, T2 b, T3 c);

void main()
{
	setlocale(LC_ALL, "RUSSIAN");

	PrintAndKoren(13, -4, 9);
	PrintAndKoren(0, -4, 9);
	PrintAndKoren(13, 0, 9);
	PrintAndKoren(13, -4, 0);
	PrintAndKoren(0, 0, 9);
	PrintAndKoren(13, 0, 0);
	PrintAndKoren(0, -4, 0);
	PrintAndKoren(0, 0, 0);
}
template<typename T1, typename T2, typename T3>
void PrintAndKoren(T1 a, T2 b, T3 c)
{
	cout << "A = " << a << "\tB = " << b << "\tC = " << c << "\n";
	cout << "Решение линейного уравнения :\n";
	Koren(a, b);
	cout << "Решение квадратного уравнения\n";
	Koren(a, b, c);
	cout << "\n";
}

template <typename T1, typename T2>
void Koren(T1 a, T2 b)
{
	if (a == 0) {
		cout << " >Уравнение не имеет решений.\n";
		return;
	}
	if (a == 0 && b == 0) {
		cout << " >Уравнение имеет бесчисленное множество решений.\n";
		return;
	}
	cout << "X = " << double(-b) / a << "\n";
}

template <typename T1, typename T2, typename T3>
void Koren(T1 a, T2 b, T3 c)
{
	if (a == 0 && b == 0 && c != 0) {
		cout << " >Уравнение не имеет решений.\n";
		return;
	}
	if (a == 0 && b == 0 && c == 0) {
		cout << " >Уравнение имеет бесчисленное множество решений\n";
		return;
	}
	if (a == 0 && b != 0 && c != 0) {
		Koren(b, c);
		return;
	}
	if (c==0 && (a == 0 || b == 0)) {
		cout << "X = 0\n";
		return;
	}
	if (b == 0) {
		cout << "X1 = "<< sqrt(double(c)/a)<<"\n";
		cout << "X2 = " << -sqrt(double(c) / a) << "\n";
		return;
	}
	
	double d = b * b - 4 * a*c;
	//cout << "D = " << d << "\n";
	double n1 = double(-b) / 2 / a;
	double n2 = sqrt(abs(d)) / 2 / a;
	if (d < 0) {
		cout << "X1 = " << n1 << " + " << n2 << " * i\n";
		cout << "X2 = " << n1 << " - " << n2 << " * i\n";
		return;
	}
	if (d > 0) {
		cout << "X1 = " << n1  + n2 << "\n";
		cout << "X2 = " << n1 - n2 << "\n";
		return;
	}
	if (d == 0) {
		cout << "X = " << n1<< "\n";
	}

}


// ДЗ 3 =================================================
#include <iostream>
using namespace std;


double Precission(double a, int n) { return int(a*pow(10, n) + .5) / pow(10, n); }

void main() {
	cout << Precission(12.1235444444, 3)<<"\n";
}

