#include <iostream>
#include<string>
#include<math.h>
using namespace std;
class SHAPE
{
public:
	virtual void nhap() {}
	virtual void xuat() {}
	virtual float dien_tich() = 0;
	virtual float chu_vi() = 0;
	//virtual float sum_chu_vi() = 0;
	//virtual float sum_dien_tich() = 0;
};
class REC :public SHAPE
{
	float dai, rong;
public:
	void nhap()
	{
		cout << "Nhap chieu dai: "; cin >> dai;
		cout << "Nhap chieu rong: "; cin >> rong;
	}
	void xuat()
	{
		cout << "Hinh chu nhat: Chieu dai: " << dai << "\tChieu rong: " << rong << endl;
	}
	float chu_vi()
	{
		return 2 * (dai + rong);
	}
	float dien_tich()
	{
		return dai * rong;
	}
};
class ROUND :public SHAPE
{
	float ban_kinh;
public:
	void nhap()
	{
		cout << "Nhap ban kinh: "; cin >> ban_kinh;
	}
	void xuat()
	{
		cout << "Hinh tron: Ban kinh: " << ban_kinh << endl;
	}
	float chu_vi()
	{
		return 2 * ban_kinh*3.14;
	}
	float dien_tich()
	{
		return 3.14*ban_kinh*ban_kinh;
	}
};
class TRI :public SHAPE
{
	float a, b, c;
public:
	void nhap()
	{
		cout << "Nhap 3 canh cua tam giac: "; cin >> a >> b >> c;
	}
	void xuat()
	{
		cout << "Tam giac: a: " << a << "\tb: " << b << "\tc: " << c << endl;
	}
	float chu_vi()
	{
		return a + b + c;
	}
	float dien_tich()
	{
		int p = (a + b + c) / 2;
		return sqrt(p*(p - a)*(p - b)*(p - c));
	}
};
int main()
{
	SHAPE *h[30];
	int chon, i = 0, n = 0;
	//nhap ds
	while (true)
	{
		cout << "1. Hinh chu nhat\n2. Hinh tron\n3. Hinh tam giac\n4.Thoat\nNhap lua chon: ";
		cin >> chon;
		if (chon == 1)
			h[i] = new REC();
		else if (chon == 2)
			h[i] = new ROUND();
		else if (chon == 3)
			h[i] = new TRI();
		else if (chon == 4)
			break;
		else
		{
			cout << "Nhap khong hop le!!" << endl;
			cout << "\n-----------------------------" << endl;
			continue;
		}
		h[i]->nhap();
		i++;
		n = i;
		cout << "\n-----------------------------" << endl;
	}
	//xuat ds
	cout << "\n-----DS vua nhap: " << endl;
	for (int j = 0; j < n; j++)
	{
		h[j]->xuat();
	}
	//tong chu vi
	float sum_cv = 0;
	for (int j = 0; j < n; j++)
	{
		sum_cv += h[j]->chu_vi();
	}
	cout << "\n-----Tong chu vi cac hinh vua nhap: " << sum_cv << endl;
	//tong dien tich
	float sum_dt=0;
	for (int j = 0; j < n; j++)
	{
		sum_dt += h[j]->dien_tich();
	}
	cout << "\n-----Tong dien tich cac hinh vua nhap: " << sum_dt << endl;
}