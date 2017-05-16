#include "utable.h"
#include"stack.h"
bool TUtable::IsKey(const string key)
{
	for (int i = 0; i < count; i++)
		if (table[i].name == key) return true;
	return false;
}

bool TUtable::IsDigit(char c)
{
	if (c >= '0' && c <= '9') return true;
	return false;
}

TUtable::TUtable()
{
	table = new TNode_[MAX_SIZE];
	count = 0;
}

TUtable::TUtable(const TUtable & t)
{
	table = new TNode_[MAX_SIZE];
	count = 0;
	for (int i = 0;i < t.GetSize();i++)
	{
		table[i].name = t.table[i].name;
		table[i].polynom = t.table[i].polynom;
		table[i].p = t.table[i].p;
		count++;
	}
}

TUtable::~TUtable()
{
	delete[]table;
}

string TUtable::ReturnName(int key) const
{
	if (IsEmtpy()) throw("No elements in table");
	if (key<0 || key>count) throw("The index goes beyond");

	return table[key - 1].name;
}

//string TUtable::ReturnPolynom(int key) const
//{
//	if (IsEmtpy()) throw("No elements in table");
//	if (key<0 || key>count) throw("The index goes beyond");
//
//	return table[key - 1].polynom;
//}

void TUtable::Add(const string & name, const string & polynom)
{
	if (IsFool()) throw("The table is full");
	//search
	if (IsKey(name)) throw("Такой ключ уже имееется");
	table[count].name = name;
	table[count].polynom = polynom;
	TPolynom res(polynom);
	table[count].p = res;
	count++;
}

string TUtable::Search(const string key)
{
	if (IsEmtpy()) return "";
	//если не нашлось, возвращаем пустую строку.
	string res("");
	for (int i = 0;i < count;i++)
	{
		if (table[i].name == key) res = table[i].polynom;
	}
	return res;
}

void TUtable::Del(const string key)
{
	if (IsEmtpy()) throw("table is empty");
	for (size_t i = 0; i < count; i++)
	{
		if (table[i].name == key)
		{
			table[i].name = table[count - 1].name;
			table[i].polynom = table[count - 1].polynom;
			table[i].p = table[count - 1].p;
			count--;
			break;
		}
	}
}

TPolynom TUtable::ReturnPolynom(const string key)
{
	if (IsEmtpy()) throw("table is empty");
	TPolynom res;
	for (int i = 0; i < count; i++)
	{
		if (table[i].name == key) res = table[i].p;
	}
	return res;
}

TPolynom TUtable::Arifmetic(const string str)
{
	string postfix = str;
	if (postfix == "") return 0;
	struct saves
	{
		int count;
		char name[50];
	};
	char test[50];
	saves vars[50];
	TStack<TPolynom> calc(20);
	TPolynom digit1, digit2, on;
	int j, l, m(0), control;
	bool exist = false;

	for (register int i = 0; i < postfix.length(); i++)
	{
		if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/' && postfix[i] != '^' && postfix[i] != ' ')
		{
			if (!IsDigit(postfix[i]))
			{
				j = i;
				int p = 0;
				while (postfix[j] >= 'A' && postfix[j] <= 'z')
				{
					test[p++] = postfix[j++];
				}
				test[p] = '\0';

				exist = false;
				for (control = 0; control < m; control++)
				{
					if (strcmp(vars[control].name, test) == 0)
					{
						exist = true;
						break;
					}
				}
				if (exist)
				{
					string a = vars[control].name;
					on = ReturnPolynom(a);
					i = j - 1;
				}
				else
				{
					j = i;
					l = 0;
					while (postfix[j] >= 'A' && postfix[j] <= 'z')
					{
						vars[m].name[l++] = postfix[j++];
					}
					vars[m].name[l] = '\0';
					i = j - 1;
					string a = vars[m].name;

					on = ReturnPolynom(a);
				}
			}
			else
			{
				j = i;
				int k = 0;
				while (postfix[j] >= '0' && postfix[j] <= '9')
				{
					k++;
					j++;
				}
				j = i;
				char *res = new char[k];
				k = 0;
				while (postfix[j] >= '0' && postfix[j] <= '9')
				{
					res[k++] = postfix[j++];
				}
				res[k] = '\0';
				string a = res;
				TPolynom r(a);
				on = r;
				i = j;
			}
			calc.Push(on);
		}
		switch (postfix[i])
		{
		case '+':
		{
			digit1 = calc.Pop();
			digit2 = calc.Pop();
			calc.Push(digit1 + digit2);
			break;
		}
		case '-':
		{
			digit1 = calc.Pop();
			digit2 = calc.Pop();
			calc.Push(digit2 - digit1);
			break;
		}
		case '*':
		{
			digit1 = calc.Pop();
			digit2 = calc.Pop();
			calc.Push(digit1 * digit2);
			break;
		}
		}
	}
	TPolynom res;
	res = calc.Pop();
	return res;
}


TUtable & TUtable::operator=(const TUtable & t)
{
	delete[] table;
	table = new TNode_[MAX_SIZE];
	count = 0;

	for (int i = 0;i < t.GetSize();i++)
	{
		table[i].name = t.table[i].name;
		table[i].polynom = t.table[i].polynom;
		table[i].p = t.table[i].p;
		count++;
	}

	return *this;
}

ostream & operator<<(ostream & out, TUtable & t)
{
	cout << endl;
	cout <<"+======================================================================+" << endl;
	cout << left << "|"<<setw(30) << "Nomber:"<< "|" <<setw(30) << setw(30) << "Name:" << "|" << setw(30) << "Polynom:" << "|" << endl;
	cout << "+======================================================================+" << endl;
	for (int i = 0; i <t.GetSize(); i++)
	{
		cout << "|" << setw(30) << i+1 << "|" << setw(30) << t.table[i].name << "|" << setw(30) <<t.table[i].polynom<<"|"<< endl;
		cout << "+----------------------------------------------------------------------+" << endl;
		
	}
	cout << endl;
	return out;
}
