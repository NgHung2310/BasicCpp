#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<string>
using namespace std;
class HangHoa
{
protected:
	string ma_hang, ten_hang;
	int don_gia;
public:
	HangHoa()
	{
		this->ma_hang = "";
		this->ten_hang = "";
		this->don_gia = 0;
	}
	HangHoa(string ma_hang, string ten_hang, int don_gia)
	{
		this->ma_hang = ma_hang;
		this->ten_hang = ten_hang;
		this->don_gia = don_gia;
	}
	~HangHoa() {}
	friend istream &operator>>(istream &is, HangHoa &hh)
	{
		cout << "Nhap ma hang hoa: "; cin.ignore(); getline(is, hh.ma_hang);
		cout << "Nhap ten hang hoa: "; getline(is, hh.ten_hang);
		cout << "Nhap don gia: "; is >> hh.don_gia;
		return is;
	}
	friend ostream &operator<<(ostream &os, HangHoa &hh)
	{
		os << "Ma hang: " << hh.ma_hang
			<< "\t\tTen hang: " << hh.ten_hang
			<< "\t\tDon gia: " << hh.don_gia;
		return os;
	}
	string get_ma_hang()
	{
		return ma_hang;
	}
	string get_ten_hang()
	{
		return ten_hang;
	}
};
class MT :public HangHoa
{
protected:
	int toc_do, so_luong;
public:
	MT()
	{
		this->toc_do = 0;
		this->so_luong = 0;
	}
	MT(string ma_hang, string ten_hang, int don_gia, int toc_do, int so_luong) :HangHoa(ma_hang, ten_hang, don_gia)
	{
		this->toc_do = toc_do;
		this->so_luong = so_luong;
	}
	~MT() {}
	friend istream &operator>>(istream &is, MT &mt)
	{
		is >> (HangHoa&)mt;
		cout << "Nhap toc do: "; cin >> mt.toc_do;
		cout << "Nhap so luong: "; cin >> mt.so_luong;
		return is;
	}
	friend ostream &operator<<(ostream &os, MT mt)
	{
		os << (HangHoa&)mt
			<< "\tToc do: " << mt.toc_do
			<< "\tSo luong: " << mt.so_luong;
		return os;
	}
	int thanh_tien()
	{
		return so_luong * don_gia;
	}
	int get_toc_do()
	{
		return toc_do;
	}
	string get_ma_hang()
	{
		return ma_hang;
	}
};
class MTXT :public MT
{
	float trong_luong;
public:
	MTXT()
	{
		this->trong_luong = 0;
	}
	MTXT(string ma_hang, string ten_hang, int don_gia, int toc_do, int so_luong, float trong_luong) :MT(ma_hang, ten_hang, don_gia, toc_do, so_luong)
	{
		this->trong_luong = trong_luong;
	}
	~MTXT() {}
	int phi_bao_tri()
	{
		return don_gia * 5 / 100;
	}
	friend istream &operator>>(istream &is, MTXT &mtxt)
	{
		is >> (MT&)mtxt;
		cout << "Nhap trong luong: "; is >> mtxt.trong_luong;
		return is;
	}
	friend ostream &operator<<(ostream &os, MTXT mtxt)
	{
		os << (MT&)mtxt
			<< "\tTrong luong: " << mtxt.trong_luong << endl;
		return os;
	}
};
int main()
{
	int n; cout << "-----So luong may tinh xach tay: "; cin >> n;
	MTXT *mtxt = new MTXT[n];
	//Nhap ds
	for (int i = 0; i < n; i++)
	{
		cout << "\n-----Nhap tt cho mtxt thu " << i + 1 << " : " << endl;
		cin >> mtxt[i];
	}
	//xuat ds
	cout << "\n-----DS vua nhap: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << mtxt[i];
	}
	//tim mt theo ma hang
	string tk_ma_mt; cout << "\n-----Ma mtxt can tim: ";
	cin.ignore(); getline(cin, tk_ma_mt);
	for (int i = 0; i < n; i++)
	{
		if (mtxt[i].get_ma_hang() == tk_ma_mt)
		{
			cout << mtxt[i];
		}
	}
	//sap xep theo ten
	for (int i = 0; i < n; i++)
	{
		if (mtxt[i].get_ten_hang() > mtxt[i + 1].get_ten_hang())
		{
			MTXT tg;
			tg = mtxt[i];
			mtxt[i] = mtxt[i + 1];
			mtxt[i + 1] = tg;
		}
	}
	cout << "\n-----DS sau khi sap xep theo ten: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << mtxt[i];
	}
	//Tong phi bao tri
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = mtxt[i].phi_bao_tri();
	}
	cout << "\n-----Tong phi bao tri: " << sum << endl;
	//mt toc do nho nhat
	int speed_min = mtxt[0].get_toc_do();
	for (int i = 0; i < n; i++)
	{
		if (speed_min > mtxt[i].get_toc_do())
		{
			speed_min = mtxt[i].get_toc_do();
		}
	}
	//Sua tt mtxt
	int idx; cout << "\n-----Nhap vi tri mtxt muon sua: "; cin >> idx; idx--;
	cin >> mtxt[idx];
	//Xoa mtxt
	string ma_del; cout << "\n-----Nhap ma mtxt muon xoa: ";
	cin.ignore(); getline(cin, ma_del);
	for (int i = 0; i < n; i++)
	{
		if (mtxt[i].get_ma_hang() == ma_del)
		{
			for (; i < n - 1; i++)
				mtxt[i] = mtxt[i + 1];
			n--;
		}
	}
	//them mot mtxt
	int k; cout << "\n-----Vi tri muon chen: "; cin >> k; k--;
	MTXT is_mtxt;
	cin >> is_mtxt;
	//n++;
	//for (int i = n-1; i >k; i--)
	//{				
	//	mtxt[i] = mtxt[i - 1];
	//}
	//mtxt[k] = new_mtxt;
	MTXT *new_mtxt = new MTXT[n + 1];
	for (int i = 0; i < k; i++)
	{
		new_mtxt[i] = mtxt[i];
	}
	new_mtxt[k] = is_mtxt;
	for (int i = k + 1; i < n + 1; i++)
	{
		new_mtxt[i] = mtxt[i - 1];
	}
	//delete mtxt;
	//n++;
	//MTXT *mtxt = new MTXT[n];
	//for (int i = 0; i < n; i++)
	//{
	//	mtxt[i] = new_mt[i];
	//}
	//delete new_mt;
	n++;
	//Sap xep theo ma may
	for (int i = 0; i < n; i++)
	{
		if (new_mtxt[i].get_ma_hang() < new_mtxt[i + 1].get_ma_hang())
		{
			MTXT tg;
			tg = new_mtxt[i];
			new_mtxt[i] = new_mtxt[i + 1];
			new_mtxt[i + 1] = tg;
		}
	}
	cout << "\n-----DS sau khi sap xep theo ma may: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << new_mtxt[i];
	}
}