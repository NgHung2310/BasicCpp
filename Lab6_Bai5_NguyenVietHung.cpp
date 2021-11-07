#include <iostream>
#include<string>
#include<math.h>
using namespace std;
class ISP
{
protected:
	string ho_ten;
public:
	virtual void nhap() 
	{
		cout << "Nhap ten khach hang: "; cin.ignore(); getline(cin, ho_ten);
	}
	virtual void xuat() 
	{
		cout << "Ten khach hang: " << ho_ten;
	}
	virtual double tien_cuoc() = 0;
	virtual string phan_loai() = 0;
};
class DialUp:public ISP
{
	double thoi_gian;//phut
public:
	void nhap()
	{
		ISP::nhap();
		cout << "Nhap thoi gian truy cap cua the bao Dial Up: "; cin >> thoi_gian;
	}
	void xuat()
	{
		ISP::xuat();
		cout << "\tThoi gian truy cap: " << thoi_gian << endl;
	}
	double tien_cuoc()
	{
		return 30000 + 30 * thoi_gian;
	}
	string phan_loai()
	{
		return "dialup";
	}
};
class ADSL :public ISP
{
	double dung_luong;//MB
public:
	void nhap()
	{
		ISP::nhap();
		cout << "Nhap dung luong truyen tai cua the bao ADSL: "; cin >> dung_luong;
	}
	void xuat()
	{
		ISP::xuat();
		cout << "\tDung luong truyen tai: " << dung_luong << endl;
	}
	double tien_cuoc()
	{
		return 50000 + 50 * dung_luong;
	}
	string phan_loai()
	{
		return "adsl";
	}
};
class T1 :public ISP
{
public:
	void nhap()
	{
		ISP::nhap();
	}
	void xuat()
	{
		ISP::xuat();
	}
	double tien_cuoc()
	{
		return 2000000;
	}
	string phan_loai()
	{
		return "t1";
	}
};
int main()
{
	int i = 0, n = 0;
	int chon;
	ISP *kh[50];
	while (true)
	{
		cout << "1. Thue bao DialUp\n2. Thue bao ADSL\n3. Thue bao T1\n4.Thoat" << endl;
		cout << "Nhap lua chon: "; cin >> chon;
		if (chon == 1)
			kh[i] = new DialUp();
		else if (chon == 2)
			kh[i] = new ADSL();
		else if (chon == 3)
			kh[i] = new T1();
		else if (chon == 4)
			break;
		else
		{
			cout << "Chon khong hop le!!" << endl;
			cout << "-------------------------" << endl;
			continue;
		}
		kh[i]->nhap();
		cout << "-----------------------------\n" << endl;
		i++;
		n = i;
	}
	//tong tien cuoc thue bao Dial Up
	double sum_tien_dialup=0;
	for (int j = 0; j < n; j++)
	{
		if (kh[j]->phan_loai() == "dialup")
			sum_tien_dialup += kh[j]->tien_cuoc();
	}
	cout << "\n-----Tong tien cuoc loai thue bao Dial Up: " << sum_tien_dialup << endl;
	//tong tien cuoc thue bao ADSL
	double sum_tien_adsl = 0;
	for (int j = 0; j < n; j++)
	{
		if (kh[j]->phan_loai() == "adsl")
			sum_tien_adsl += kh[j]->tien_cuoc();
	}
	cout << "\n-----Tong tien cuoc loai thue bao ADSL: " << sum_tien_adsl << endl;
	//tong tien cuoc thue bao T1
	double sum_tien_t1 = 0;
	for (int j = 0; j < n; j++)
	{
		if (kh[j]->phan_loai() == "t1")
			sum_tien_t1 += kh[j]->tien_cuoc();
	}
	cout << "\n-----Tong tien cuoc loai thue bao T1: " << sum_tien_t1 << endl;
	//tong tien cua cac thue bao
	cout << "\n-----Tong tien cuoc tat ca thue bao: " << sum_tien_dialup + sum_tien_adsl + sum_tien_t1 << endl;
	//Thue bao ADSL tien cuoc lon nhat
	double adsl_cuoc_min = 0;
	int idx = 0;
	for (int j = 0; j < n; j++)
	{
		if (kh[j]->phan_loai() == "adsl")
			if (adsl_cuoc_min < kh[j]->tien_cuoc())
			{
				adsl_cuoc_min = kh[j]->tien_cuoc();
				idx = j;
			}
	}
	cout << "\n-----Khach hang ADSL co toen cuoc lon nhat: " << endl;
	kh[idx]->xuat();
}