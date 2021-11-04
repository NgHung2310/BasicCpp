#include<iostream>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<string>
#include<ctime>
#pragma warning(disable : 4996)
using namespace std;
class BenhNhan
{
protected:
	string ten, que_quan;
	int nam_sinh;
public:
	BenhNhan(string ten="", string que_quan="", int nam_sinh=0)
	{
		this->ten = ten;
		this->que_quan = que_quan;
		this->nam_sinh = nam_sinh;
	}
	~BenhNhan(){}
	void nhap()
	{
		cout << "Nhap ten benh nhan: "; cin.ignore(); getline(cin, ten);
		cout << "Nhap que quan: "; cin.get(); getline(cin, que_quan);
		cout << "Nhap nam sinh benh nhan: "; cin >> nam_sinh;
	}
	void xuat()
	{
		cout << "Ten benh nhan: " << ten
			<< "Que quan: " << que_quan
			<< "Nam sinh: " << nam_sinh;
	}
	int get_nam_sinh()
	{
		return nam_sinh;
	}
};
class BenhAn :public BenhNhan
{
	string ten_benh_an;
	int vien_phi;
public:
	~BenhAn(){}
	void nhap()
	{
		BenhNhan::nhap();
		cout << "Nhap ten benh an: "; cin.get(); getline(cin, ten_benh_an);
		cout << "Nhap so tien vien phi: "; cin >> vien_phi;
	}
	void xuat()
	{
		BenhNhan::xuat();
		cout << "Ten benh an: " << ten_benh_an
			<< "Vien phi: " << vien_phi << endl;
	}
	int tuoi()
	{
		time_t now = time(0);
		tm *ltm = localtime(&now);
		return 1900 + ltm->tm_year - get_nam_sinh();
	}
	int get_vien_phi()
	{
		return vien_phi;
	}
};
int main()
{
	int n; cout << "-----So benh an: "; cin >> n;
	BenhAn *ba = new BenhAn[n];
//Nhap benh nhan
	for (int i = 0; i < n; i++)
	{
		cout << "-----Thong tin benh nhan thu " << i + 1 << " :" << endl;
		ba[i].nhap();
	}
//Sap xep benh nhan
	for (int i = 0; i < n; i++)
	{
		if (ba[i].tuoi() < ba[i + 1].tuoi())
		{
			BenhAn tg;
			tg = ba[i];
			ba[i] = ba[i + 1];
			ba[i + 1] = tg;
		}
	}
//Xuat benh nhan
	cout << "-----DS benh nhan:" << endl;
	for (int i = 0; i < n; i++)
	{
		ba[i].xuat();
	}
//Benh nhan tuoi >50
	cout << "-----DS benh nhan tuoi >50: " << endl;
	for (int i = 0; i < n; i++)
	{
		if(ba[i].tuoi()>50)
			ba[i].xuat();
	}
//Benh nah co vien phi cao nhat
	int idx;
	for (int i = 0; i < n; i++)
	{
		if (ba[i].get_vien_phi() < ba[i + 1].get_vien_phi())
		{
			ba[i] = ba[i + 1];
			idx = i+1;
		}
	}
	cout << "-----Benh nhan co vien phi cao nhat: " << endl;
	ba[idx].xuat();

}