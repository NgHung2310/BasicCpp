#include<iostream>
#include<conio.h>
#include<math.h>
#include<string>
#include<stdio.h>
using namespace std;
class MonHoc
{
protected:
	string ten_mon_hoc;
	int so_tiet;
public:
	MonHoc()
	{
		this->ten_mon_hoc = "";
		this->so_tiet = 0;
	}
	MonHoc(string ten_mon_hoc, int so_tiet)
	{
		this->so_tiet = so_tiet;
		this->ten_mon_hoc = ten_mon_hoc;
	}
	~MonHoc() {}
	void xuat()
	{
		cout << "Ten mon hoc: " << ten_mon_hoc
			<< "\tSo tiet: " << so_tiet;
	}
};
class Nguoi
{
protected:
	string ho_ten;
	int nam_sinh;
public:
	Nguoi()
	{
		this->ho_ten = "";
		this->nam_sinh = 0;
	}
	Nguoi(string ho_ten, int nam_sinh)
	{
		this->ho_ten = ho_ten;
		this->nam_sinh = nam_sinh;
	}
	~Nguoi() {}
	void xuat()
	{
		cout << "\tHo ten: " << ho_ten
			<< "\t\tNam sinh: " << nam_sinh;
	}
};
class GiaoVien :public MonHoc, public Nguoi
{
	string bo_mon;
public:
	GiaoVien()
	{
		this->bo_mon = "";
	}
	GiaoVien(string ten_mon_hoc, int so_tiet, string ho_ten, int nam_sinh, string bo_mon) :MonHoc(ten_mon_hoc, so_tiet), Nguoi(ho_ten, nam_sinh)
	{
		this->bo_mon = bo_mon;
	}
	void xuat()
	{
		MonHoc::xuat();
		Nguoi::xuat();
		cout << "\t\tBo mon: " << bo_mon << endl;
	}
};
int main()
{
	GiaoVien *gv = new GiaoVien("Toan", 6, "Nguyen Van A", 1999, "Toan");
	gv->xuat();
}