#include <iostream>
#include<math.h>
using namespace std;
class GV
{
	char ho_ten[30], bang_cap[15], chuyen_nganh[20];
	int tuoi;
	float bac_luong;
public:
	friend istream &operator>>(istream &nhap, GV &gv)
	{
		cout << "Nhap ho ten gv: "; cin.ignore(); nhap.getline(gv.ho_ten, 30);
		cout << "Nhap tuoi gv: ";  nhap >> gv.tuoi;
		cout << "Nhap bang cap: "; cin.ignore(); nhap.getline(gv.bang_cap, 15);
		cout << "Nhap chuyen nganh: "; cin.ignore(); nhap.getline(gv.chuyen_nganh, 20);
		cout << "Nhap bac luong: ";  nhap >> gv.bac_luong;
		return nhap;
	}
	friend ostream &operator<<(ostream &xuat, GV gv)
	{
		xuat << "Ho ten: " << gv.ho_ten 
			<< "\t\tTuoi: " << gv.tuoi 
			<< "\tBang cap: " << gv.bang_cap 
			<< "\tChuyen nganh" << gv.chuyen_nganh 
			<< "\tBac luong: " << gv.bac_luong << endl;
		return xuat;
	}
	float tien_luong()
	{
		return bac_luong * 610;
	}
	char *get_hoten()
	{
		return ho_ten;
	}
};
int main()
{
	int n; cout << "Nhap so gv: "; cin >> n;
	GV *gv = new GV[n];
	for (int i = 0; i < n; i++)
	{
		cout << "---Nhap thong tin cho gv thu " << i + 1 << endl;
		cin >> gv[i];
	}
	cout << "---DS gv vua nhap" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << gv[i];
	}
	cout << "---Gv co tien luong <2000" << endl;
	for (int i = 0; i < n; i++)
	{
		if (gv[i].tien_luong() < 2000)
			cout << gv[i];
	}
	char tim_gv[30]; cout << "Nhap ten gv can tim: "; cin.ignore(); cin.getline(tim_gv, 30);
	bool KT_gv=false;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(gv[i].get_hoten(), tim_gv) == 0)
		{
			cout << gv[i] << endl;
			KT_gv = true;
		}
	}
	if (!KT_gv)
	{
		cout << "Khong tim thay!" << endl;
		cout << "Nhap thong tin cho gv moi: " << endl;
		cin >> gv[n];
		n++;
		for (int i = 0; i < n ; i++)
		{
			cout << gv[i];
		}

	}
}