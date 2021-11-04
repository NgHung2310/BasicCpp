#include<iostream>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<string>
using namespace std;
class Mat_hang
{
public:
	string ma_hang;
protected:
	string  ten_hang;
	int don_gia;
public:
	Mat_hang()
	{
		this->ma_hang = "";
		this->ten_hang = "";
		this->don_gia = 0;
	}
	Mat_hang(string ma_hang, string ten_hang, int don_gia)
	{
		this->ma_hang = ma_hang;
		this->ten_hang = ten_hang;
		this->don_gia = don_gia;
	}
	~Mat_hang() {}
	friend istream &operator>>(istream &is, Mat_hang &mh)
	{
		cout << "Nhap ma hang: "; cin.ignore(0); getline(is, mh.ma_hang);
		cout << "Nhap ten hang: "; getline(is, mh.ten_hang);
		cout << "Nhap don gia: "; is >> mh.don_gia;
		return is;
	}
};
class Banh_keo :public Mat_hang
{
	string noi_SX;
public:
	Banh_keo()
	{
		this->noi_SX = "";
	}
	Banh_keo(string ma_hang, string ten_hang, int don_gia, string noi_SX) :Mat_hang(ma_hang, ten_hang, don_gia)
	{
		this->noi_SX = noi_SX;
	}
	~Banh_keo() {}
	int chiet_khau()
	{
		return don_gia / 100;
	}
	friend istream &operator>>(istream &is, Banh_keo &bk)
	{
		is >> (Mat_hang&)bk;
		cout << "Nhap noi SX: ";cin.get(); getline(is, bk.noi_SX);
		return is;
	}
	friend ostream &operator<<(ostream &os, Banh_keo bk)
	{
		os << "Ma hang: " << bk.ma_hang
			<< "\t\tTen hang: " << bk.ten_hang
			<< "\t\tDon gia: " << bk.don_gia
			<< "\tNoi SX: " << bk.noi_SX << endl;
		return os;
	}
};
int main()
{
	int n; cout << "Nhap so banh keo: "; cin >> n; cin.ignore();
	Banh_keo *bk = new Banh_keo[n];
//Nhap ds banh keo
	for (int i = 0; i < n; i++)
	{
		cout << "-----Nhap tt banh keo thu " << i + 1 << " : " << endl;
		cin >> bk[i];
	}
//Xuat ds vua nhap
	cout << "/n-----DS banh keo vua nhap: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << bk[i];
	}
//DS co ma khac "MO1"
	cout << "\n-----DS banh keo co ma khac \"MO1\" : " << endl;
	for (int i = 0; i < n; i++)
	{
		if (bk[i].ma_hang != "MO1")
			cout << bk[i];
	}
}