#include<iostream>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<string>
using namespace std;
class mydate
{
protected:
	int d, m, y;
public:
	mydate()
	{
		this->d = this->m = this->y = 0;
	}
	mydate(int d, int m, int y)
	{
		this->d = d;
		this->m = m;
		this->y = y;
	}
	~mydate() {}
	void xuat()
	{
		cout << "Ngay sinh: " << d << "/" << m << "/" << y ;
	}
	int get_y()
	{
		return y;
	}
};
class person:public mydate
{
	string name;
	string address;
	long int phone;
public:
	person():mydate()
	{
		this->address = "";
		this->name = "";
		this->phone = 0;
	}
	person(int d,int m,int y,string name,string address,long int phone):mydate(d,m,y)
	{
		this->address = address;
		this->name = name;
		this->phone = phone;
	}
	~person() {}
	bool operator>(person ps)
	{
		if (get_y() > ps.get_y())
			return 1;
		else 
			return 0;
	}
	void nhap()
	{
		cout << "Nhap ngay thang nam sinh(dd/mm/yyy): "; cin >> d >> m >> y;
		cout << "Nhap ten: "; cin.get(); getline(cin, name);
		cout << "Nhap dia chi: "; getline(cin, address);
		cout << "Nhap so dien thoai: "; cin >> phone;
	}
	void xuat()
	{
		mydate::xuat();
		cout << "\tTen: " << name 
			<< "\t\tDia chi: " << address 
			<< "\t\t\tSo dien thoai: " << phone << endl;
	}
};
int main()
{
	int n; cout << "Nhap so nguoi: "; cin >> n;
	person *ps = new person[n];
//Nhap tt
	for (int i = 0; i < n; i++)
	{
		cout << "-----Nhap tt nguoi thu " << i + 1 << " : " << endl;
		ps[i].nhap();
	}
//Xuat tt
	cout << "\n-----DS nguoi cua nhap: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". "; ps[i].xuat();
	}
//Sap xep
	for (int i = 0; i < n; i++)
	{
		if (ps[i] > ps[i + 1])
		{
			person tg = ps[i];
			ps[i] = ps[i + 1];
			ps[i + 1] = tg;
		}		
	}
	cout << "\n-----DS theo tt tang dan cua nam sinh:" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". "; ps[i].xuat();
	}
}