#include <iostream>
#include <time.h>
using namespace std;

#define TEST
#define BalStpnd 5  //средний бал для стипендии
#define nOcenok 10  //количество оценок для студента
#define MaxBal 12   //максимальный бал для оценки

#ifdef TEST
void IniMas(int mas[], int n);
#endif

void main()
{
	setlocale(LC_ALL, rus);
	int mas[nOcenok];

#ifdef TEST
	srand(int(time(NULL)));
	IniMas(mas, nOcenok);
#else
	cout << "Введите " << nOcenok << " оценок студента :\n";
	for (int i = 0; i < nOcenok; i++)
	{
		do
		{
			int n;
			cout << "[" << i + 1 << "] = ";
			cin >> n;

		} while (n<1 || n>maxbal);
	}
#endif

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

	}

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
		mas[i] = rand() % MaxBal+1;
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
