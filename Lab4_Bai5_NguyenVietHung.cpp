#include<iostream>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<string>
using namespace std;
class person
{
protected:
	string name, address;
	long int phone;
public:
	person()
	{
		this->name = "";
		this->address = "";
		this->phone = 0;
	}
	person(string name, string address, long int phone)
	{
		this->name = name;
		this->address = address;
		this->phone = phone;
	}
	~person() {}
};
class officer :public person
{
protected:
	float salary;//milion
public:
	officer()
	{
		this->salary = 0;
	}
	officer(string name, string address, long int phone, float salary) :person(name, address, phone)
	{
		this->salary = salary;
	}
	~officer() {}
};
class manager :public officer
{
	float extra;
public:
	manager()
	{
		this->extra = 0;
	}
	manager(string name, string address, long int phone, float salary, float extra) :officer(name, address, phone, salary)
	{
		this->extra = extra;
	}
	~manager() {}
	void nhap()
	{
		cout << "Nhap ten: "; cin.ignore(); getline(cin, name);
		cout << "Nhap dia chi: "; getline(cin, address);
		cout << "Nhap sdt: "; cin >> phone;
		cout << "Nhap luong: "; cin >> salary;
		cout << "Nhap phu cap: "; cin >> extra;
	}
	void xuat()
	{
		cout << "Ten: " << name
			<< "\t\tDia chi: " << address
			<< "\t\tSDT: " << phone
			<< "\tLuong: " << salary
			<< "\tPhu cap: " << extra << endl;
	}
	string get_add()
	{
		return address;
	}
	float get_salary()
	{
		return salary;
	}
};
int main()
{
	int n; cout << "-----Nhap so doi tuong: "; cin >> n;
	manager *mng = new manager[n];
//Nhap ds
	for (int i = 0; i < n; i++)
	{
		cout << "\n-----Thong tin doi tuong thu " << i + 1 << " : " << endl;
		mng[i].nhap();
	}
//Xuat ds
	cout << "\n-----DS vua nhap: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". "; mng[i].xuat();
	}
//Loc doi tuong o "Ha Noi" vaf luong khac 10tr
	cout << "\n-----Doi tuong o \"Ha Noi\" va salary khac 10tr:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (mng[i].get_add() != "Ha Noi"&&mng[i].get_salary() != 10)
			mng[i].xuat();
	}
}