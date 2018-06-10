#pragma once
#include <iostream>
using namespace std;

class DMas
{
#define RND (rand()%21-10)
#define cmpmem(X) bool err=true;if(X==NULL)cout<<"Ошибка выделения памяти";else err=false
#define msgerrbound cout<<"ERROR: Вышли за границы массива\n" 
	void Create();
	int count;
	int * arr;
public:
	DMas();
	~DMas();

	DMas(DMas & obj);
	DMas(int n);

	DMas& operator=(const DMas &obj);
	DMas operator+(const DMas &obj);
	DMas operator-(const DMas &obj);
	DMas operator++();
	DMas operator++(int x);
	DMas operator--();
	DMas operator--(int x);
	int operator[](int i);
	
	void Print();
	void Print(int i);
	void Printn(int i);
	
	

};

