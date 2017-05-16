#include "otable.h"

bool TOtable::IsKey(const string key)
{
	for (int i = 0; i < count; i++)
		if (table[i].key == key) return true;
	return false;
}

bool TOtable::IsDigit(char c)
{
		if (c >= '0' && c <= '9') return true;
		return false;
}

TOtable::TOtable()
{
	table = new TNode[MAX];
	count = 0;
}

TOtable::TOtable(const TOtable &t)
{
	table = new TNode[MAX];
	count = 0;
	for (int i = 0; i < t.count; i++)
	{
		table[i].key = t.table[i].key;
		table[i].polynom = t.table[i].polynom;
		table[i].p = t.table[i].p;
		count++;
	}
}

TOtable::~TOtable()
{
	delete[] table;
}

void TOtable::Add(const string key, const string polynom)
{
	if (IsFull()) throw("table is full");
	if (IsEmpty())
	{
		table[count].key = key;
		table[count].polynom = polynom;
		TPolynom res(polynom);
		table[count].p = res;
		count++;
	}
	else
	{
		int i = 0;
		int tmp=count;
		if (IsKey(key)) throw("Such a key already exists ");
		while (i < count)
		{
			if (table[i].key > key) {
				tmp = i;
				break;
			}
			i++;
		}
			for (i = count; i > tmp; i--)
			{
				table[i].key = table[i - 1].key;
				table[i].polynom = table[i - 1].polynom;
				table[i].p = table[i-1].p;
			}
		table[tmp].key = key;
		table[tmp].polynom = polynom;
		TPolynom res(polynom);
		table[tmp].p = res;
		count++;
		
	}
}

string TOtable::Search(const string key)
{
	if (IsEmpty()) return "";
	string res = "";
	int mid = 0;
	int left = 0;
	int right = count;
	while(1)
	{
		mid = (left + right) / 2;
		if (key < table[mid].key)
			right = mid - 1;
		else if (key>table[mid].key)
			left = mid + 1;
		else {
			return res=table[mid].polynom;
		}
		if (left > right) return res;
	}
	//return res;
}

void TOtable::Del(const string key)
{
	if (IsEmpty()) throw("table is empty");
	int tmp;
	for (int i = 0; i < count; i++)
	{
		if (table[i].key == key) {
			tmp = i;
			break;
		}
	}
	for (int i = tmp; i < count; i++)
	{
		table[i].key = table[i + 1].key;
		table[i].polynom = table[i + 1].polynom;
		table[i].p = table[i + 1].p;
	}
	count--;
}

void TOtable::Del(const int key)
{
	if (IsEmpty()) throw("table is empty");
	if (key<0 || key>count) throw("Uncorrect index");
	for (int i = key-1; i < count; i++)
	{
		table[i].key = table[i + 1].key;
		table[i].polynom = table[i + 1].polynom;
		table[i].p = table[i + 1].p;
	}
	count--;
}

string TOtable::ReturnKey(int key)
{
	if (IsEmpty()) throw("table is empty");
	if (key<0 || key>count) throw("Uncorrect index");
	return table[key - 1].key;
}
TPolynom TOtable::ReturnPolynom(const string key)
{
	if (IsEmpty()) throw("table is empty");
	TPolynom res;
	for (int i = 0; i < count; i++)
	{
		if (table[i].key == key)
			res = table[i].p;
	}
	return res;
}
TPolynom TOtable::Arifmetic(const string str)
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
//string TOtable::ReturnPolynom(int key)
//{
//	if (IsEmpty()) throw("table is empty");
//	if (key<0 || key>count) throw("Uncorrect index");
//	return table[key - 1].polynom;
//}

TOtable& TOtable::operator=(const TOtable & t)
{
	delete[] table;
	table = new TNode[MAX];
	count = 0;
	for (int i = 0; i < t.GetSize(); i++)
	{
		table[i].key = t.table[i].key;
		table[i].polynom = t.table[i].polynom;
		table[i].p = table[i + 1].p;
		count++;
	}

	return *this;
}

ostream & operator<<(ostream & out, TOtable & t)
{
	cout << endl;
	if (t.count == 0)
	{
		out << "	+=============================================================+" << endl;
		out << "	|                       table is empty                         |" << endl;
		out << "	+=============================================================+" << endl;
		return out;
	}
	cout << "+======================================================================+" << endl;
	cout << left << "|" << setw(30) << "Nomber:" << "|" << setw(30) << setw(30) << "Name:" << "|" << setw(30) << "Polynom:" << endl;
	cout << "+======================================================================+" << endl;
	for (int i = 0; i <t.GetSize(); i++)
	{
		cout << "|" << setw(30) << i+1 << "|" << setw(30) << t.table[i].key << "|" << setw(30) << t.table[i].polynom  << endl;
		cout << "+----------------------------------------------------------------------+" << endl;

	}
	cout << endl;
	return out;
}
