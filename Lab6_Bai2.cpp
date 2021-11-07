#include <iostream>
#include<string>
#include<math.h>
using namespace std;
class Nguoi
{
protected:
	string ho_ten;
public:
	virtual void nhap()
	{
		cout << "Nhap ho ten: "; cin.ignore(); getline(cin, ho_ten);
	}
	virtual void xuat()
	{
		cout << "Ho ten: " << ho_ten;
	}
	virtual int thuong() = 0;
};
class SinhVien :public Nguoi
{
	float diem_thi;
public:
	void nhap()
	{
		Nguoi::nhap();
		cout << "Nhap diem thi: "; cin >> diem_thi;
	}
	void xuat()
	{
		Nguoi::xuat();
		cout << "\t\tDiem thi: " << diem_thi << endl;
	}
	int thuong()
	{
		if (diem_thi > 8)
			return 1;
		else return 0;
	}
};
class GiangVien : public Nguoi
{
	int so_bai_bao;
public:
	void nhap()
	{
		Nguoi::nhap();
		cout << "Nhap so bai bao: "; cin >> so_bai_bao;
	}
	void xuat()
	{
		Nguoi::xuat();
		cout << "\t\tSo bai bao: " << so_bai_bao << endl;
	}
	int thuong()
	{
		if (so_bai_bao > 5)
			return 1;
		else return 0;
	}
};
int main()
{
	Nguoi *ng[30];
	int chon;
	int i = 0, n = 0;
	//nhap ds
	while (true)
	{
		cout << "1. Sinh vien\n2. Giang vien\n3. Thoat\nNhap lua chon: " << endl;
		cin >> chon;
		if (chon == 1)		
			ng[i] = new SinhVien();		
		else if (chon == 2)		
			ng[i] = new GiangVien();		
		else if (chon == 3)
			break;
		else
		{
			cout << "Chon khong hop le!! Chon lai!!" << endl;
			continue;
		}
		ng[i]->nhap();
		cout << "-------------------------------------------" << endl;
		i++;
		n = i;
	}
	//xuat ds
	cout << "/n-----DS vua nhap:" << endl;
	for(int j = 0; j < n; j++)
		ng[j]->xuat();
	//ds thuong
	cout << "/n-----DS nguoi duoc thuong: " << endl;
	for (int j = 0; j < n; j++)
		if(ng[j]->thuong())
			ng[j]->xuat();
}