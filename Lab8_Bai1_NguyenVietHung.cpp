#include<string>
#include <iostream>
#include<vector>
using namespace std;

class Basic
{
protected:
	int thoi_gian_goi, don_gia_goi;
	int luu_luong, don_gia_truy_cap;
public:
	Basic(int thoi_gian_goi=0,int don_gia_goi=0, int luu_luong=0,int don_gia_truy_cap=0)
	{
		this->thoi_gian_goi = thoi_gian_goi;
		this->luu_luong = luu_luong;
		this->don_gia_goi = don_gia_goi;
		this->don_gia_truy_cap = don_gia_truy_cap;
	}
	~Basic() {}
	virtual void nhap()
	{
		cout << "Nhap thoi gian goi(phut): "; cin >> thoi_gian_goi;		
		cout << "Nhap luu luong truy cap(MB): "; cin >> luu_luong;
		don_gia_goi = 1000;
		don_gia_truy_cap = 200;
	}
	virtual void xuat()
	{
		cout << "Thoi gian goi: " << thoi_gian_goi
			<< "\tLuu luong truy cap: " << luu_luong << endl;
	}
	virtual int cuoc_dien_thoai()
	{
		return thoi_gian_goi * don_gia_goi;
	}
	virtual int cuoc_internet()
	{
		return luu_luong * don_gia_truy_cap;
	}
	virtual int cuoc_tong()
	{
		return cuoc_dien_thoai() + cuoc_internet();
	}

};

class DataFree :public virtual Basic
{
	int nguong_free;
public:
	
	DataFree(int nguong_free=0) :Basic( thoi_gian_goi, don_gia_goi, luu_luong, don_gia_truy_cap)
	{
		this->nguong_free = nguong_free;
	}
	~DataFree() {}
	void nhap()
	{
		Basic::nhap();
		cout << "Nhap nguong luu luong free(MB): "; cin >> nguong_free;
	}
	void xuat()
	{
		Basic::xuat();
		cout << "Nguong luu luong free: " << nguong_free << endl;
	}
	int cuoc_dien_thoai()
	{
		return thoi_gian_goi * don_gia_goi;
	}
	int cuoc_internet() 
	{
		if (luu_luong <= nguong_free)
			return 0;
		else
			return (luu_luong - nguong_free) * 200;
	}
	int cuoc_tong()
	{
		return cuoc_dien_thoai()+ cuoc_internet();

	}
};

class DataFix :public virtual Basic
{
public:
	~DataFix() {}
	void nhap()
	{
		Basic::nhap();
	}
	void xuat()
	{
		Basic::xuat();
	}
	int cuoc_dien_thoai()
	{
		return thoi_gian_goi * don_gia_goi*9/10;
	}
	int cuoc_internet()
	{
		return 1000000;//1tr
	}
	int cuoc_tong()
	{
		return cuoc_dien_thoai() + cuoc_internet();

	}
};

class KhachHang
{
protected:
	string ho_ten, dia_chi, goi_cuoc;
	unsigned int cmt;
public:
	KhachHang(string ho_ten="" , unsigned int cmt=0 , string dia_chi="" , string goi_cuoc="" )
	{
		this->ho_ten = ho_ten;
		this->cmt = cmt;
		this->dia_chi = dia_chi;
		this->goi_cuoc = goi_cuoc;
	}
	~KhachHang() {}
	void nhap()
	{
		cout << "Nhap ho ten khach hang: "; cin.ignore();  getline(cin, ho_ten);
		cout << "Nhap CMT/CCCD: "; cin >> cmt;
		cout << "Nhap dia chi: "; cin.ignore(); getline(cin, dia_chi);
		cout << "Nhap goi cuoc(Data Free, Data Fix): "; getline(cin, goi_cuoc);
	}
	void xuat()
	{
		cout << "Ho ten: " << ho_ten
			<< "\nCMT/CCCD: " << cmt
			<< "\nDia chi: " << dia_chi
			<< "\nGoi cuoc: " << goi_cuoc << endl;
	}
	int tinh_cuoc()
	{
		Basic *p[1];
		if (goi_cuoc == "Data Free")
		{
			p[0] = new DataFree;
		}
		else if(goi_cuoc == "Data Fix")
		{
			p[0] = new DataFix;
		}
		p[0]->nhap();
		
		return p[0]->cuoc_tong();
	}
};

class HopDong
{

public:
	KhachHang *kh = new KhachHang[50];
	int n;
	void dang_ky()
	{
		int i = 0;
		int choose;
		while (true)
		{
			cout << "\n1.KH dang ky moi \n2.Thoat \nLua chon: " ;
			cin >> choose;
			if (choose == 1)
			{
				kh[i].nhap();
				//kh[i].tinh_cuoc();				
				i++;
				n = i;
			}
			else if(choose ==2)
				break;
			else
			{
				cout << "Chon khong hop le!!" << endl<<endl;
				continue;
			}				
						
		}
	}
	void ds_dang_ky()
	{
		for (int i = 0; i < n; i++)
		{
			cout << "\n-----Khach hang thu " << i + 1 << " : " << endl;
			kh[i].xuat();
		}
	}
	void thong_bao_tien_cuoc()
	{
		for (int i = 0; i < n; i++)
		{
			cout << "\n-----Khach hang thu " << i + 1 << " : " << endl;
			kh[i].xuat();
			cout << "->Tong tien cuoc:" << kh[i].tinh_cuoc() << endl;
		}
	}
};
int main()
{
	HopDong hd;
	hd.dang_ky();
	cout << "\n\n-----DS khach hang-----" << endl;
	hd.ds_dang_ky();
	cout << "\n\n-----Tien cuoc-----" << endl;
	hd.thong_bao_tien_cuoc();
}