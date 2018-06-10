#include <iostream>
//#include <string.h>
//#include <stdio.h>
using namespace std;

//#define  TEST

#include "String.h"

void main() {
	setlocale(LC_ALL, "RUSSIAN");
	
	String s1,s2;
	s1.Gets();
	s2.Gets();

	(s1 + s2).Printn();
	(s1*s2).Printn();
	s1.Printn();
	s2.Printn();

}
