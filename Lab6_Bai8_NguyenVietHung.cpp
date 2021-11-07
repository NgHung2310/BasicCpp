#include<iostream>
#include<string>
using namespace std;
class MatHang
{
protected:
	string ten_mat_hang;
	int so_luong;
public:
	virtual void nhap()
	{
		cout << "Nhap ten mat hang: "; cin.ignore(); getline(cin, ten_mat_hang);
		cout << "Nhap so luong: "; cin >> so_luong;
	}
	virtual void xuat()
	{
		cout << "Ten mat hang: " << ten_mat_hang << "\tSo luong: " << so_luong;
	}
	int nhap_kho(int p) 
	{
		so_luong+=p;
		return so_luong;
	}
	int xuat_kho(int p) 	
	{
		so_luong-=p;
		return so_luong;
	}
	
};
class MHNhapKhau:public MatHang
{
	float thue;
public:
	void nhap()
	{
		MatHang::nhap();
		cout << "Nhap thue: "; cin >> thue;
	}
	void xuat()
	{
		MatHang::xuat();
		cout << "\tThue: " << thue << endl;
	}
	//float nhap_kho()
	//{
	//	MatHang::nhap_kho();
	//}
	//float xuat_kho()
	//{
	//	MatHang::xuat_kho();
	//}
	void tang_thue(int a) 
	{ 
		thue += a; 
	}
	void giam_thue(int a) 
	{
		thue -= a;
	}
};
class MHDaiLy :public MatHang
{
	float hoa_hong;
public:
	void nhap()
	{
		MatHang::nhap();
		cout << "Nhap hoa hong: "; cin >> hoa_hong;
	}
	void xuat()
	{
		MatHang::xuat();
		cout << "\tHoa hong: " << hoa_hong << endl;
	}
	void tang_hoa_hong(int a) 
	{
		hoa_hong += a;
	}
	void giam_hoa_hong(int a) 
	{
		hoa_hong -= a;
	}

};
int main()
{
	int i = 0; int n;
	int chon;
	MatHang *mh[100];
	//Nhap ds ban dau
	while (i<100)
	{
		cout << "1. Hang nhap khau\n2. Hang dai ly\n3. Thoat" << endl;
		cout << "Nhap lua chon nhap hang: "; cin >> chon;
		if (chon == 1)
			mh[i] = new MHNhapKhau();
		else if (chon == 2)
			mh[i] = new MHDaiLy();
		else if (chon == 3)
			break;
		else
		{
			cout << "Chon khong hop le! " << endl;
			continue;
		}
		mh[i]->nhap();
		i++;
		n = i;
	}
	//ds vua nhap
	cout << "\n-----DS mat hang vua nhap: " << endl;
	for (int j = 0; j < n; j++)
	{
		cout << j + 1 << ". ";
		mh[j]->xuat();
	}
	//nhap kho
	cout << "\n-----Nhap hang vao kho: " << endl; 
	cout << "1. Nhap mat hang co san\n2. Nhap mat hang moi\nTuy chon nhap kho: " ;
	int chon_nk; cin >> chon_nk;
	if (chon_nk == 2)
		while (i < 100)
		{
			cout << "1. Hang nhap khau\n2. Hang dai ly\n3. Thoat" << endl;
			cout << "Nhap lua chon nhap hang: "; cin >> chon;
			if (chon == 1)
				mh[i] = new MHNhapKhau();
			else if (chon == 2)
				mh[i] = new MHDaiLy();
			else if (chon == 3)
				break;
			else
			{
				cout << "Chon khong hop le! " << endl;
				continue;
			}
			mh[i]->nhap();
			i++;
			n = i;
		}
	else if (chon_nk == 1)
	{
		int stt, sl;
		cout << "\n-----Nhap STT mat hang muon nhap kho: "; cin >> stt; stt--;
		cout << "\n-----Nhap so luong muon nhap: "; cin >> sl;
		mh[stt]->nhap_kho(sl);
	}
	
	//xuat kho
	int stt, sl;
	cout << "\n-----Nhap STT mat hang muon xuat kho: "; cin >> stt; stt--;
	cout << "\n-----Nhap so luong muon xuat: "; cin >> sl;
	mh[stt]->xuat_kho(sl);
	//Thong ke lai ds mat hang
	cout << "\n-----Bao cao so luong: " << endl;
	for (int j = 0; j < n; j++)
	{
		cout << j + 1 << ". ";
		mh[j]->xuat();
	}

}