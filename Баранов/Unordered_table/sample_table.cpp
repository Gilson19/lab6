#include"utable.h"
#include"htable.h"
#include"otable.h"
#include<locale.h>
#include"postfix.h"
void WorkWithUtable();
void WorkWithOtable();
void WorkWithHtable();
int main()
{
	setlocale(LC_ALL, "Russian");
	int answer = 12;
	while (answer != 0)
	{
		system("cls");
		cout << "1.Работа с неупорядоченной таблицой" << endl;
		cout << "2.Работа с упорядоченной таблицей" << endl;
		cout << "3.Работа с хэш-таблицей" << endl;
		cout << "0.Выход" << endl;
		cout << "::";
		cin >> answer;
		switch (answer)
		{
		case(1):
		{
			system("cls");
			WorkWithUtable();
			break;
		}
		case(2):
		{
			system("cls");
			WorkWithOtable();
			break;
		}
		case(3):
		{
			system("cls");
			WorkWithHtable();
			break;
		}
		default:
			break;
		}
	}
	system("pause");
}

void WorkWithUtable()
{
	TUtable table;
	int answer = 12;
	while (answer != 0)
	{
		system("cls");
		cout << "Меню:" << endl;
		cout << "1.Добавить элемент в таблицу"<<endl;
		cout << "2.Поиск по ключу" << endl;
		cout << "3.Удаление по ключу" << endl;
		cout << "4.Печать таблицы" << endl;
		cout << "5.Арифметические операции" << endl;
		cout << "0.Выход" << endl;
		cout << "::";
		cin >> answer;
		switch (answer)
		{
		case (1):
		{
			system("cls");
			cout << "Введите полином" << endl;
			string b="";
			while (b == "")
			{
				cout << "::";
				cin >> b;
				if (b == "") cout << "Ошибка,был введен пустой полином, повторите ввод" << endl;
			}
			string a;
			cout << "Введите имя полинома" << endl;
			cout << "::";
			cin >> a;
			if (table.Search(a) == "")
			{
				table.Add(a, b);
			}
			else
			{
				while (table.Search(a) != "")
				{
					system("cls");
					cout << "Такое имя уже используется,придумаете другое имя" << endl;
					cout << "Введите имя полинома" << endl;
					cout << "::";
					cin >> a;
				}
				table.Add(a, b);
			}
			system("pause");
			break;

		}
		case(2):
		{
			system("cls");
			string a,res;
			cout << "Введите ключ для поиска" << endl;
			cout << "::";
			cin >> a;
			if (table.Search(a) == "") cout << "По этому ключу ничего не найдено" << endl;
			else
			{
				res = table.Search(a);
				cout << "Найденное значение" << endl;
				cout << "::" << res<<endl;
			}
			system("pause");
			break;

		}
		case(3):
		{
			system("cls");
			string a;
			cout << "Введите ключ для удаления" << endl;
			cout << "::";
			cin >> a;
			table.Del(a);
			system("pause");
			break;
		}
		case(4):
		{
			system("cls");
			cout << table;
			system("pause");
			break;
		}
		case(5):
		{
			system("cls");
			cout << table<<endl;
			cout << "Введите алгебраическое выражение, используя имена полиномов из таблицы" << endl;
			string a;
			cin >> a;
			cout <<"Арифмитическое выражение: "<< a << endl;
			TPostfix postfix(a);
			postfix.ToPostfix();
			cout << "Постфиксная форма: " << postfix.GetPostfix()<<endl;
			TPolynom res= table.Arifmetic(postfix.GetPostfix());
			cout<<"Результат ::  " << res.ToString() << endl;
			system("pause");
			break;
		}
		default:
			break;
		}
	}
}

