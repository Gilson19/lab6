#ifndef __TKEYPOLYNOM_H__
#define __TKEYPOLYNOM_H__
#include<string>
#include<iostream>
#include"polinom.h"

using namespace std;
// узел дл€ хэш таблицы
//используетс€ метод цепочек
class TKeyPolynom
{
public:
	TKeyPolynom *pNext; //используем указатель на следущий элемент, чтобы создать список
	string name;
	string value;
	TPolynom p;
	int count;

	TKeyPolynom()
	{
		pNext = nullptr;
		name = "";
		value = "";
		TPolynom res;
		p = res;
		count = 0;
	}
	void SetKey(const string &key)
	{
		name = key;
	}
	void SetValue(const string &p)
	{
		value = p;
	}
	void SetPolynom(const TPolynom &polynom)  
	{
		p = polynom;
	}
	string GetKey()
	{
		return name;
	}
	string GetValue()
	{
		return value;
	}
	TPolynom GetPolynom()
	{
		return p;
	}
	void SetNext( TKeyPolynom* _pNext) //устанавливаем следующий при возникновении коллезии 
	{
		pNext = _pNext;
		count++;
	}
	TKeyPolynom* GetNext()
	{
		return pNext;
	}
	~TKeyPolynom()
	{
		//delete pNext;
		//не надо, т.к не выдел€ли пам€ть под pNext
		//служит как указатель 
	}
};

#endif
