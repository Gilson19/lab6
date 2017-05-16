#ifndef __TOTABLE_H__
#define __TOTABLE_H__

#include<string>
#include<iostream>
#include<iomanip>
#include"polinom.h"
#include"stack.h"

using namespace std;

const int MAX = 100;

struct TNode
{
	string key;
	string polynom;
	TPolynom p;
};
class TOtable
{
private:
	TNode *table;
	int count;
	bool IsKey(const string key);
	//for arifmetic
	bool IsDigit(char c);
public:
	TOtable();
	TOtable(const TOtable &t);
	~TOtable();
	bool IsEmpty() { return count == 0; }
	bool IsFull() { return count == MAX; }
	int GetSize() const { return count;}
	//работа с ключами
	void Add(const string key, const string polynom);
	string Search(const string key);
	void Del(const string key);
	//работа с индексами
	void Del(const int key);
	string ReturnKey(int key);
	//string ReturnPolynom(int key);
	TPolynom ReturnPolynom(const string key);
	TPolynom Arifmetic(const string str);

	TOtable& operator=(const TOtable &t);


	friend ostream& operator<<(ostream &out, TOtable &t);
};
#endif