#ifndef __THTABLE_H__
#define __THTABLE_H__

#include<iostream>
#include<string>
#include<iomanip>
#include"KeyPolynom.h"
#include"polinom.h"
#include"stack.h"
using namespace std;

const int MAX_SIZE_H = 256; // всего элементов в таблице ASKII, 0..255


class THtable
{
private:
	TKeyPolynom *table;
	int count;
	int hashfunc(string key); 
	//for arifmetic
	bool IsDigit(char c);
public:
	THtable();
	THtable(const THtable &h);
	~THtable();

	bool IsEmpty() const { return count == 0; }
	int GetSize() const { return count; }

	void Add(const string name, const string polynom);
	string Search(const string name);
	void Del(const string name);
	TPolynom ReturnPolynom(const string key);

	TPolynom Arifmetic(const string str);

	friend ostream & operator<<(ostream & out, THtable & t);
};

#endif

