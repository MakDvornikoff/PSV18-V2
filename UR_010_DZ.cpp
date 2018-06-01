
Дворников М.А.PSV18 - V2

Курс «Язык программирования C»
Домашнее задание из методички "Урок 10"

1. Дан массив чисел размерностью 10 элементов. Написать
функцию, которая сортирует массив по возрастанию или по
убыванию, в зависимости от третьего параметра функции.
Если он равен 1, сортировка идет по убыванию, если 0, то по
возрастанию. Первые 2 параметра функции — это массив и
его размер, третий параметр по умолчанию равен 1.
2. Дан массив случайных чисел в диапазоне от –20 до
+20. Необходимо найти позиции крайних отрицательных
элементов (самого левого отрицательного элемента и са-
мого правого отрицательного элемента) и отсортировать
элементы, находящиеся между ними.
3. Дан массив из 20 целых чисел со значениями от 1 до 20.
Необходимо:
■■ написать функцию, разбрасывающую элементы мас-
сива произвольным образом;
■■ создать случайное число из того же диапазона и найти
позицию этого случайного числа в массиве;
■■ отсортировать элементы массива, находящиеся слева
от найденной позиции по убыванию, а элементы массива,
находящиеся справа от найденной позиции по возрастанию.


// ДЗ 1 =================================================

#include <iostream>
#include <time.h>
using namespace std;

#define N 10
#define MyType int

template <typename T> void Sort(T mas[], int n, bool direct =1);
template <typename T> void Init(T mas[], int n);
template <typename T> void Print(T mas[], int n);

void main() {
	srand(int(time(NULL)));
	MyType mas[N];
	Init(mas, N);
	Print(mas, N);
	Sort(mas, N);
	Print(mas, N);
	Sort(mas, N,0);
	Print(mas, N);
}
template <typename T> void Sort(T mas[], int n, bool direct ) {
	int k;
	if (direct) k = 1; else k = -1;
	for (int i = 0; i < n; i++)
		for (int j = n - 1; j>i; j--)
			if (k*mas[j] < k*mas[j - 1]) {
				T tmp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = tmp;
			}
}

template <typename T> void Init(T mas[], int n) {
	for (int i = 0; i < n; i++)
		mas[i] = T(rand() % 201) / 10 - 10;
}
template <typename T> void Print(T mas[], int n) {
	for (int i = 0; i < n; i++)
		cout << "  " << mas[i] << "\t";
	cout<<"\n";
}

// ДЗ 2 =================================================

#include <iostream>
#include<time.h>
using namespace std;

#define N 10
#define MyType double

template <typename T> void Init(T mas[], int n);
template <typename T> void Print(T mas[], int n);
template <typename T> void Sort(T mas[], int n, int start, int end, int direction=1);
template <typename T> int ScanMinus(T mas[], int n, int direction = 1);
void main (){
	srand(int(time(NULL)));
	MyType mas[N];
	Init(mas, N);
	Print(mas, N);
	Sort(mas, N, ScanMinus(mas, N, 1)+1, ScanMinus(mas, N, 0)-1);
	Print(mas, N);
}

template<typename T>
void Init(T mas[], int n)
{
	for (int i = 0; i < n; i++)
		mas[i] = T(rand() % 401) / 10 - 20;
}

template<typename T>
void Print(T mas[], int n)
{
	for (int i = 0; i < n; i++)
		cout << "  " << mas[i] << "\t";
	cout << "\n";
}

template<typename T>
void Sort(T mas[], int n, int start, int end, int direction)
{
	if (direction) direction = 1; else direction = -1;
	for (int i=start;i<end;i++)
		for (int j = end; j > i; j--) 			
			if (direction*mas[j] < direction*mas[j - 1]) {
				T tmp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = tmp;
			}		
}

template<typename T>
int ScanMinus(T mas[], int n, int direction)
{
	int i;
	if (direction) {
		direction = 1;
		i = 0;
	}
	else {
		direction = -1;
		i = n - 1;
	}
	do {
		if (mas[i] < 0) return i;
		i += direction;
	} while (i != 0 && i != (n - 1));
	return -1;
}


// ДЗ 3 =================================================
#include <iostream>
#include <time.h>
using namespace std;

#define N 20
#define RND(X) (rand() % X + 1)
#define ITERRATION 10

void Init(int mas[],int n) { for (int i = 0; i < n; i++) mas[i] = i + 1;}
int Find(int mas[],int n, int val) { for (int i = 0; i < n; i++) if (mas[i] == val) return i; return -1;}
void Print(int mas[], int n) { for (int i = 0; i < n; i++) cout << "  " << mas[i] << "\t"; cout << "\n"; }
void UnSort(int mas[],int n, int iterration);
void Sort(int mas[], int n,int start, int end, int direction=1);

void main() {
	srand(int(time(NULL)));
	int mas[N];
	Init(mas, N);
	Print(mas, N);
	UnSort(mas, N, ITERRATION);
	Print(mas, N);
	int v = RND(N);
	cout << "Value = " << v << "\n";
	v = Find(mas, N, v);
	cout << "Position = "<<v<<"\n";
	Sort(mas, N, 0, v - 1, 0);
	Sort(mas, N, v + 1, N - 1, 1);
	Print(mas, N);
}

void UnSort(int mas[], int n, int iterration)
{
	for (int i = 0; i < iterration; i++) {
		int p1 = RND(n)-1;
		int p2 = RND(n)-1;
		int tmp = mas[p1];
		mas[p1] = mas[p2];
		mas[p2] = tmp;
	}
}

void Sort(int mas[], int n, int start, int end, int direction)
{
	if (direction>0) direction = 1; else direction = -1;
	for (int i=start;i<end;i++)
		for (int j=end;j>i;j--)
			if (direction*mas[j] < direction*mas[j - 1]) {
				int tmp = mas[j];
				mas[j] = mas[j - 1];
				mas[j - 1] = tmp;
			}
}

