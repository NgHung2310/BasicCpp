#include <iostream>
#include<string>
#include<math.h>
using namespace std;
class DocGia
{
protected:
	string ma, ho_ten;
	int so_thang_hl;
public:
	virtual void nhap()
	{
		cout << "Nhap ma: "; cin.ignore(); getline(cin, ma);
		cout << "Nhap ho ten: "; getline(cin, ho_ten);
		cout << "Nhap so thang hieu luc: "; cin >> so_thang_hl;
	}
	virtual void xuat()
	{
		cout << "Ma: " << ma
			<< "\tHo ten: " << ho_ten
			<< "\t\tSo thang hieu luc: " << so_thang_hl;
	}	
	virtual int tim() =0;

	virtual int tienthe() = 0;
};
class DGTre:public DocGia
{
	int nam_sinh;
public:
	void nhap()
	{
		DocGia::nhap();
		cout << "Nhap nam sinh: "; cin >> nam_sinh;
	}
	void xuat()
	{
		DocGia::xuat();
		cout << "\tNam sinh: " << nam_sinh << endl;
	}
	int tim()
	{
		if (so_thang_hl < 10)
			return 1;
		else 
			return 0;
	}
	int tienthe()
	{
		return so_thang_hl * 20000;
	}
};
class DGLon:public DocGia
{
	string nghe_nghiep;
public:
	void nhap()
	{
		DocGia::nhap();
		cout << "Nhap nghe nghiep: "; cin.ignore(); getline(cin, nghe_nghiep);
	}
	void xuat()
	{
		DocGia::xuat();
		cout << "\tNghe nghiep: " << nghe_nghiep << endl;
	}
	int tim()
	{
		if (nghe_nghiep == "giang vien")
			return 1;
		else 
			return 0;
	}
	int tienthe()
	{
		return so_thang_hl * 30000;
	}
};
class QLDocGia
{
public:
	int i = 0,tong_tien_the=0,n=0;
	DocGia *dg[30];
	void nhap()
	{
		while (true)
		{
		
			cout << "\n1. Doc gia tre\n2. Doc gia lon\n3. Thoat" << endl;
			int choose;
			cout << "Nhap lua chon: "; cin >> choose;
			if (choose == 1)
			{
				dg[i] = new DGTre();
			}
			else if (choose == 2)
			{
				dg[i] = new DGLon();
			}
			else if (choose == 3)
				break;
			else
			{
				cout << "\n-----Nhap khong hop le: " << endl;
				continue;
			}
			dg[i]->nhap();
			tong_tien_the += dg[i]->tienthe();
			i++;
			n = i;
		}
		cout << "\n-----Tong thien the: " << tong_tien_the << endl;
	
	}
	void tim()
	{
		cout << "\nDS doc gia can tim: " << endl;
		int j = 0;	
		while(j<n)
		{
			if (dg[j]->tim()==0)
			{

				dg[j]->xuat();
			}
			j++;			
		}
	}
};
int main()
{
	QLDocGia *a=new QLDocGia();
	a->nhap();
	a->tim();
}
