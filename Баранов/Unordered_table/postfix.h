#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include <iostream>
#include <stdlib.h>
#include "stack.h"
#include"polinom.h"
#include"utable.h"

using namespace std;

class TPostfix
{
private:
	string infix;
	string postfix;
	void EraseSpace();
	int prior(char c);
	bool IsDigit(int i);
	bool IsChar(int i);

public:
	TPostfix();
	TPostfix(const string &enter);
	void SetInfix(const string &enter);
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string ToPostfix();
	/*void WatchLen();
	void WatchSize();*/
	TPolynom Calculate();
};

#endif

