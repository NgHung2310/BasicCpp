#include<iostream>
#include<string>
using namespace std;
class XE
{
public:
	virtual void nhap() {}
	virtual void xuat() {}
	virtual double get_doanh_thu() = 0;
	virtual string loai_xe() { return ""; }
};
class NoiThanh:public XE
{
	string ma_chuyen, tai_xe;
	int so_xe, so_tuyen;
	double so_km, doanh_thu;
public:
	void nhap()
	{
		cout << "-----Nhap tt xe noi thanh: " << endl;
		cout << "Nhap ma so chuyen: "; cin.ignore(); getline(cin, ma_chuyen);
		cout << "Nhap ten tai xe: "; getline(cin, tai_xe);
		cout << "Nhap so xe: "; cin >> so_xe;
		cout << "Nhap so chuyen: "; cin >> so_tuyen;
		cout << "Nhap so km di duoc: "; cin >> so_km;
		cout << "Nhap doanh thu: "; cin >> doanh_thu;
	}
	void xuat()
	{
		cout << "-----Xe noi thanh: " << endl;
		cout << "Ma so chuyen: " << ma_chuyen
			<< "\tTai xe: " << tai_xe
			<< "\tSo xe: " << so_xe
			<< "\tSo tuyen: " << so_tuyen
			<< "\tSo km: " << so_km
			<< "\tDoanh thu: " << doanh_thu << endl;
	}
	double get_doanh_thu()
	{
		return doanh_thu;
	}
	string loai_xe()
	{
		return "noi thanh";
	}
};
class NgoaiThanh :public XE
{
	string ma_chuyen, tai_xe,noi_den;
	int so_xe,so_ngay_di;
	double doanh_thu;
public:
	void nhap()
	{
		cout << "-----Nhap tt xe ngoai thanh: " << endl;
		cout << "Nhap ma so chuyen: "; cin.ignore(); getline(cin, ma_chuyen);
		cout << "Nhap ten tai xe: "; getline(cin, tai_xe);
		cout << "Nhap so xe: "; cin >> so_xe;
		cout << "Nhap noi den: "; cin >> noi_den;
		cout << "Nhap so ngay di duoc: "; cin >> so_ngay_di;
		cout << "Nhap doanh thu: "; cin >> doanh_thu;
	}
	void xuat()
	{
		cout << "-----Xe ngoai thanh: " << endl;
		cout << "Ma so chuyen: " << ma_chuyen
			<< "\tTai xe: " << tai_xe
			<< "\tSo xe: " << so_xe
			<< "\tNoi den: " << noi_den
			<< "\tSo ngay di: " << so_ngay_di
			<< "\tDoanh thu: " << doanh_thu << endl;
	}
	double get_doanh_thu()
	{
		return doanh_thu;
	}
	string loai_xe()
	{
		return "ngoai thanh";
	}
};
int main()
{
	int i = 0, n = 0;
	XE *xe[50];
	int chon;
	while (true)
	{
		cout << "1. Xe noi thanh\n2. Xe ngoai thanh\n3. Thoat\nNhap lua chon: "; cin >> chon;
		if (chon == 1)
			xe[i] = new NoiThanh();
		else if (chon == 2)
			xe[i] = new NgoaiThanh();
		else if (chon == 3)
			break;
		else
		{
			cout << "Nhap khong hop le!!\n--------------------------" << endl;
			continue;
		}
		xe[i]->nhap();
		cout << "--------------------------" << endl;
		i++;
		n = i;
	}
	cout << "\n-----DS vua nhap: " << endl;
	for (int j = 0; j < n; j++)
	{
		xe[j]->xuat();
	}
	//
	double tong_doanh_thu_noi_thanh = 0;
	for (int j = 0; j < n; j++)
	{
		if (xe[j]->loai_xe() == "noi thanh")
			tong_doanh_thu_noi_thanh += xe[j]->get_doanh_thu();
	}
	cout << "\n-----Tong doanh thu xe noi thanh: " << tong_doanh_thu_noi_thanh << endl;
	//
	double tong_doanh_thu_ngoai_thanh = 0;
	for (int j = 0; j < n; j++)
	{
		if (xe[j]->loai_xe() == "ngoai thanh")
			tong_doanh_thu_ngoai_thanh += xe[j]->get_doanh_thu();
	}
	cout << "\n-----Tong doanh thu xe ngoai thanh: " << tong_doanh_thu_ngoai_thanh << endl;
}