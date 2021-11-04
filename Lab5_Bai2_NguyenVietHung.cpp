#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string>
#include<conio.h>
using namespace std;
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
	friend istream &operator>>(istream &is, Nguoi &ng)
	{
		cout << "Nhap ho ten: "; cin.ignore(); getline(is, ng.ho_ten);
		cout << "Nhap nam sinh: "; is >> ng.nam_sinh;
		return is;
	}
	friend ostream &operator<<(ostream &os, Nguoi ng)
	{
		os << "Ho ten: " << ng.ho_ten
			<< "\t\tNam sinh: " << ng.nam_sinh;
		return os;
	}
};
class SinhVien
{
protected:
	string hanh_kiem;
	float diem;
public:
	SinhVien()
	{
		this->hanh_kiem = "";
		this->diem = 0;
	}
	SinhVien(string hanh_kiem, float diem)
	{
		this->hanh_kiem = hanh_kiem;
		this->diem = diem;
	}
	~SinhVien() {}
	friend istream &operator>>(istream &is, SinhVien &sv)
	{
		cout << "Nhap hanh kiem: "; cin.ignore(); getline(is, sv.hanh_kiem);
		cout << "Nhap diem: "; is >> sv.diem;
		return is;
	}
	friend ostream &operator<<(ostream &os, SinhVien sv)
	{
		os << "\tHanh kiem: " << sv.hanh_kiem
			<< "\tDiem: " << sv.diem;
		return os;
	}
	float get_diem()
	{
		return diem;
	}
};
class SVTaiChuc :public Nguoi, public SinhVien
{
	int hoc_phi;
public:
	SVTaiChuc()
	{
		this->hoc_phi = 0;
	}
	SVTaiChuc(string ho_ten, int nam_sinh, string hanh_kiem, float diem, int hoc_phi) :Nguoi(ho_ten, nam_sinh), SinhVien(hanh_kiem, diem)
	{
		this->hoc_phi = hoc_phi;
	}
	~SVTaiChuc() {}
	friend istream &operator>>(istream &is, SVTaiChuc &svtc)
	{
		is >> (Nguoi&)svtc;
		is >> (SinhVien&)svtc;
		cout << "Nhap hoc phi: "; is >> svtc.hoc_phi;
		return is;
	}
	friend ostream &operator<<(ostream &os, SVTaiChuc svtc)
	{
		os << (Nguoi&)svtc << (SinhVien&)svtc << "\tHoc phi: " << svtc.hoc_phi << endl;
		return os;
	}
	int hoc_bong()
	{
		if (hanh_kiem == "Tot"&&diem >= 8.0)
			return 5;
		else if (hanh_kiem == "Kha"&&diem >= 7.0)
			return 3;
		else
			return 0;
	}
};
int main()
{
	int n; cout << "-----Nhap so sinh vien: "; cin >> n;
	SVTaiChuc *svtc = new SVTaiChuc[n];
	//nhap ds
	for (int i = 0; i < n; i++)
	{
		cout << "\n-----Thong tin sv thu " << i + 1 << " : " << endl;
		cin >> svtc[i];
	}
	//xuat ds
	cout << "\n-----DS vua nhap: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 <<". "<< svtc[i];
	}
	//sv dc hoc bong
	cout << "\n-----SV duoc hoc bong" << endl;
	for (int i = 0; i < n; i++)
	{
		if (svtc[i].hoc_bong() != 0)
			cout << svtc[i];
	}
	//sap xep sv
	cout << "\n-----DS sap xep theo diem: " << endl;
	for (int i = 0; i < n-1; i++)
	{
		if (svtc[i].get_diem() > svtc[i + 1].get_diem())
		{
			SVTaiChuc tg;
			tg= svtc[i];
			svtc[i] = svtc[i + 1];
			svtc[i + 1] = tg;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << svtc[i];
	}
}