#include<math.h>
#include <iostream>
#include<string>
#include <cstdio>
using namespace std;
class MAYTINH
{
	string ma_hang;
	string ten_hang_sx;
	int don_gia;//vnd
	int dung_luong_RAM;//gigabyte
	float trong_luong;//kg
public:
	MAYTINH(string ma_hang="", string ten_hang_sx="", int don_gia=0, int dung_luong_RAM=0, float trong_luong=0)
	{
		this->ma_hang = ma_hang;
		this->ten_hang_sx = ten_hang_sx;
		this->don_gia = don_gia;
		this->dung_luong_RAM = dung_luong_RAM;
		this->trong_luong = trong_luong;
	}
	~MAYTINH() {}
	friend istream &operator>>(istream &nhap, MAYTINH &mt)
	{
		cout << "Nhap ma hang: "; cin.get(); getline(nhap, mt.ma_hang);
		cout << "Nhap ten hang sx: "; cin.ignore(0); getline(nhap, mt.ten_hang_sx);
		cout << "Nhap don gia: "; nhap >> mt.don_gia;
		cout << "Nhap dung luong RAM: "; nhap >> mt.dung_luong_RAM;
		cout << "Nhap trong luong: "; nhap >> mt.trong_luong;
		return nhap;
	}
	friend ostream &operator<<(ostream &xuat, MAYTINH mt)
	{
		xuat << "Ma hang: " << mt.ma_hang 
			<< "\t\tTen hang sx: " << mt.ten_hang_sx 
			<< "\t\tDon gia: " << mt.don_gia 
			<< "\tDung luong RAM: " << mt.dung_luong_RAM 
			<< "\tTrong luong: " << mt.trong_luong << endl;
		return xuat;
	}
	int tien_van_chuyen()
	{
		
		if (trong_luong > 2)
			return 100000;
		else if (trong_luong > 1)
			return 50000;
		else
			return 30000;
	}
	int get_RAM()
	{
		return dung_luong_RAM;
	}
	string get_ten_hang_sx()
	{
		return ten_hang_sx;
	}
};
int main()
{
	int n; cout << "Nhap so luong: "; cin >> n;
	MAYTINH *mt = new MAYTINH[n];
	for (int i = 0; i < n; i++)
	{
		cout << "---Nhap thong tin may tinh thu " << i + 1 << endl;
		cin >> mt[i];
	}
	cout << "---DS vua nhap" << endl;
	for (int i = 0; i < n; i++)
	{
		cout<<i+1<<". " << mt[i];
	}

	cout << "---May tinh co RAM =16" << endl;
	for (int i = 0; i < n; i++)
	{
		if(mt[i].get_RAM()==16)
			cout << mt[i];
	}
	cout << "---May tinh hang SONY" << endl;
	bool KT_SONY = false;
	for (int i = 0; i < n; i++)
	{
		if (mt[i].get_ten_hang_sx() == "SONY")
		{
			cout << mt[i];
			KT_SONY = true;
			for (int j = i+1; j < n; j++)
				mt[i] = mt[j];
			n--;
		}
	}
	if (!KT_SONY)
	{	
		MAYTINH SONY("", "SONY", 0, 0, 0);
		
		n++;
		for (int i = n; i >=1; i--)
		{
			mt[i] = mt[i - 1]; 
		}
		
		SONY=mt[0]; 
	}
	for (int i = 0; i < n; i++)
	{
		cout << mt[i];
	}

}
