//Задание №4.
//Необходимо отсортировать первые две трети массива в порядке возрастания, 
//если среднее арифметическое всех элементов больше нуля; иначе - лишь первую треть.
//Остальную часть массива не сортировать, а расположить в обратном порядке.

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
