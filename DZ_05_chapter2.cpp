
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
#include <iostream>
#include <time.h>
using namespace std;

//#define TEST   //для теста - заполнение массива RANDOM()
#define BalStpnd 10.7  //средний бал для стипендии
#define nOcenok 10  //количество оценок для студента
#define MaxBal 12   //максимальный бал для оценки
#define msgNoCorrectCin cout<<"\nнеправильно ввели, повторите ввод\n\n"

void IniMas(int mas[], int n);
void Peresdacha(int mas[], int n);
void CinElementMas(int mas[], int n, int NumMas);
void PrintMas(int mas[], int n);
void Peresdacha(int mas[], int n);
void ChekStipendiya(int mas[], int n);

void main()
{
	srand(int(time(NULL)));
	setlocale(LC_ALL, "RUSSIAN");
	
	int mas[nOcenok];
	IniMas(mas, nOcenok);

	int menu = -1;
	while (menu)
	{
		cout << "Вывод оценок студента <1>\n";
		cout << "Пересдача экзамена    <2>\n";
		cout << "Выходит ли стипендия  <3>\n";
		cout << "Выход из программы    <0>\n";
		cout << "Выберите пункт меню   >";
		cin >> menu;
		if (!menu) break;
		switch (menu)
		{
		case 1: {
			PrintMas(mas, nOcenok);
			break;
		}
		case 2: {
			Peresdacha(mas, nOcenok);
			break;
		}
		case 3: {
			ChekStipendiya(mas, nOcenok);
			break;
		}
		default: {
			msgNoCorrectCin;
			break;
		}
		}

	}
}

void PrintMas(int mas[], int n)
{
	cout << "Оценки студента:\n";
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] = " << mas[i] << "\n";
	}
}

void Peresdacha(int mas[], int n)
{
	cout << "Пересдача экзамена :\n";
	bool err;
	do {
		cout << "Введите номер экзамена >";
		int num; cin >> num;
		err = (num<1 || num>nOcenok);
		if (err)
			msgNoCorrectCin;
		else {
			cout << "Введите новую оценку :";
			CinElementMas(mas, n, num-1);
		}
	} while (err);
}

void ChekStipendiya(int mas[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) sum += mas[i];
	if (double(sum) / n < BalStpnd) 
		cout << "Стипендии нет...\n"; 
	else cout << "Стипендия есть!\n";
}

void CinElementMas(int mas[], int n, int NumMas)
{
	bool err;
	do
	{
		int o;
		cout << "[" << NumMas + 1 << "] = ";
		cin >> o;
		err = (o<1 || o>MaxBal);
		if (err)
			msgNoCorrectCin;
		else mas[NumMas] = o;
} while (err);
}

#ifdef TEST
void IniMas(int mas[], int n)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % MaxBal+1;
	}
}
#else
void IniMas(int mas[], int n)
{
	cout << "Введите " << nOcenok << " оценок студента :\n";
	for (int i = 0; i < n; i++)
	{
		CinElementMas(mas,n,i);
	}
}
#endif



// ДЗ 4 =================================================
#include <iostream>
#include <time.h>
using namespace std;


#define N 10 //размерность массива
#define MyType double // тип данных для массива int, double, float
#define StartEndPlus  (2*N/3) //граница сортировки при значении >0
#define StartEndMinus  (1*N/3) //граница сортировки в остальных случаях

template <typename T> void Init(T mas[], int n) { for (int i = 0; i < n; i++) mas[i] = T(rand() % 201) / 10 - 10; }
template <typename T> void Print(T mas[], int n) { for (int i = 0; i < n; i++) cout << "  " << mas[i] << "\t"; cout << "\n"; }
template <typename T> T SrArifm(T mas[], int n) { T sum = 0; for (int i = 0; i < n;  i++)sum += mas[i]; return sum / n; } //хотя можно было и не делить на n чтобы узнать знак - или +
template <typename T> void SortUp(T mas[], int n, int start, int end);
template <typename T> void Mirror(T mas[], int n, int start, int end);

void main()
{
	srand(int(time(NULL)));
	setlocale(LC_ALL, "RUSSIAN");
	MyType mas[N];
	Init(mas, N);
	Print(mas, N);
	MyType sr = SrArifm(mas, N);
	cout <<"\nСреднее арифметическое = "<< sr <<"\n\n";
	int n;
	if (sr > 0) n = StartEndPlus; else n = StartEndMinus;
	SortUp(mas, N, 0, n-1);
	Mirror(mas, N, n , N - 1);
	Print(mas, N);
}

template<typename T>
void SortUp(T mas[], int n, int start, int end)
{
	for (int i = start; i <end; i++)
		for (int j = end; j > i; j--)
			if (mas[j] < mas[j - 1]) {
				T tmp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = tmp;
			}

}

template<typename T>
void Mirror(T mas[], int n, int start, int end)
{
	while (start < end) {
		T tmp = mas[start];
		mas[start] = mas[end];
		mas[end] = tmp;
		start++; end--;
	}
}

