#include<string>
#include <iostream>
#include<vector>
using namespace std;
struct NGAY_GD
{
	int ngay, thang, nam;
};
class GiaoDich
{
protected:
	string ma_gd;
	NGAY_GD ngay_gd;
	float don_gia;
	int so_luong;
	float thanh_tien;
public:
	GiaoDich() {}
	~GiaoDich() {}
	virtual void nhap()
	{
		cout << "Nhap ma GD: ";
		cin.ignore(); getline(cin, ma_gd);
		cout << "Nhap ngay GD(dd/mm/yy): ";
		cin >> ngay_gd.ngay >> ngay_gd.thang >> ngay_gd.nam;
		cout << "Nhap don gia: "; cin >> don_gia;
		cout << "Nhap so luong: "; cin >> so_luong;
	}
	virtual void xuat()
	{
		cout << "Ma GD: " << ma_gd
			<< "\tNgay GD: " << ngay_gd.ngay << "/" << ngay_gd.thang << "/" << ngay_gd.nam
			<< "\t\tDon gia: " << don_gia
			<< "\tSo luong: " << so_luong;
	}
	virtual string loai_gd() { return ""; }
	virtual float get_thanh_tien() = 0;

	float get_don_gia()
	{
		return don_gia;
	}

	int get_ngay() { return ngay_gd.ngay; }
	int get_thang() { return ngay_gd.thang; }
	int get_nam() { return ngay_gd.nam; }
};

class GDVang:public virtual GiaoDich
{
	string loai_vang;
public:
	GDVang() {}
	~GDVang() {}
	void nhap()
	{
		GiaoDich::nhap();
		cout << "Nhap loai vang: "; cin.ignore(); getline(cin, loai_vang);
		thanh_tien = so_luong * don_gia;
	}
	void xuat()
	{
		GiaoDich::xuat();
		cout << "\tLoai vang: " << loai_vang
			<< "\tThanh tien: " << thanh_tien << endl;
	}

	string loai_gd()
	{
		return "vang";
	}

	float get_thanh_tien()
	{
		return thanh_tien;
	}
};

class GDTien:public virtual GiaoDich
{
	float ti_gia;
	string loai_tien;
public:
	GDTien() {}
	~GDTien() {}
	void nhap()
	{
		GiaoDich::nhap();
		cout << "Nhap ti gia: "; cin >> ti_gia;
		cout << "Nhap loai tien(VND, USD, EURO): ";
		cin.ignore(); getline(cin, loai_tien);
		thanh_tien = loai_tien == ("VND") ? so_luong * don_gia : so_luong * don_gia*ti_gia;
	}
	void xuat()
	{
		GiaoDich::xuat();
		cout << "\tTi gia: " << ti_gia
			<< "\tLoai tien: " << loai_tien
			<< "\tThanh tien: " << thanh_tien << endl;
	}

	string loai_gd()
	{
		return "tien";
	}

	float get_thanh_tien()
	{
		return thanh_tien;
	}
};

class QuanLy_GD
{
public:
	QuanLy_GD() {}
	~QuanLy_GD() {}
	GiaoDich *gd[50];
	int n;
	//Nhap DS GD
	void nhap_dsgd()
	{
		int i=0, selecter;
		while (true)
		{
			cout << "\n1.GD Vang"
				<< "\n2.GD Tien te"
				<< "\n3.Thoat"
				<< "\nLua chon: ";
			cin >> selecter;
			if (selecter == 1)
				gd[i] = new GDVang();
			else if (selecter == 2)
				gd[i] = new GDTien();
			else if (selecter == 3)
				break;
			else
			{
				cout << "Lua chon khong hop le!!!";
				continue;
			}
			gd[i]->nhap();
			i++;
			n = i;
		}
	}
	//Xuat DS GD
	void xuat_dsgd()
	{
		cout << "\n-----DS giao dich-----" << endl;
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ". ";
			gd[i]->xuat();
		}
	}
	//So luong gd vang
	int so_luong_gd_vang()
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
		{
			if (gd[i]->loai_gd() == "vang")
				idx++;
		}
		return idx;
	}
	//so luong gd tien te
	int so_luong_gd_tien()
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
		{
			if (gd[i]->loai_gd() == "tien")
				idx++;
		}
		return idx;
	}
	//trung binh thanh tien cua GD tien te
	float tb_thanhtien_gd_tien()
	{
		float sum = 0;
		int idx = 0;
		for (int i = 0; i < n; i++)
		{
			if (gd[i]->loai_gd() == "tien")
			{
				sum += gd[i]->get_thanh_tien();
				idx++;
			}
		}
		return sum / idx;
	}
	//GD co don gia >1ty
	void gd_don_gia_hon_1ty()
	{	
		cout << "\n-----GD co don gia >1ty-----" << endl;
		for (int i = 0; i < n; i++)
		{
			if (gd[i]->get_don_gia() > 1000000000)
				gd[i]->xuat();
		}
	}
	//GD vang ngay 20/3/2015
	int gd_vang_ngay_20_3_2015()
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
		{
			if (gd[i]->loai_gd() == "vang"
				&& gd[i]->get_ngay() == 20
				&& gd[i]->get_thang() == 3
				&& gd[i]->get_nam() == 2015)
				idx++;
		}
		return idx;
	}
	//Sap xep theo ngay gd
	void swap(GiaoDich *a, GiaoDich *b)
	{
		if (a->get_nam() > b->get_nam()
			&&a->get_thang() > b->get_thang()
			&& a->get_ngay() > b->get_ngay())
		{
			swap(a, b);
		}
	}
	void sap_xep()
	{
		for (int i = 0; i < n-1; i++)
			for (int j = i + 1; j < n; j++)
			{
				swap(gd[i], gd[i]);
			}
	}
	//Them gd
	void them_gd()
	{
		cout << "Them GD o cuoi: " << endl;
		int selecter;
	loop:
		cout << "\n1.GD Vang"
			<< "\n2.GD Tien te"
			<< "\nLua chon: ";
		cin >> selecter;
		if (selecter == 1)
			gd[n] = new GDVang();
		else if (selecter == 2)
			gd[n] = new GDTien();
		else
		{
			cout << "Lua chon khong hop le!!!";
			goto loop;
		}
		gd[n]->nhap();
		n++;
	}
	//Xoa gd vang 20/5/2010
	void xoa_gd_vang_ngay_20_05_2010()
	{
		for (int i = 0; i < n; i++)
		{
			if (gd[i]->loai_gd() == "vang"
				&& gd[i]->get_ngay() == 20
				&& gd[i]->get_thang() == 5
				&& gd[i]->get_nam() == 2010)
			{
				for (int j = i; j < n - 1; j++)
				{
					gd[j] = gd[j + 1];
				}
				n--;
			}
		}
	}
};

int main()
{
	QuanLy_GD *ql=new QuanLy_GD;
	ql->nhap_dsgd();
	ql->xuat_dsgd();
	cout << "\nSo luong GD vang: " << ql->so_luong_gd_vang() << endl;
	cout << "\nSo luong GD tien: " << ql->so_luong_gd_tien() << endl;
	ql->gd_don_gia_hon_1ty();
	cout << "\nSo luong GD vang ngay 20/3/2015: " << ql->gd_vang_ngay_20_3_2015() << endl;
	ql->sap_xep();
	ql->them_gd();
	ql->xoa_gd_vang_ngay_20_05_2010();
	ql->xuat_dsgd();
}