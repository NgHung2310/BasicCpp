#include <iostream>
#include<math.h>
#include<string>
#include<conio.h>
#include<iomanip>
using namespace std;
class OTO
{
	char ma_hang[10], ten_hang_sx[20];
	//string ma_hang, ten_hang_sx;
	int don_gia;
	float trong_luong, dung_tich_xilanh;
public:
	OTO()
	{
		strcpy_s(this->ma_hang, "");
		strcpy_s(this->ten_hang_sx, "");
		this->don_gia = 0;
		this->trong_luong = 0;
		this->dung_tich_xilanh = 0;
	}
	OTO(char *ma_hang, char *ten_hang_sx, int don_gia=0, float trong_luong=0, float dung_tich_xilanh=0)
	{
		strcpy_s(this->ma_hang, ma_hang);
		strcpy_s(this->ten_hang_sx, ten_hang_sx);
		this->don_gia = don_gia;
		this->trong_luong = trong_luong;
		this->dung_tich_xilanh = dung_tich_xilanh;
	}
	~OTO() {}
//toan tu nhap >>
	friend istream &operator>>(istream &nhap, OTO &oto)
	{
		cout << "Nhap ma hang: "; cin.ignore(); nhap.getline(oto.ma_hang, 10);
		cout << "Nhap ten hang sx: ";  nhap.getline(oto.ten_hang_sx, 20);
		cout << "Nhap don gia: "; nhap >> oto.don_gia;
		cout << "Nhap dung tich xilanh: "; nhap >> oto.dung_tich_xilanh;
		cout << "Nhap trong luong: "; nhap >> oto.trong_luong;
		return nhap;
	}
//toan tu xuat <<
	friend ostream &operator<<(ostream &xuat, OTO oto)
	{
		xuat << "Ma hang: " << oto.ma_hang
			<< "\tTen hang sx: " << oto.ten_hang_sx
			<< "\tDon gia: " << oto.don_gia
			<< "\tDung tich xilanh: " << oto.dung_tich_xilanh
			<< "\tTrong luong: " << oto.trong_luong;
		return xuat;
	}
//tinh tien van chuyen
	int tien_van_chuyen()
	{
		if (trong_luong > 2)
			return 100000;
		else if (trong_luong > 1)
			return 50000;
		else
			return 30000;
	}
//toan tu so sanh ==
	friend bool operator==(OTO &oto,float dung_tich_xilanh)
	{
		if (dung_tich_xilanh == oto.dung_tich_xilanh)
			return true;
		else
			return false;
	}
//ham lay ten hang sx
	char* get_ten_hang()
	{
		return ten_hang_sx;
	}

};
int main()
{
	int n; cout << "Nhap so luong: "; cin >> n;
	OTO *oto = new OTO[n];
//nhap ds
	for (int i = 0; i < n; i++)
	{
		cout << "-----OTO thu " << i + 1 << endl;
		cin >> oto[i];
	}
//xuat ds
	cout << "-----DS vua nhap: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1<<". " << oto[i]<< endl;
			
	}
//tim oto co dung tich xilanh =2.5
	bool KT_xilanh = false;
	for (int i = 0; i < n; i++)
	{		
		if (oto[i] == 2.5) 
		{
			cout << "-----OTO co dung tich xilanh =2.5: " << oto[i] << endl;
			KT_xilanh = true;
		}
	}
	if (!KT_xilanh)
		cout << "-----Khong co oto nao xilanh =2.5" << endl;
//tim oto hang TOYOTA
	bool KT_ten_hang = false;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(oto[i].get_ten_hang(), "TOYOTA") == 0)
		{
			do 
			{ 
				oto[i] = oto[i + 1]; 
			} while (i < n);
			n--;
			KT_ten_hang = true;
		}
	}
	if (!KT_ten_hang)
	{
		n++;
		for (int i = n-1; i >= 0; i--)
		{
			oto[i] = oto[i - 1];
		}
		cout << "Nhap oto moi: " << endl;
		cin >> oto[0];
	}
//DS sau khi tim kiem
	cout << "-----DS sau khi tim kiem: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << oto[i] << endl;

	}

}
