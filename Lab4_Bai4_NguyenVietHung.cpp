#include<iostream>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<string>
using namespace std;
class AnPham
{
protected:
	string ten;
	int gia_thanh;
public:
	void nhap()
	{
		cout << "Nhap ten an pham: "; cin.get(); getline(cin, ten);
		cout << "Nhap gia thanh: "; cin >> gia_thanh;
	}
	void xuat()
	{
		cout << "Ten an pham: " << ten << "\t\tGia thanh: " << gia_thanh;
	}
};
class Sach :public AnPham
{
	int so_trang;
public:
	void nhap()
	{
		AnPham::nhap();
		cout << "Nhap so trang: "; cin>>so_trang;
	}
	void xuat()
	{
		AnPham::xuat();
		cout << "\tSo trang: " << so_trang << endl;
	}
	int get_so_trang()
	{
		return so_trang;
	}
};
class DiaCD :public AnPham
{
	int so_phut;
public:
	void nhap()
	{
		AnPham::nhap();
		cout << "Nhap so phut: "; cin >> so_phut;
	}
	void xuat()
	{
		AnPham::xuat();
		cout << "\tSo phut: " << so_phut << endl;
	}
	string get_ten()
	{
		return ten;
	}
};
int main()
{
	int luachon;
	cout << "1. Nhap du lieu sach\n2. Nhap du lieu dia CD" << endl;
nhaplai:
	cout << "\nNhap du lieu cho....?\nLua chon cua ban: "; cin >> luachon;
	if (luachon == 1)
	{
		int n; cout << "-----Nhap so quyen sach: "; cin>>n;
		Sach *s = new Sach[n];
		//Nhap ds sach
		for (int i = 0; i < n; i++)
		{
			cout << "-----Cuon sach thu " << i + 1 << " : " << endl;
			s[i].nhap();
		}
		//Xuat ds sach
		cout << "\n-----DS sach vua nhap: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ". "; s[i].xuat();
		}
		//DS sach co so trang >500
		cout << "-----DS sach co so trang >500: " << endl;
		for (int i = 0; i < n; i++)
		{
			if (s[i].get_so_trang() > 500)
				s[i].xuat();
		}
	}
	else if (luachon == 2)
	{
		int n; cout << "-----Nhap so dia CD: "; cin>> n;
		DiaCD *dia = new DiaCD[n];
		//Nhap ds dia CD
		for (int i = 0; i < n; i++)
		{
			cout << "-----Dia CD thu " << i + 1 << " : " << endl;
			dia[i].nhap();
		}
		//Xuat ds dia CD
		cout << "\n-----DS dia CD vua nhap: " << endl;
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ". "; dia[i].xuat();
		}
		//Tim ten dia CD
		bool TKdia = false;
		string tkdiaCD; cout << "-----Ten dia CD can tim: ";
		cin.get(); getline(cin, tkdiaCD);
		for (int i = 0; i < n; i++)
		{
			if (dia[i].get_ten() == tkdiaCD)
			{
				dia[i].xuat();
				TKdia = true;
			}
		}
		if (!TKdia)
			cout << "Khong tim thay!!" << endl;
	}
	else
	{
		cout << "Nhap khong hop le!!" << endl;
		goto nhaplai;
	}
}
