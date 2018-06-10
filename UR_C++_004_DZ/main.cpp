#include <iostream>
#include <time.h>

using namespace std;

//#define  TEST

//#include "String.h"
#include "DMas.h"

void main() {
	setlocale(LC_ALL, "RUSSIAN");
	srand(int(time(NULL)));
	DMas m1(10),m2(7),m3;

	m1.Print();
	m1.Printn(2);
	//m2 = m1;
	(m2++).Print();
	m2.Print();

	cout<<m1[9]<<"\n";
	m3 = m1 - m2;
	m3.Print();
	(m1 +  m2).Print();

}
