#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class HinhVe
{
public:
	virtual void nhap() {}
	virtual void xuat() {}
	virtual double chu_vi() = 0;
	virtual double dien_tich() = 0;
	virtual double the_tich() = 0;
};
class HaiChieu :public HinhVe
{
public:
	virtual void nhap() {}
	virtual void xuat() {}
	virtual double chu_vi() = 0;
	virtual double dien_tich() = 0;
	virtual double the_tich() = 0;
};
class BaChieu :public HinhVe
{
public:
	virtual void nhap() {}
	virtual void xuat() {}
	virtual double the_tich() = 0;
	virtual double chu_vi() = 0;
	virtual double dien_tich() = 0;
};
class Tron :public HaiChieu
{
	double ban_kinh;
public:
	void nhap() 
	{
		cout << "Nhap ban kinh hinh tron: "; cin >> ban_kinh;
	}
	void xuat() 
	{
		cout << "Hinh tron ban kinh: " << ban_kinh << endl;
	}
	double chu_vi()
	{
		return 2 * 3.14*ban_kinh;
	}
	double dien_tich()
	{
		return 3.14*ban_kinh*ban_kinh;
	}
	virtual double the_tich() { return 0; }
};
class ChuNhat :public HaiChieu
{
	double dai, rong;
public:
	void nhap() 
	{
		cout << "Nhap chieu dai hinh chu nhat: "; cin >> dai;
		cout << "Nhap chieu rong hinh chu nhat: "; cin >> rong;
	}
	void xuat() 
	{
		cout << "Hinh chu nhat chieu dai " << dai << " rong " << rong << endl;
	}
	double chu_vi()
	{
		return 2 * (dai + rong);
	}
	double dien_tich()
	{
		return dai * rong;
	}
	virtual double the_tich() { return 0; }
};
class Vuong :public HaiChieu
{
	double canh;
public:
	void nhap() 
	{
		cout << "Nhap canh hinh vuong: "; cin >> canh;
	}
	void xuat() 
	{
		cout << "Hinh vuong co canh " << canh << endl;
	}
	double chu_vi()
	{
		return 4 * canh;
	}
	double dien_tich()
	{
		return canh * canh;
	}
	virtual double the_tich() { return 0; }
};
class Cau :public BaChieu
{
	double ban_kinh;
public:
	void nhap() 
	{
		cout << "Nhap ban kinh hinh cau: "; cin >> ban_kinh;
	}
	void xuat() 
	{
		cout << "Hinh cau co ban kinh " << ban_kinh << endl;
	}
	double the_tich()
	{
		return 4 / 3 * 3.14*ban_kinh*ban_kinh*ban_kinh;
	}
	virtual double chu_vi() { return 0; }
	virtual double dien_tich() { return 0; }
};
class LapPhuong :public BaChieu
{
	double canh;
public:
	void nhap() 
	{
		cout << "Nhap xanh hinh lap phuong: "; cin >> canh;
	}
	void xuat() 
	{
		cout << "Hinh lap phuong co canh " << canh << endl;
	}
	double the_tich()
	{
		return canh * canh*canh;
	}
	virtual double chu_vi() { return 0; }
	virtual double dien_tich() { return 0; }
};
int main()
{
	HinhVe *h;
	h = new Tron();
	h->nhap();
	h->xuat();
	cout <<"Chu vi: "<< h->chu_vi() << endl;
	cout << "Dien tich: " << h->dien_tich() << endl << endl;

	h = new ChuNhat();
	h->nhap();
	h->xuat();
	cout << "Chu vi: " << h->chu_vi() << endl;
	cout << "Dien tich: " << h->dien_tich() << endl << endl;

	h = new Vuong();
	h->nhap();
	h->xuat();
	cout << "Chu vi: " << h->chu_vi() << endl;
	cout << "Dien tich: " << h->dien_tich() << endl << endl;

	h = new Cau();
	h->nhap();
	h->xuat();
	cout <<"The tich: "<< h->the_tich() << endl << endl;

	h = new LapPhuong();
	h->nhap();
	h->xuat();
	cout <<"The tich: "<< h->the_tich() << endl << endl;
}
