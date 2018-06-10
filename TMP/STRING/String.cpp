#include "String.h"
#include <iostream>
using namespace std;
#define cmpmem(X) bool fmem=false;if(X==NULL)cout<<"Ошибка выделения памяти";else fmem=true
//===================================================================
//Конструктор / деструктор
String::String() {
	create(StrDefoltLen);
}
String::~String() {
	if (Length) free(pString);
}

//===================================================================
//остальные конструкторы
String::String(String & obj) {
	create(strlen(obj.pString) + 1);
	strcpy_s(pString, Length, obj.pString);
}

String::String(int lenght) {
	create(StrDefoltLen);
}

String::String(const char  * const str) {
	create(strlen(str) + 1);
	strcpy_s(pString, Length, str);
}


void String::create(int length) {
	pString = (char*)malloc((length) * sizeof(char));
	cmpmem(pString);
	if (!fmem) length = 0;
	else Length = length;
}

//===================================================================
//перегрузка операторов
String String::operator+ (String & obj) {
	int len1 = strlen(pString) + 1;
	int len12 = len1 + strlen(obj.pString);
	char *p = (char*)malloc(len12 * sizeof(char));
	cmpmem(p);
	if (!fmem) return NULL;
	
	strcpy_s(p, len1, pString);
	strcpy_s(p + strlen(pString), len12, obj.pString);
	String  tmp(p);
	return tmp;
}
String String::operator* (String & obj) {
	char * s = (char*)malloc(sizeof(char));
	*s = 0;
	if (!Length || !(obj.Length)) return String(s);
		
	int len = 0;
	for (int i = 0; i < Length; i++) {
		
		bool f = true;
		for (int k=0;k<i;k++) {
			if (*(pString + k) == *(pString + i)) {
				f = false; 
				break;
			}
		}

		if (f) {
			
			for (int j = 0; j < obj.Length; j++)
				if (*(pString + i) == *(obj.pString + j)) {
					*(s + len ) = *(pString + i);
					len++;
					s = (char*)realloc(s,(len+1) * sizeof(char));
					*(s + len ) = 0;
					break;
				}
		}
		
	}
	return String(s);
}

//===================================================================
//остальные методы
char * String::Get() {
	return pString;

}
char * String::Gets() {
	gets_s(pString, (Length));
	return pString;
}
void String::Print() {
	cout << pString;
}
void String::Printn() {
	cout << pString << "\n";
}
void String::Printt() {
	cout << pString << "\t";
}