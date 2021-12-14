#include<string>
#include <iostream>
#include<vector>
using namespace std;

class Quay
{
protected:
	string ma_quay;
	int STT_quay;
	float dien_tich, doanh_thu;
public:
	virtual void nhap()
	{
		cout << "Nhap ma quay: "; cin.ignore(); getline(cin, ma_quay);
		cout << "Nhap STT quay: "; cin >> STT_quay;
		cout << "Nhap dien tich mat bang: "; cin >> dien_tich;
		cout << "Nhap doanh thu: "; cin >> doanh_thu;
	}
	virtual void xuat()
	{
		cout << "Ma quay: " << ma_quay
			<< "\tSTT: " << STT_quay
			<< "\tDien tich: " << dien_tich
			<< "\tTien doanh thu: " << doanh_thu ;
	}
	virtual float tien_thue_quay()
	{
		return 50000000 * dien_tich;
	}
	virtual float thue_doanh_thu() = 0;
	virtual float tien_dich_vu() = 0;
	virtual float tien_phai_dong()
	{
		return tien_thue_quay() + thue_doanh_thu() + tien_dich_vu();
	}
	virtual int loai_quay() = 0;
};

class QuayThucPham :public virtual Quay
{
	float dich_vu;
public:
	void nhap()
	{
		Quay::nhap();
		cout << "Nhap tien dich vu: "; cin >> dich_vu;
	}
	void xuat()
	{
		Quay::xuat();
		cout << "\tTien dich vu: " << dich_vu << endl;
	}
	virtual float tien_thue_quay()
	{
		return 50000000 * dien_tich;
	}
	virtual float thue_doanh_thu()
	{
		return doanh_thu * 5 / 100;
	}
	virtual float tien_dich_vu()
	{
		return dich_vu;
	}
	virtual float tien_phai_dong()
	{
		return tien_thue_quay() + thue_doanh_thu() + tien_dich_vu();
	}
	int loai_quay()
	{
		return 1;
	}
};

class QuayQuanAo :public virtual Quay
{
public:
	void nhap()
	{
		Quay::nhap();		
	}
	void xuat()
	{
		Quay::xuat();
		cout << endl;
	}
	virtual float tien_thue_quay()
	{
		return 50000000 * dien_tich;
	}
	virtual float thue_doanh_thu()
	{
		return doanh_thu * 10 / 100;
	}
	virtual float tien_dich_vu()
	{
		return 0;
	}
	virtual float tien_phai_dong()
	{
		return tien_thue_quay() + thue_doanh_thu() + tien_dich_vu();
	}
	int loai_quay()
	{
		return 2;
	}
};

class QuayTrangSuc :public virtual Quay
{
public:
	void nhap()
	{
		Quay::nhap();
	}
	void xuat()
	{
		Quay::xuat();
		cout << endl;
	}
	virtual float tien_thue_quay()
	{
		return 50000000 * dien_tich;
	}
	virtual float thue_doanh_thu()
	{
		if(doanh_thu<100000000)
			return doanh_thu * 20 / 100;
		else
			return doanh_thu * 30 / 100;
	}
	virtual float tien_dich_vu()
	{
		return 0;
	}
	virtual float tien_phai_dong()
	{
		return tien_thue_quay() + thue_doanh_thu() + tien_dich_vu();
	}
	int loai_quay()
	{
		return 3;
	}
};

class SieuThi
{
	Quay *qu[50];
	int n;
public:
	void nhap_quay()
	{
		int choose;
		int i = 0;
		while (true)
		{
			cout <<"\t---------------"
				<< "\n1. Quay thuc pham"
				<< "\n2. Quay quan ao"
				<< "\n3. Quay trang suc"
				<< "\n4. Thoat"
				<< "\nLua chon: ";
			cin >> choose;
			
			
			if (choose == 1)
				qu[i] = new QuayThucPham;		
			else if (choose == 2)
				qu[i] = new QuayQuanAo;			
			else if (choose == 3)
				qu[i] = new QuayTrangSuc;			
			else if (choose == 4)
				break;
			else
			{
				cout << "Chon khong hop le!!" << endl;
				continue;
			}
			
			qu[i]->nhap();
			i++;
			n = i;		
		}

	}
	void xuat_ds()
	{
		for (int i = 0; i < n; i++)
		{
			qu[i]->xuat();
		}
	}

	int dem_quay_thuc_pham()
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
		{
			if (qu[i]->loai_quay() == 1)
				idx++;
		}
		return idx;
	}

	int dem_quay_quan_ao()
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
		{
			if (qu[i]->loai_quay() == 2)
				idx++;
		}
		return idx;
	}

	int dem_quay_tang_suc()
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
		{
			if (qu[i]->loai_quay() == 3)
				idx++;
		}
		return idx;
	}

	void tong_tien()
	{
		for (int i = 0; i < n; i++)
		{
			cout << endl;
			qu[i]->xuat();
			cout<<"->Tong tien thue mat bang: " << qu[i]->tien_phai_dong() << endl;
		}
	}
};

int main()
{
	SieuThi st;
	cout << "-----Nhap DS quay hang-----" << endl;
	st.nhap_quay();
	cout << "\n-----DS cac quay hang vua nhap-----" << endl;
	st.xuat_ds();
	cout << "-----So luong quay thuc pham: " << st.dem_quay_thuc_pham() << endl;
	cout << "-----So luong quay quan ao: " << st.dem_quay_quan_ao() << endl;
	cout << "-----So luong quay trang suc: " << st.dem_quay_tang_suc() << endl;
	cout << "\n-----So tien cac quay phai dong-----" << endl;
	st.tong_tien();
}