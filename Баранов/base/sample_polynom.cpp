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
		cout << "Меню:" << endl;
		cout << "1:Ввод полиномов"<<endl;
		cout << "2:Введенные полиномы" << endl;
		cout << "3:Работа с полиномами" << endl;
		cout << "0:Выход" << endl;
		cout << "::";
		cin >> answer;
		switch (answer)
		{
		case(1):
		{
			system("cls");
			cout<<"В Полиноме учавствует переменные x,y,z" << endl;
			cout<< "Cтепень каждой переменной не превосходит 9 и не может быть отрицательной" << endl;
			cout << "Степень переменной записывается сразу за переменной" << endl;
			cout << endl;
			cout << "Введите полином:" << endl;
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
				cout << "Нет введеных полиномов" << endl;
				system("pause");
				break;
			}
			cout << "Введенные Полиномы:" << endl;
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
				cout << "Имеющие полиномы:" << endl;
				for (int i = 0; i < Plist.GetSize(); i++)
				{
					cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
				}
				cout << endl;
				cout << ":::::::::::::::::::::::::::::::::::::::::::" << endl;
				cout << "Работа с полиномами:" << endl;
				cout << "1:Сложение" << endl;
				cout << "2:Умножение" << endl;
				cout << "3:Вычитание" << endl;
				cout << "4:Умножение на число" << endl;
				cout << "5:Вычисление в точке" << endl;
				cout << "6:Дифференцирование" << endl;
				cout << "0:Вернуться к меню" << endl;
				cout << "::";
				cin >> a;
				switch (a)
				{
				case(1):
				{
					int x,y;
					system("cls");
					cout << "Имеющие полиномы:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "Выберите полиномы для сложения:" << endl;
						cout << "Первый полином :: ";
						cin >> x;
						cout << "Второй полином :: ";
						cin >> y;
					TPolynom res;
					res = Plist.GetElem(x - 1) + Plist.GetElem(y - 1);
					//Plist.InSertLast(res);
					cout << "Ответ ::";
					cout << Plist.GetElem(x - 1).ToString() << " + " << Plist.GetElem(y - 1) << " = " << res.ToString() << endl;
					system("pause");
					break;
				}
				case(2):
				{
					int x, y;
					system("cls");
					cout << "Имеющие полиномы:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "Выберите полиномы для умножения:" << endl;
					cout << "Первый полином :: ";
					cin >> x;
					cout << "Второй полином :: ";
					cin >> y;
					TPolynom res;
					res = Plist.GetElem(x - 1) * Plist.GetElem(y - 1);
					//Plist.InSertLast(res);
					cout << "Ответ ::";
					cout << Plist.GetElem(x - 1).ToString() << " * " << Plist.GetElem(y - 1) << " = " << res.ToString() << endl;
					system("pause");
					break;
				}
				case(3):
				{
					int x, y;
					system("cls");
					cout << "Имеющие полиномы:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "Выберите полиномы для вычитания:" << endl;
					cout << "Первый полином :: ";
					cin >> x;
					cout << "Второй полином :: ";
					cin >> y;
					TPolynom res;
					res = Plist.GetElem(x - 1) - Plist.GetElem(y - 1);
					//Plist.InSertLast(res);
					cout << "Ответ ::";
					cout << Plist.GetElem(x - 1).ToString() << " - " << Plist.GetElem(y - 1) << " = " << res.ToString() << endl;
					system("pause");
					break;
				}
				case(4):
				{
					int x;
					double c;
					system("cls");
					cout << "Имеющие полиномы:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "Выберите полином для умножения на число:" << endl;
					cout << "Номер полином :: ";
					cin >> x;
					cout << "Введите число";
					cout << " :: ";
					cin >> c;
					TPolynom res;
					res = Plist.GetElem(x - 1) *c;
					//Plist.InSertLast(res);
					cout << "Ответ ::";
					cout << Plist.GetElem(x - 1).ToString() << " * " << c << " = " << res.ToString() << endl;
					system("pause");
					break;
				}
				case(5):
				{
					int b;
					double x, y, z;
					system("cls");
					cout << "Имеющие полиномы:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "Выберите полином для вычисления в точке:" << endl;
					cout << "Номер полинома :: ";
					cin >> b;
					cout << "Введите координаты точки" << endl;
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
					cout << "Ответ ::";
					cout << res << endl;
					system("pause");
					break;
				}
				case(6):
				{
					int x;
					double c;
					system("cls");
					cout << "Имеющие полиномы:" << endl;
					for (int i = 0; i < Plist.GetSize(); i++)
					{
						cout << i + 1 << ":" << Plist.GetElem(i).ToString() << endl;
					}
					cout << endl;
					cout << endl;
					cout << "Выберите полином для умножения на число:" << endl;
					cout << "Номер полином :: ";
					cin >> x;
					TPolynom res, tmp;
					tmp = Plist.GetElem(x - 1);
					res = Plist.GetElem(x - 1);
					res=res.diff();
					//Plist.InSertLast(res);
					cout << "Ответ ::";
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