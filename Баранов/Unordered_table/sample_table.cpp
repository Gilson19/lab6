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
		cout << "1.������ � ��������������� ��������" << endl;
		cout << "2.������ � ������������� ��������" << endl;
		cout << "3.������ � ���-��������" << endl;
		cout << "0.�����" << endl;
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
		cout << "����:" << endl;
		cout << "1.�������� ������� � �������"<<endl;
		cout << "2.����� �� �����" << endl;
		cout << "3.�������� �� �����" << endl;
		cout << "4.������ �������" << endl;
		cout << "5.�������������� ��������" << endl;
		cout << "0.�����" << endl;
		cout << "::";
		cin >> answer;
		switch (answer)
		{
		case (1):
		{
			system("cls");
			cout << "������� �������" << endl;
			string b="";
			while (b == "")
			{
				cout << "::";
				cin >> b;
				if (b == "") cout << "������,��� ������ ������ �������, ��������� ����" << endl;
			}
			string a;
			cout << "������� ��� ��������" << endl;
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
					cout << "����� ��� ��� ������������,���������� ������ ���" << endl;
					cout << "������� ��� ��������" << endl;
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
			cout << "������� ���� ��� ������" << endl;
			cout << "::";
			cin >> a;
			if (table.Search(a) == "") cout << "�� ����� ����� ������ �� �������" << endl;
			else
			{
				res = table.Search(a);
				cout << "��������� ��������" << endl;
				cout << "::" << res<<endl;
			}
			system("pause");
			break;

		}
		case(3):
		{
			system("cls");
			string a;
			cout << "������� ���� ��� ��������" << endl;
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
			cout << "������� �������������� ���������, ��������� ����� ��������� �� �������" << endl;
			string a;
			cin >> a;
			cout <<"�������������� ���������: "<< a << endl;
			TPostfix postfix(a);
			postfix.ToPostfix();
			cout << "����������� �����: " << postfix.GetPostfix()<<endl;
			TPolynom res= table.Arifmetic(postfix.GetPostfix());
			cout<<"��������� ::  " << res.ToString() << endl;
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
		cout << "����:" << endl;
		cout << "1.�������� ������� � �������" << endl;
		cout << "2.����� �� �����" << endl;
		cout << "3.�������� �� �����" << endl;
		cout << "4.������ �������" << endl;
		cout << "5.�������������� ��������" << endl;
		cout << "0.�����" << endl;
		cout << "::";
		cin >> answer;
		switch (answer)
		{
		case (1):
		{
			system("cls");
			cout << "������� �������" << endl;
			string b = "";
			while (b == "")
			{
				cout << "::";
				cin >> b;
				if (b == "") cout << "������,��� ������ ������ �������, ��������� ����" << endl;
			}
			string a;
			cout << "������� ��� ��������" << endl;
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
					cout << "����� ��� ��� ������������,���������� ������ ���" << endl;
					cout << "������� ��� ��������" << endl;
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
			cout << "������� ���� ��� ������" << endl;
			cout << "::";
			cin >> a;
			if (table.Search(a) == "") cout << "�� ����� ����� ������ �� �������" << endl;
			else
			{
				res = table.Search(a);
				cout << "��������� ��������" << endl;
				cout << "::" << res << endl;
			}
			system("pause");
			break;

		}
		case(3):
		{
			system("cls");
			string a;
			cout << "������� ���� ��� ��������" << endl;
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
			cout << "������� �������������� ���������, ��������� ����� ��������� �� �������" << endl;
			string a;
			cin >> a;
			cout << "�������������� ���������: " << a << endl;
			TPostfix postfix(a);
			postfix.ToPostfix();
			cout << "����������� �����: " << postfix.GetPostfix() << endl;
			TPolynom res = table.Arifmetic(postfix.GetPostfix());
			cout << "��������� ::  " << res.ToString() << endl;
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
		cout << "����:" << endl;
		cout << "1.�������� ������� � �������" << endl;
		cout << "2.����� �� �����" << endl;
		cout << "3.�������� �� �����" << endl;
		cout << "4.������ �������" << endl;
		cout << "5.�������������� ��������" << endl;
		cout << "0.�����" << endl;
		cout << "::";
		cin >> answer;
		switch (answer)
		{
		case (1):
		{
			system("cls");
			cout << "������� �������" << endl;
			string b = "";
			while (b == "")
			{
				cout << "::";
				cin >> b;
				if (b == "") cout << "������,��� ������ ������ �������, ��������� ����" << endl;
			}
			string a;
			cout << "������� ��� ��������" << endl;
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
					cout << "����� ��� ��� ������������,���������� ������ ���" << endl;
					cout << "������� ��� ��������" << endl;
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
			cout << "������� ���� ��� ������" << endl;
			cout << "::";
			cin >> a;
			if (table.Search(a) == "") cout << "�� ����� ����� ������ �� �������" << endl;
			else
			{
				res = table.Search(a);
				cout << "��������� ��������" << endl;
				cout << "::" << res << endl;
			}
			system("pause");
			break;

		}
		case(3):
		{
			system("cls");
			string a;
			cout << "������� ���� ��� ��������" << endl;
			cout << "::";
			cin >> a;
			if (table.Search(a) == "") {
				cout << "��� ������ �������� � ������ ������" << endl;
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
			cout << "������� �������������� ���������, ��������� ����� ��������� �� �������" << endl;
			string a;
			cin >> a;
			cout << "�������������� ���������: " << a << endl;
			TPostfix postfix(a);
			postfix.ToPostfix();
			cout << "����������� �����: " << postfix.GetPostfix() << endl;
			TPolynom res = table.Arifmetic(postfix.GetPostfix());
			cout << "��������� ::  " << res.ToString() << endl;
			system("pause");
			break;
		}
		default:
			break;
		}
	}
}
