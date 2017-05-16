#include<iostream>
#include"polinom.h"
#include<string>
#include<locale.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string str;
	TList<TPolynom> Plist;
	int answer=12;
	while (answer != 0)
	{
		system("cls");
		cout << "����:" << endl;
		cout << "1:���� ���������"<<endl;
		cout << "2:��������� ��������" << endl;
		cout << "3:������ � ����������" << endl;
		cout << "0:�����" << endl;
		cout << "::";
		cin >> answer;
		switch (answer)
		{
		case(1):
		{
			system("cls");
			cout<<"� �������� ���������� ���������� x,y,z" << endl;
			cout<< "C������ ������ ���������� �� ����������� 9 � �� ����� ���� �������������" << endl;
			cout << "������� ���������� ������������ ����� �� ����������" << endl;
			cout << endl;
			cout << "������� �������:" << endl;
			cout<< "::";
			cin >> str;
			TPolynom a(str);
			Plist.InSertLast(a);
			system("pause");
			break;
		}
		case(2):
		{
			system("cls");
			if (Plist.GetSize() == 0)
			{
				cout << "��� �������� ���������" << endl;
				system("pause");
				break;
			}
			cout << "��������� ��������:" << endl;
			int a = Plist.GetSize();

			for ( int i = 0; i < Plist.GetSize(); i++)
			{
				cout << i+1 << ":" << Plist.GetElem(i).ToString() << endl;
			}
			system("pause");
			break;
		}
		case(3):
		{
			int a=12;
			while (a != 0)
			{
				system("cls");
				cout << "������� ��������:" << endl;
				for (int i = 0; i < Plist.GetSize(); i++)
				{
					cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
				}
				cout << endl;
				cout << ":::::::::::::::::::::::::::::::::::::::::::" << endl;
				cout << "������ � ����������:" << endl;
				cout << "1:��������" << endl;
				cout << "2:���������" << endl;
				cout << "3:���������" << endl;
				cout << "4:��������� �� �����" << endl;
				cout << "5:���������� � �����" << endl;
				cout << "6:�����������������" << endl;
				cout << "0:��������� � ����" << endl;
				cout << "::";
				cin >> a;
				switch (a)
				{
				case(1):
				{
					int x,y;
					system("cls");
					cout << "������� ��������:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "�������� �������� ��� ��������:" << endl;
						cout << "������ ������� :: ";
						cin >> x;
						cout << "������ ������� :: ";
						cin >> y;
					TPolynom res;
					res = Plist.GetElem(x - 1) + Plist.GetElem(y - 1);
					//Plist.InSertLast(res);
					cout << "����� ::";
					cout << Plist.GetElem(x - 1).ToString() << " + " << Plist.GetElem(y - 1) << " = " << res.ToString() << endl;
					system("pause");
					break;
				}
				case(2):
				{
					int x, y;
					system("cls");
					cout << "������� ��������:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "�������� �������� ��� ���������:" << endl;
					cout << "������ ������� :: ";
					cin >> x;
					cout << "������ ������� :: ";
					cin >> y;
					TPolynom res;
					res = Plist.GetElem(x - 1) * Plist.GetElem(y - 1);
					//Plist.InSertLast(res);
					cout << "����� ::";
					cout << Plist.GetElem(x - 1).ToString() << " * " << Plist.GetElem(y - 1) << " = " << res.ToString() << endl;
					system("pause");
					break;
				}
				case(3):
				{
					int x, y;
					system("cls");
					cout << "������� ��������:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "�������� �������� ��� ���������:" << endl;
					cout << "������ ������� :: ";
					cin >> x;
					cout << "������ ������� :: ";
					cin >> y;
					TPolynom res;
					res = Plist.GetElem(x - 1) - Plist.GetElem(y - 1);
					//Plist.InSertLast(res);
					cout << "����� ::";
					cout << Plist.GetElem(x - 1).ToString() << " - " << Plist.GetElem(y - 1) << " = " << res.ToString() << endl;
					system("pause");
					break;
				}
				case(4):
				{
					int x;
					double c;
					system("cls");
					cout << "������� ��������:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "�������� ������� ��� ��������� �� �����:" << endl;
					cout << "����� ������� :: ";
					cin >> x;
					cout << "������� �����";
					cout << " :: ";
					cin >> c;
					TPolynom res;
					res = Plist.GetElem(x - 1) *c;
					//Plist.InSertLast(res);
					cout << "����� ::";
					cout << Plist.GetElem(x - 1).ToString() << " * " << c << " = " << res.ToString() << endl;
					system("pause");
					break;
				}
				case(5):
				{
					int b;
					double x, y, z;
					system("cls");
					cout << "������� ��������:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "�������� ������� ��� ���������� � �����:" << endl;
					cout << "����� �������� :: ";
					cin >> b;
					cout << "������� ���������� �����" << endl;
					cout << "x::";
					cin >> x;
					cout << endl;
					cout << "y::";
					cin >> y;
					cout << endl;
					cout << "z::";
					cin >> z;
					cout << endl;
					double res;
					res = Plist.GetElem(b - 1).ComputationAtPoint(x, y, z);
					cout << "����� ::";
					cout << res << endl;
					system("pause");
					break;
				}
				case(6):
				{
					int x;
					double c;
					system("cls");
					cout << "������� ��������:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "�������� ������� ��� ��������� �� �����:" << endl;
					cout << "����� ������� :: ";
					cin >> x;
					TPolynom res, tmp;
					tmp = Plist.GetElem(x - 1);
					res = Plist.GetElem(x - 1);
					res=res.diff();
					//Plist.InSertLast(res);
					cout << "����� ::";
					cout << "d["<<tmp.ToString()<<"] = "<<res.ToString() << endl;
					system("pause");
					break;
				}
				default:
					break;
				}
			}
		}
		default:
			break;
		}
	}
	return 0;
}