void WorkWithOtable()
{
	TOtable table;
	int answer = 12;
	while (answer != 0)
	{
		system("cls");
		cout << "Меню:" << endl;
		cout << "1.Добавить элемент в таблицу" << endl;
		cout << "2.Поиск по ключу" << endl;
		cout << "3.Удаление по ключу" << endl;
		cout << "4.Печать таблицы" << endl;
		cout << "5.Арифметические операции" << endl;
		cout << "0.Выход" << endl;
		cout << "::";
		cin >> answer;
		switch (answer)
		{
		case (1):
		{
			system("cls");
			cout << "Введите полином" << endl;
			string b = "";
			while (b == "")
			{
				cout << "::";
				cin >> b;
				if (b == "") cout << "Ошибка,был введен пустой полином, повторите ввод" << endl;
			}
			string a;
			cout << "Введите имя полинома" << endl;
			cout << "::";
			cin >> a;
			if (table.Search(a) == "")
			{
				table.Add(a, b);
			}
			else
			{
				while (table.Search(a) != "")
				{
					system("cls");
					cout << "Такое имя уже используется,придумаете другое имя" << endl;
					cout << "Введите имя полинома" << endl;
					cout << "::";
					cin >> a;
				}
				table.Add(a, b);
			}
			system("pause");
			break;

		}
		case(2):
		{
			system("cls");
			string a, res;
			cout << "Введите ключ для поиска" << endl;
			cout << "::";
			cin >> a;
			if (table.Search(a) == "") cout << "По этому ключу ничего не найдено" << endl;
			else
			{
				res = table.Search(a);
				cout << "Найденное значение" << endl;
				cout << "::" << res << endl;
			}
			system("pause");
			break;

		}
		case(3):
		{
			system("cls");
			string a;
			cout << "Введите ключ для удаления" << endl;
			cout << "::";
			cin >> a;
			table.Del(a);
			system("pause");
			break;
		}
		case(4):
		{
			system("cls");
			cout << table;
			system("pause");
			break;
		}
		case(5):
		{
			system("cls");
			cout << table << endl;
			cout << "Введите алгебраическое выражение, используя имена полиномов из таблицы" << endl;
			string a;
			cin >> a;
			cout << "Арифмитическое выражение: " << a << endl;
			TPostfix postfix(a);
			postfix.ToPostfix();
			cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
			TPolynom res = table.Arifmetic(postfix.GetPostfix());
			cout << "Результат ::  " << res.ToString() << endl;
			system("pause");
			break;
		}
		default:
			break;
		}
	}
}

void WorkWithHtable()
{
	THtable table;
	int answer = 12;
	while (answer != 0)
	{
		system("cls");
		cout << "Меню:" << endl;
		cout << "1.Добавить элемент в таблицу" << endl;
		cout << "2.Поиск по ключу" << endl;
		cout << "3.Удаление по ключу" << endl;
		cout << "4.Печать таблицы" << endl;
		cout << "5.Арифметические операции" << endl;
		cout << "0.Выход" << endl;
		cout << "::";
		cin >> answer;
		switch (answer)
		{
		case (1):
		{
			system("cls");
			cout << "Введите полином" << endl;
			string b = "";
			while (b == "")
			{
				cout << "::";
				cin >> b;
				if (b == "") cout << "Ошибка,был введен пустой полином, повторите ввод" << endl;
			}
			string a;
			cout << "Введите имя полинома" << endl;
			cout << "::";
			cin >> a;
			if (table.Search(a) == "")
			{
				table.Add(a, b);
			}
			else
			{
				while (table.Search(a) != "")
				{
					system("cls");
					cout << "Такое имя уже используется,придумаете другое имя" << endl;
					cout << "Введите имя полинома" << endl;
					cout << "::";
					cin >> a;
				}
				table.Add(a, b);
			}
			system("pause");
			break;

		}
		case(2):
		{
			system("cls");
			string a, res;
			cout << "Введите ключ для поиска" << endl;
			cout << "::";
			cin >> a;
			if (table.Search(a) == "") cout << "По этому ключу ничего не найдено" << endl;
			else
			{
				res = table.Search(a);
				cout << "Найденное значение" << endl;
				cout << "::" << res << endl;
			}
			system("pause");
			break;

		}
		case(3):
		{
			system("cls");
			string a;
			cout << "Введите ключ для удаления" << endl;
			cout << "::";
			cin >> a;
			if (table.Search(a) == "") {
				cout << "Нет такого значения с данным именем" << endl;
				system("pause");
				break;
			}
			table.Del(a);
			system("pause");
			break;
		}
		case(4):
		{
			system("cls");
			cout << table;
			system("pause");
			break;
		}
		case(5):
		{
			system("cls");
			cout << table << endl;
			cout << "Введите алгебраическое выражение, используя имена полиномов из таблицы" << endl;
			string a;
			cin >> a;
			cout << "Арифмитическое выражение: " << a << endl;
			TPostfix postfix(a);
			postfix.ToPostfix();
			cout << "Постфиксная форма: " << postfix.GetPostfix() << endl;
			TPolynom res = table.Arifmetic(postfix.GetPostfix());
			cout << "Результат ::  " << res.ToString() << endl;
			system("pause");
			break;
		}
		default:
			break;
		}
	}
}
