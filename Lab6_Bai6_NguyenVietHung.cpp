#include <iostream>
#include<string>
#include<math.h>
#include<fstream>
using namespace std;
//class VLEAGUE
//{
//public:
//	virtual void nhap() {}
//	virtual void xuat() {}
//};
class CauThu/*:public VLEAGUE*/
{
	long int CMND;
	int nam_sinh;
	float chieu_cao, can_nang;
	string ho_ten, vi_tri_thi_dau, quoc_tich;
public:
	CauThu(long int CMND = 0, string ho_ten = "", string quoc_tich = "", int nam_sinh = 0, float chieu_cao = 0, float can_nang = 0, string vi_tri_thi_dau = "")
	{
		this->CMND = CMND;
		this->ho_ten = ho_ten;
		this->quoc_tich = quoc_tich;
		this->nam_sinh = nam_sinh;
		this->chieu_cao = chieu_cao;
		this->can_nang = can_nang;
		this->vi_tri_thi_dau = vi_tri_thi_dau;
	}
	void nhap()
	{
		
		cout << "Nhap CMND: "; cin >> CMND;
		cout << "Nhap ho ten: "; cin.ignore(); getline(cin, ho_ten);
		cout << "Nhap quoc tich: "; getline(cin, quoc_tich);
		cout << "Nhap nam sinh: "; cin >> nam_sinh;
		cout << "Nhap chieu cao: "; cin >> chieu_cao;
		cout << "Nhap can nang: "; cin >> can_nang;
		cout << "Nhap vi tri thi dau: "; cin.ignore(); getline(cin, vi_tri_thi_dau);
	}
	void xuat()
	{
		ofstream VLEAGUE("VLEAGUE.txt",ios::app);
		VLEAGUE << "CMND: " << CMND
			<< "\t\tHo ten: " << ho_ten
			<< "\t\tQuoc tich: " << quoc_tich
			<< "\tNam sinh: " << nam_sinh
			<< "\tChieu cao: " << chieu_cao
			<< "\tCan nang: " << can_nang
			<< "\tVi tri thi dau: " << vi_tri_thi_dau << endl;
	}
};
class DoiBong:public CauThu
{
	string ten_doi, dia_phuong, huan_luyen_vien;
	CauThu *ct = new CauThu[3];
public:	
	DoiBong(string ten_doi="", string dia_phuong="", string huan_luyen_vien="", CauThu *ct=new CauThu[3])
	{
		this->ten_doi = ten_doi;
		this->dia_phuong = dia_phuong;
		this->huan_luyen_vien = huan_luyen_vien;
		for (int i = 0; i < 3; i++)
			this->ct[i] = ct[i];
	}
	void nhap()
	{
		cout << "Nhap ten doi: "; cin.ignore(); getline(cin, ten_doi);
		cout << "Nhap dia phuong: ";  getline(cin, dia_phuong);
		cout << "Nhap huan luyen vien: "; getline(cin, huan_luyen_vien);
		for (int i = 0; i < 3; i++)
		{
			cout << "\n-----Cau thu thu " << i + 1 << "/3 : " << endl;
			ct[i].nhap();
		}
	}
	void xuat()
	{
		ofstream VLEAGUE("VLEAGUE.txt", ios::app);
		VLEAGUE << "Ten doi: " << ten_doi
			<< "\t\tDia phuong: " << dia_phuong
			<< "\t\tHuan luyen vien: " << huan_luyen_vien << endl;
		cout << "DS cau thu: " << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "\n-----Cau thu thu " << i + 1 << "/3 : " << endl;
			ct[i].xuat();
		}
	}
	void get_ds()
	{
		for (int i = 0; i < 3; i++)
		{
			cout << "\n-----Cau thu thu " << i + 1 << "/3 : " << endl;
			ct[i].xuat();
		}
	}
};
class TranDau/*:public VLEAGUE*/
{
	int dd, mm, yy, diem_doi_1, diem_doi_2;
	string ten_doi_1, ten_doi_2, san_thi_dau;
public:
	TranDau(int dd=0, int mm=0, int yy=0, string san_thi_dau="", string ten_doi_1="", string ten_doi_="", int diem_doi_1=0, int diem_doi_2=0)
	{
		this->dd = dd;
		this->mm = mm;
		this->yy = yy;
		this->san_thi_dau = san_thi_dau;
		this->diem_doi_1 = diem_doi_1;
		this->diem_doi_2 = diem_doi_2;
		this->diem_doi_1 = diem_doi_1;
		this->diem_doi_2 = diem_doi_2;
	}
	void nhap()
	{
		
		cout << "Nhap nhay thi dau (dd/mm/yy): "; cin >> dd >> mm >> yy;
		cout << "Nhap san thi dau: "; cin.ignore(); getline(cin, san_thi_dau);
		cout << "Nhap ten doi 1: "; getline(cin, ten_doi_1);
		cout << "Nhap ten doi 2: "; getline(cin, ten_doi_2);
		cout << "Ban thang doi 1: "; cin >> diem_doi_1;
		cout << "Ban thang doi 2: "; cin >> diem_doi_2;
	}
	void xuat()
	{
		ofstream VLEAGUE("VLEAGUE.txt", ios::app);
		VLEAGUE << "Ngay thi dau: " << dd << "/" << mm << "/" << yy
			<< "\t\tSan thi dau: " << san_thi_dau
			<< "\t\tTen doi 1: " << ten_doi_1 << "\t\tBan thang: " << diem_doi_1
			<< "\tTen doi 2: " << ten_doi_2 << "\t\tBan thang: " << diem_doi_2
			<< endl;			
	}
};
int main()
{
	ofstream VLEAGUE("VLEAGUE.txt",ios::app);
	
	//tam cho moi doi co 3 cau thu de tiet kiem thoi gian nhap
	//DS cau thu 
	int n_ct;
	cout << "\n-----Nhap so cau thu tham du: "; cin >> n_ct;
	CauThu *ct = new CauThu[n_ct];
	for (int i = 0; i < n_ct; i++)
	{
		ct[i].nhap();
	}
	for (int i = 0; i < n_ct; i++)
	{
		ct[i].xuat();
	}
	//DS doi bong
	int n_db;
	cout << "\n-----Nhap so doi bong tham du: "; cin >> n_db;
	DoiBong *db = new DoiBong[n_db];
	for (int i = 0; i < n_db; i++)
	{
		db[i].nhap();
	}
	for (int i = 0; i < n_db; i++)
	{
		db[i].xuat();
	}
	//DS tran dau
	int n_td;
	cout << "\n-----Nhap so tran dau dien ra: "; cin >> n_td;
	TranDau *td = new TranDau[n_td];
	for (int i = 0; i < n_td; i++)
	{
		td[i].nhap();
	}
	for (int i = 0; i < n_td; i++)
	{
		td[i].xuat();
	}
	//1 cau thu, 1doi bong, 1tran dau
	VLEAGUE << "-----Thong tin cho 1 cau thu: " << endl;
	ct[0].xuat();
	VLEAGUE << "-------------------------------\n" << endl;
	VLEAGUE << "-----Thong tin cho 1 doi bong: " << endl;
	db[0].xuat();
	VLEAGUE << "-------------------------------\n" << endl;
	VLEAGUE << "-----Thong tin cho 1 tran dau: " << endl;
	td[0].xuat();
	VLEAGUE << "-------------------------------\n" << endl;
	//DS cau thu trong 1 doi bong
	db[0].get_ds();

}