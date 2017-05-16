#include "htable.h"

int THtable::hashfunc(string key)
{
	//вычисление хэш функции по сумме значений таблицы АСКИ.
	//
	int res = 0;
	for (int i = 0; i < key.length(); i++)
	{
		res += (int)key[i];
	}
	return res % MAX_SIZE_H;
}

bool THtable::IsDigit(char c)
{
	if (c >= '0' && c <= '9') return true;
	return false;
}

THtable::THtable()
{
	table = new TKeyPolynom[MAX_SIZE_H];
	for (int i = 0; i < MAX_SIZE_H; i++)
		table[i].SetNext(nullptr);//устаналиваем по нулям(нуллптр) для дальшейшей работы
	count = 0;
}

THtable::THtable(const THtable & h)
{
	table = new TKeyPolynom[MAX_SIZE_H];
	for (int i = 0; i < MAX_SIZE_H; i++)
		table[i].SetNext(nullptr);//устаналиваем по нулям(нуллптр) для дальшейшей работы
	count = 0;
	for (int i = 0; i < MAX_SIZE_H; i++)
	{
		TKeyPolynom *tmp = h.table[i].GetNext();
		if (tmp!= nullptr)
		{
			string key = tmp->GetKey();
			int hash = hashfunc(key);
			TKeyPolynom *node=new TKeyPolynom;
			node->SetKey(tmp->GetKey());
			node->SetValue(tmp->GetValue());
			node->SetPolynom(tmp->GetPolynom());
			table[hash].SetNext(node);
		}
	}
		
}

void THtable::Add(const string name, const string polynom)
{
	int hash = hashfunc(name); //вызываем хэш функцию для данного ключа(имени полинома)
	TKeyPolynom *tmp = table[hash].GetNext();
	if (tmp != nullptr)
	{
		if (tmp->GetKey() == name)  throw("This elem with key have in table");
	}

		TKeyPolynom *node = new TKeyPolynom;//нужно node*, создаем узел 
		//установка значений
		node->SetKey(name);
		node->SetValue(polynom);
		TPolynom res(polynom);
		node->SetPolynom(res);
		//устанавливаем на следующее значение  
		node->SetNext(table[hash].GetNext());
		table[hash].SetNext(node); // устанавливаем созданное звено, при этом используется индекс, которое вернула хэш функция
		count++;
}

string THtable::Search(const string name)
{
	if (IsEmpty()) return "";
	int key = hashfunc(name);
	string res;
	TKeyPolynom *tmp = table[key].GetNext();
	if (tmp == nullptr) return "";
	while ((tmp->GetNext() != nullptr) && (tmp->GetKey() != name))
		{
			tmp = tmp->GetNext();
		}
	if (tmp->GetKey() == name)
	{
		res = tmp->GetValue();
		return res;
	}
	else return "";
	//return "";
}

void THtable::Del(const string name)
{
	TKeyPolynom *tmp = table[hashfunc(name)].GetNext(); //текущий
	/*if(tmp->GetNext()!=nullptr)*/
	TKeyPolynom *next = tmp->GetNext();//следующий
	if (tmp->GetKey() == name)//если текущий равен по ключ, то удаляем
	{
		table[hashfunc(name)].SetNext(next);
		delete tmp;
		count--;
		return;
	}
	else
	{
		//пока не нашли по ключу  или не дошли до конца
		while (next->GetKey() != name && next->GetNext() != nullptr)
		{
			next = next->GetNext();
			tmp = tmp->GetNext();
		}
		if (next->GetKey() == name)
		{
			tmp->SetNext(next->GetNext());
			delete next;
			count--;
			return;
		}
	 return;
	}
}

TPolynom THtable::ReturnPolynom(const string key)
{
	int hash = hashfunc(key);
	TPolynom res;
	TKeyPolynom *tmp = table[hash].GetNext();
	//if (tmp == nullptr) return "";
	while ((tmp->GetNext() != nullptr) && (tmp->GetKey() != key))
	{
		tmp = tmp->GetNext();
	}
	if (tmp->GetKey() == key)
	{
		res = tmp->GetPolynom();
		return res;
	}
}

TPolynom THtable::Arifmetic(const string str)
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

THtable::~THtable()
{
	TKeyPolynom *next, *tmp;
	for (int i = 0; i < MAX_SIZE_H; i++)
	{
		tmp = table[i].GetNext();
		while (tmp != nullptr)
		{
			next = tmp;
			tmp=tmp->GetNext();
			delete next;
		}
	}
	delete[] table;
}


ostream & operator<<(ostream & out, THtable & t)
{
	TKeyPolynom *tmp;
	int j = 0;
	if (t.count == 0)
	{
		out << "	+=============================================================+" << endl;
		out << "	|                       table is empty                         |" << endl;
	    out << "	+=============================================================+" << endl;
		return out;
	}
	else
	{
		out <<"+=============================================================+" << endl;
		out  <<"|" << setw(30) << "Name:" << "|" << setw(30) << "Polynom:" << "|" << endl;
		out <<"+=============================================================+" << endl;
		for (int i = 0; i < MAX_SIZE_H; i++)
		{
			tmp = t.table[i].GetNext();
			if (tmp == nullptr) continue;
			cout << "+=============================================================+" << endl;
			out << setw(30) << tmp->GetKey() << setw(30);
			//cout << "+======================================================================+" << endl;
			while (tmp != nullptr)
			{
				j++;
				if (j >= 2)
				{
					cout << "+=============================================================+" << endl;
					out << setw(30)<< tmp->GetKey() << setw(30);
					out << setw(30) << tmp->GetValue() << setw(30) << endl;
					cout << "+=============================================================+" << endl;
					tmp = tmp->GetNext();
				}
				else
				{
					out << setw(30) << tmp->GetValue() << setw(30) << endl;
					tmp = tmp->GetNext();
					cout << "+=============================================================+" << endl;
				}
			}
			j = 0;
		}
		return out;
	}
}
