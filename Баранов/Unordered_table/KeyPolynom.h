#ifndef __TKEYPOLYNOM_H__
#define __TKEYPOLYNOM_H__
#include<string>
#include<iostream>
#include"polinom.h"

using namespace std;
// ���� ��� ��� �������
//������������ ����� �������
class TKeyPolynom
{
public:
	TKeyPolynom *pNext; //���������� ��������� �� �������� �������, ����� ������� ������
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
	void SetNext( TKeyPolynom* _pNext) //������������� ��������� ��� ������������� �������� 
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
		//�� ����, �.� �� �������� ������ ��� pNext
		//������ ��� ��������� 
	}
};

#endif
