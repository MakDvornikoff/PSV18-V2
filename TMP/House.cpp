#include <iostream>
//#include <string.h>
//#include <stdio.h>

using namespace std;

#define  StrMaxLen 30
#define  StrMaxLenShort 10
//#define  TEST

class Human {
	char * pFirstname;
	char * pMiddlename;
	char * pSurname;
public:

	struct sDate {
		int day;
		int month;
		int year;
	}Date;

	void Create() {
		pFirstname = (char *)malloc((StrMaxLen + 1) * sizeof(char));
		pMiddlename = (char *)malloc((StrMaxLen + 1) * sizeof(char));
		pSurname = (char *)malloc((StrMaxLen + 1) * sizeof(char));
	}
	Human(Human & obj) {
#ifdef TEST
		cout << "\nHUMA COPY_Constr\n\n";
#endif
		Create();

		pFirstname = strncpy(pFirstname, obj.pFirstname, StrMaxLen);
		pMiddlename = strncpy(pMiddlename, obj.pMiddlename, StrMaxLen);
		pSurname = strncpy(pSurname, obj.pSurname, StrMaxLen);
		Date.day = obj.Date.day;
		Date.month = obj.Date.month;
		Date.year = obj.Date.year;
	}

	Human() {
#ifdef TEST
		cout << "\nHUMA CONSTR\n\n";
#endif
		Create();
		cout << "Данные жильца:\nФамилия >";
		gets_s(pSurname, StrMaxLen);
		cout << "Имя >";
		gets_s(pFirstname, StrMaxLen);
		cout << "Отчество >";
		gets_s(pMiddlename, StrMaxLen);
		cout << "День рождения:\nДень >";
		cin >> Date.day;
		cout << "Месяц >";
		cin >> Date.month;
		cout << "Год >";
		cin >> Date.year;
	}
	Human(char * FirstName, char * Middlename, char * Surname, int day, int month, int year) {
#ifdef TEST
		cout << "\nHUMA CONSTR\n\n";
#endif
		Create();
		strncpy(pFirstname, FirstName, StrMaxLen);
		pMiddlename = strncpy(pMiddlename, Middlename, StrMaxLen);
		pSurname = strncpy(pSurname, Surname, StrMaxLen);
		Date.day = day;
		Date.month = month;
		Date.year = year;
	}

	void SetFirstname(char * name) {
		pMiddlename = strncpy(pMiddlename, name, StrMaxLen);
	}
	void SetMiddlename(char * name) {
		pMiddlename = strncpy(pMiddlename, name, StrMaxLen);
	}
	void SetSurname(char * name) {
		pSurname = strncpy(pSurname, name, StrMaxLen);
	}

	~Human() {
#ifdef TEST
		cout << "\nHUMA DESTRUCT\n\n";
		print();
#endif
		free(pFirstname);
		free(pMiddlename);
		free(pSurname);
	}
	void print() {
		cout << "\nФамилия: " << pSurname <<
			"\tИмя: " << pFirstname <<
			"\tОтчество: " << pMiddlename <<
			"\tДень рождения: " << Date.day << "." << Date.month << "." << Date.year << "\n";
	}
};
class Appartment {
	void Create() {
		CountHumans = 0;
		Humans = NULL;
	}


public:
	int Number;
	int Area;
	int CountRoom;
	Human ** Humans;
	int CountHumans;




