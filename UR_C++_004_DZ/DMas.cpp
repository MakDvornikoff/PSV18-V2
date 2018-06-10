#include "DMas.h"


//===================================================================
//����������� / ����������

DMas::DMas()
{
	count = 0;
	arr = NULL;

}


DMas::~DMas()
{
	if (arr != NULL) free(arr);
}

//===================================================================
//��������� ������������
DMas::DMas(int n) {
	count = n;
	Create();
}
DMas::DMas(DMas & obj) {
	//if (arr != NULL) free(arr);
	count = obj.count;
	arr = (int *)malloc(count * sizeof(int));
	cmpmem(arr);
	if (err) {
		count = 0;
		return;
	}

	for (int i = 0; i < count; i++)
		*(arr + i) = *(obj.arr + i);
}
void DMas::Create() {
	arr = (int *)malloc(count * sizeof(int));
	cmpmem(arr);
	if (err) {
		count = 0;
		return;
	}

	for (int i = 0; i < count; i++)
		*(arr + i) = RND;
}

//===================================================================
//���������� ����������

DMas& DMas::operator=(const DMas &obj) {
	if (&obj == this) return *this;
	if(arr != NULL) free(arr);
	count = obj.count;
	arr = (int *)malloc(count * sizeof(int));
	cmpmem(arr);
	if (err) {
		count = 0;
		return *this;
	}

	for (int i = 0; i < count; i++)
		*(arr + i) = *(obj.arr + i);
	return *this;
}
DMas DMas::operator+(const DMas &obj) {
	int n = (count < obj.count) ? count : obj.count;
	DMas tmp;
	tmp.count = n;
	tmp.arr = (int*)malloc(tmp.count * sizeof(int));
	cmpmem(tmp.arr);
	if (err) {
		tmp.count = 0;
		return tmp;
	}

	for (int i = 0; i < tmp.count; i++)
		*(tmp.arr + i) = *(arr+i)+*(obj.arr + i);
	return tmp;
}
DMas DMas::operator-(const DMas &obj) {
	int n = (count < obj.count) ? count : obj.count;
	DMas tmp;
	tmp.count = n;
	tmp.arr = (int*)malloc(tmp.count * sizeof(int));
	cmpmem(tmp.arr);
	if (err) {
		tmp.count = 0;
		return tmp;
	}

	for (int i = 0; i < tmp.count; i++)
		*(tmp.arr + i) = *(arr + i) - *(obj.arr + i);
	return tmp;
}
DMas DMas::operator++() {
	if (count)
		arr = (int*)realloc(arr, (count + 1)*sizeof(int));
	else
		arr = (int*)malloc(sizeof(int));
	cmpmem(arr);
	if (err) {
		count = 0;
		return *this;
	}
	
	*(arr + count) = RND;
	count++;

	return *this;
}
DMas DMas::operator++(int x) {
	DMas tmp;
	tmp= *this;
	
	if (count)
		arr = (int*)realloc(arr, (count + 1) * sizeof(int));
	else
		arr = (int*)malloc(sizeof(int));
	cmpmem(arr);
	if (err) {
		count = 0;
		return tmp;
	}

	*(arr + count) = RND;
	count++;

	return tmp;
}
DMas DMas::operator--() {
	count--;
	if (count > 0)
		arr = (int*)realloc(arr, (count) * sizeof(int));
	else
		if (arr != NULL) {
			free(arr);
			count = 0;
		}
	return *this;
}
DMas DMas::operator--(int x) {
	DMas tmp = *this;
	count--;
	if (count > 0)
		arr = (int*)realloc(arr, (count) * sizeof(int));
	else
		if (arr != NULL) {
			free(arr);
			count = 0;
		}
	return tmp;

}
int DMas::operator[](int i) {
	if (i<0 || i>count - 1)msgerrbound; else return *(arr + i);
	return 0;
}

//===================================================================
//��������� ������
void DMas::Print() {
	for (int i = 0; i < count; i++)
		cout << "  " << *(arr + i) << "\t";
	cout << "\n";
}
void DMas::Print(int i) {
	cout << "  " << *(arr + i) << "\t";

}
void DMas::Printn(int i) {
		cout << "  " << *(arr + i);
	cout << "\n";
}