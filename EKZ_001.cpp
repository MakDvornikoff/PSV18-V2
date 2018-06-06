#include <iostream>
using namespace std;


#define MyType double

void  Create(MyType * &dar, int &n) {
	n = 0;
	while (n < 1) {
		cout << "Введите количество элементов >";
		cin >> n;
	}
	dar = (MyType *)malloc(n * sizeof(MyType));
	for (int i = 0; i < n; i++) {
		cout << "Dar[" << i << "]=";
		cin >> *(dar + i);
	}
	//return dar;
}

template <typename T> T ** Create(T * dar1, int n1, int * &n2) {

	int col = -1;
	while (col < 1||col>n1) {
		cout << "Введите количество столбцов для матрицы >";
		cin >> col;
	}

	
	int last = n1 % col; //остаток
	int row = n1 / col;
	if (last != 0) row++; else last = col;

	if (n2 != NULL) free(n2);
	n2 = (int *)malloc((row+1) * sizeof(int));
	*n2 = row; //в первом элементе хранится количество строк. в последующих элементах - длина каждой строки

	T ** dar2 = (T**)malloc(row * sizeof(T *));
	
	int j = n1 - 1;
	for (int i = 1; i <= *n2; i++) {
		int curr;
		if (i == *n2) curr = last; else curr = col;
		*(n2 + i) = curr;
		*(dar2 + i - 1) = (T*)malloc(curr * sizeof(T*));
				
		for (int ii=0;ii<curr;ii++,j--) *(*(dar2+i-1)+ii)=*(dar1+j);
	}
	return dar2;
}


template <typename T> void Print(T * dar, int n) {
	for (int i = 0; i < n; i++,dar++) 
		cout << "  " << *dar << "\t";
	cout << "\n";
}

template <typename T> void Print(T ** dar, int * n) {
	for (int i = 1; i <= *n; i++,dar++) Print(*dar, *(n+i));
}


void main() {

	setlocale(LC_ALL, "RUSSIAN");

	int n1;
	MyType * dar1=NULL;
	Create(dar1, n1);
	Print(dar1, n1);

	int * n2=NULL;
	MyType ** dar2 = Create(dar1, n1, n2);
	Print(dar2, n2);

	free(dar1);
	free(dar2);
	free(n2);
}