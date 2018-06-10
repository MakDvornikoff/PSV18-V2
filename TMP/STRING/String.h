#pragma once

#define  StrDefoltLen 80
#define  StrLongLen 255
#define  StrMiddleLen 30
#define  StrShortLen 10

class String
{
	int Length;
	char * pString;
	void create(int lenght);
public:

	String();
	~String();

	String(String & obj);
	String(int lenght);
	String(const char  * const str);

	String operator+ (String & obj);
	String operator* (String & obj);

	char * Get();
	char * Gets();
	void Print();
	void Printn();
	void Printt();

};

