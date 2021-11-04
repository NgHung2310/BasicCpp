#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class Person
{
protected:
	string name, address;
	long int phone;
public:
	Person()
	{
		this->name = "";
		this->address = "";
		this->phone = 0;
	}
	Person(string name, string address, long int phone)
	{
		this->name = name;
		this->address = address;
		this->phone = phone;
	}
	~Person() {}
	string get_name()
	{
		return name;
	}
};
class Officer :public virtual Person
{
protected:
	float salary;
public:
	Officer()
	{
		this->salary = 0;
	}
	Officer(string name, string address, long int phone, float salary) :Person(name, address, phone)
	{
		this->salary = salary;
	}
	~Officer() {}
	float get_salary()
	{
		return salary;
	}
};
class Student :public virtual Person
{
protected:
	float fee;
public:
	Student()
	{
		this->fee = 0;
	}
	Student(string name, string address, long int phone, float fee) :Person(name, address, phone)
	{
		this->fee = fee;
	}
	~Student() {}
};
class OffStudent :public Officer, public Student
{
public:
	OffStudent() {}
	OffStudent(string name, string address, long int phone, float salary, float fee)
		:Officer( name,  address,   phone,  salary),Student( name,  address,   phone,  fee), Person( name,  address,  phone)
	{}
	void OutScreen()
	{
		cout << "Ten: " << name
			<< "\t\tDia chi: " << address
			<< "\t\tSDT: " << phone
			<< "\t\tLuong: " << salary
			<< "\tHoc phi: " << fee << endl;
	}
};
int main()
{
	int n; cout << "-----Nhap so luong OffStudent: "; cin >> n;
	string name;
	string address;
	long int phone;
	float salary;
	float fee;
	OffStudent *osd=new OffStudent[n];
	//nhap ds
	for (int i = 0; i < n; i++)
	{
		cout << "\n-----Nhap thong tin doi tuong thu " << i + 1 << ": " << endl;
		cout << "Nhap ten: "; cin.ignore(); getline(cin, name);
		cout << "Nhap dia chi: "; getline(cin, address);
		cout << "Nhap SDT: "; cin >> phone;
		cout << "Nhap luong: "; cin >> salary;
		cout << "Nhap hoc phi: "; cin >> fee;
		osd[i]= OffStudent(name, address, phone, salary, fee);
	}
	//xuat ds
	cout << "\n-----DS vua nhap: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". "; 
		osd[i].OutScreen();
	}
	//tim nguoi salary=5
	cout << "\n-----Nguoi co luong 5tr: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (osd[i].get_salary() == 5)
			osd[i].OutScreen();
	}
	//Sap xep theo ten
	for (int i = 0; i < n-1; i++)
	{
		if (osd[i].get_name() > osd[i + 1].get_name())
		{
			OffStudent tg = osd[i];
			osd[i] = osd[i + 1];
			osd[i + 1] = tg;
		}
	}
	cout << "\n-----DS sau sap xep: " << endl;
	for (int i = 0; i < n; i++)
	{
		osd[i].OutScreen();
	}
}