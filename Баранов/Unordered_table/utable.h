#ifndef __TUTABLE_H__
#define __TUTABLE_H__
#include<iostream>
#include<string>
#include<iomanip>
#include "polinom.h"
#include"stack.h"
using namespace std;

const int MAX_SIZE = 100;

struct TNode_
{
	string name;
	string polynom;
	TPolynom p;
};

class TUtable
{
private:
	TNode_ *table;
	size_t count;
	bool IsKey(const string key);
	//for arifmetic
	bool IsDigit(char c);
public:
	TUtable();
	TUtable(const TUtable &t);
	~TUtable();

	size_t GetSize() const { return count; }
	bool IsEmtpy() const { return (count == 0); }
	bool IsFool() const { return (count==MAX_SIZE); }
	
	string ReturnName(int key) const;
	//string ReturnPolynom(int key) const;

	void Add(const string &name,const  string &polynom);
	string Search(const string key);
	void Del(const string key);
	TPolynom ReturnPolynom(const string key);
	TPolynom Arifmetic(const string str);

	TUtable& operator=(const TUtable &t);

	friend ostream& operator<<(ostream &out, TUtable &t);
};

#endif
