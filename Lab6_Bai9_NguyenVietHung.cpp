#include<iostream>
#include<string>
using namespace std;
struct ThoiGian
{
	int dd, mm, yy;
};
class GiaoDich
{
protected:
	string ma_gd;
	ThoiGian ngay;
	double don_gia,dien_tich;
public:
	virtual void nhap()
	{
		cout << "Nhap ma giao dich: "; cin.ignore(); getline(cin, ma_gd);
		cout << "Ngay giao dich (dd/mm/yy): "; cin >> ngay.dd >> ngay.mm >> ngay.yy;
		cout << "Nhap don gia: "; cin >> don_gia;
		cout << "Nhap dien tich: "; cin >> dien_tich;
	}
	virtual void xuat()
	{
		cout << "Ma GD: " << ma_gd
			<< "\tNgay GD: " << ngay.dd << "/" << ngay.mm << "/" << ngay.yy
			<< "\tDon gia: " << don_gia
			<< "\tDien tich: " << dien_tich;
	}
	virtual double thanh_tien() = 0;
	virtual string loai_gd() 
	{
		return "";
	}
	int get_mm()
	{
		return ngay.mm;
	}
	int get_yy()
	{
		return ngay.yy;
	}
};
class GDDat:public GiaoDich
{
	string loai_dat;
public:
	void nhap()
	{
		GiaoDich::nhap();
		cout << "Nhap loai dat (A,B,C): "; cin>>loai_dat;
	}
	void xuat()
	{
		GiaoDich::xuat();
		cout << "\tLoai dat: " << loai_dat << endl;
	}
	double thanh_tien()
	{
		if (loai_dat == "A")
			return dien_tich * don_gia*1.5;
		else if (loai_dat == "B" || loai_dat == "C")
			return dien_tich * don_gia;
	}
	string loai_gd()
	{
		return "dat";
	}
};
class GDNha:public GiaoDich
{
	string loai_nha, dia_chi;
public:
	void nhap()
	{
		GiaoDich::nhap();
		cout << "Nhap loai nha (cao cap,thuong): "; cin.ignore(); getline(cin, loai_nha);
		cout << "Nhap dia chi: "; getline(cin, dia_chi);
	}
	void xuat()
	{
		GiaoDich::xuat();
		cout << "\tLoai nha: " << loai_nha
			<< "\tDia chi: " << dia_chi << endl;
	}
	double thanh_tien()
	{
		if (loai_nha == "cao cap")
			return dien_tich * don_gia;
		else if (loai_nha == "thuong")
			return dien_tich * don_gia * 9 / 10;
	}
	string loai_gd()
	{
		return "nha";
	}
};
int main()
{
	int n=1;
	cout << "-----Nhap so luong giao dich: "; cin >> n;
	GiaoDich *gd[100];
	//nhap ds
	for (int i = 0; i < n; i++)
	{
		int chon;
		cout << "1. GD dat\n2. GD nha\nChon loai giao dich: "; cin >> chon;
		if (chon == 1)
			gd[i] = new GDDat();
		if (chon == 2)
			gd[i] = new GDNha();
		gd[i]->nhap();
	}
	//xuat ds
	for (int i = 0; i < n; i++)
	{
		gd[i]->xuat();
	}
	//tong tuong loai gd
	int idx_dat = 0, idx_nha = 0;
	for (int i = 0; i < n; i++)
	{
		if (gd[i]->loai_gd() == "dat")
			idx_dat++;
		else if (gd[i]->loai_gd() == "nha")
			idx_nha++;
	}
	cout << "\n-----So luong giao dich dat: " << idx_dat << endl;
	cout << "\n-----So luong giao dich nha: " << idx_nha << endl;
	//trung binh tien gd dat
	double tong_tien_dat = 0;
	for (int i = 0; i < n; i++)
	{
		if (gd[i]->loai_gd() == "dat")
			tong_tien_dat += gd[i]->thanh_tien();
	}
	cout << "\n-----Trung binh thanh tien giao dich dat: " << tong_tien_dat / idx_dat << endl;
	//giao dich thang 9/2013
	cout << "\n-----Cac giao dich thang 9/2013: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (gd[i]->get_mm() == 9 && gd[i]->get_yy() == 2013)
			gd[i]->xuat();
	}
}