	Appartment() {
		cout << "\nAPPART CONSTR\n\n";
		Create();
		cout << "Квартира:\nНомер >";
		cin >> Number;
		cout << "Площадь >";
		cin >> Area;
		cout << "Количество комнат >";
		cin >> CountRoom;
	}
	Appartment(int number, int area, int countRoom) {
#ifdef TEST
		cout << "\nAPPART CONSTR\n\n";
#endif
		Create();
		Number = number;
		Area = area;
		CountRoom = countRoom;
	}
	~Appartment() {
#ifdef TEST
		cout << "\nAPPART DESTRUCT\n\n";
#endif
		for (int i = 0; i < CountHumans; i++) {
			delete  *(Humans + i);
		}
		if (Humans != NULL) free(Humans);
	}
	void AddHuman(Human *  & const human) {

		if (CountHumans)
			Humans = (Human **)realloc(Humans, (CountHumans + 1) * sizeof(Human*));
		else
			Humans = (Human **)malloc(sizeof(Human*));

		*(Humans + CountHumans) = human;
		CountHumans++;
	}
	void AddHuman(char * FirstName, char * Middlename, char * Surname, int day, int month, int year) {
		Human * human;
		human = new Human(FirstName, Middlename, Surname, day, month, year);
		AddHuman(human);
	}
	Appartment(Appartment & obj) {
#ifdef TEST
		cout << "\nAPPART COPY_Constr\n\n";
#endif
		Create();
		Number = obj.Number;
		Area = obj.Area;
		CountRoom = obj.CountRoom;
		CountHumans = obj.CountHumans;
		if (CountHumans > 0) {
			Humans = (Human **)malloc(CountHumans * sizeof(Human*));
			for (int i = 0; i < CountHumans; i++) {
				Human * tmp = new Human(*(obj.Humans[i]));

				*(Humans + i) = tmp;
				tmp = NULL;
			}
		}
		else Humans = NULL;
	}
	void Remove(Human * human) {
		int pos = 0;
		while (pos < CountHumans && human != *(Humans + pos)) pos++;

		if (pos == CountHumans) {
			cout << "Error <Remove Human> объект не найден";
			return;
		}

		delete *(Humans + pos);

		if (CountHumans == 1) {
			free(Humans);
			Humans = NULL;
			CountHumans = 0;
			return;
		}

		for (int i = pos + 1; i < CountHumans; i++) {
			*(Humans + i - 1) = *(Humans + i);
		}
		--CountHumans;
		Humans = (Human**)realloc(Humans, CountHumans * sizeof(Human*));
	}
	void Remove(int number) {
		if (number > CountHumans || number<1) return;
		Remove(*(Humans + number - 1));
	}
	void print() {
		cout << "Квартира:\nНомер: " << Number << "\tПлощадь: " << Area << "\tКоличество комнат: " << CountRoom;
		cout << "\nПрописаны :";
		if (CountHumans)
			for (int i = 0; i < CountHumans; i++) {
				cout << i + 1 << ") ";
				(*(Humans + i))->print();
			}
		else
			cout << "Нет прописанных жильцов\n";
	}
};
class House {
	void Create() {
		pNumber = (char *)malloc((StrMaxLenShort + 1) * sizeof(char));
		pPrefixStreet = (char *)malloc((StrMaxLenShort + 1) * sizeof(char));
		pStreet = (char *)malloc((StrMaxLen + 1) * sizeof(char));
		pCity = (char *)malloc((StrMaxLen + 1) * sizeof(char));
	}

	char * pNumber;
	char * pPrefixStreet;
	char * pStreet;
	char * pCity;

public:


	House(char * Number, char * PrefixStreet, char * Street, char * City) {
		Create();
		pNumber = strncpy(pNumber, Number, StrMaxLenShort);
		pPrefixStreet = strncpy(pPrefixStreet, PrefixStreet, StrMaxLenShort);
		pStreet = strncpy(pStreet, Street, StrMaxLen);
		pCity = strncpy(pCity, City, StrMaxLen);
	}
	House() {
		Create();
		cout << "Введите :\nНомер дома >";
		gets_s(pNumber, StrMaxLenShort);
		cout << "Префикс ул./пер./туп. >";
		gets_s(pPrefixStreet, StrMaxLenShort);
		cout << "Название улицы >";
		gets_s(pStreet, StrMaxLen);
		cout << "Город >";
		gets_s(pCity, StrMaxLen);
	}
	House(char * n) {

	}
	~House() {
		free(pNumber);
		free(pPrefixStreet);
		free(pStreet);
		free(pCity);
	}
	void print() {
		cout << "Дом № " << pNumber <<
			"\tулица: " << pPrefixStreet << ". " << pStreet <<
			"\tгород: " << pCity << "\n";
	}
	Appartment AddAppartment() {

	}
	Appartment AddAppartment(char * Number, int S, int NRoom) {

	}
	void DeleteAppartment(char * NumDelete) {

	}
};

void main() {
	setlocale(LC_ALL, "RUSSIAN");


	/*char Num[] = "3a";
	char Prfx[] = "per";
	char Strt[] = "Macht";
	char City[] = "Dnepr";

	House house (Num,Prfx,Strt,City);
	house.print();*/

	Appartment ap(3, 72, 3);
	ap.print();

	//Human * hu;
	//hu = new Human;  //ввод с клавиатуры
	//ap.AddHuman(hu);

	char fn[StrMaxLen] = "Ivan";
	char mn[StrMaxLen] = "Petrovich";
	char sn[StrMaxLen] = "Vasilkov";
	ap.AddHuman(fn, mn, sn, 15, 6, 1970);
	ap.AddHuman(fn, mn, sn, 16, 6, 1970);
	ap.AddHuman(fn, mn, sn, 17, 6, 1970);

	ap.print();
	Appartment ap2 = ap;
	ap2.Number = 5;
	char sn2[StrMaxLen] = "STOLETOV";
	ap2.Humans[0]->SetSurname(sn2);
	ap2.Humans[1]->SetSurname(sn2);
	ap2.Humans[2]->SetSurname(sn2);
	ap.print();
	ap2.print();

	ap2.Remove(2);
	ap.Remove(1);
	ap.print();
	ap2.print();
}