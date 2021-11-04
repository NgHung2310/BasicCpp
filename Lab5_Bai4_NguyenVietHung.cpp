#include<iostream>
#include<math.h>
#include<string>
using namespace std;
class STUDENT
{
protected:
	string ma_sv, ho_ten, gioi_tinh;
public:
	STUDENT()
	{
		this->ma_sv = this->ho_ten = this->gioi_tinh = "";
	}
	STUDENT(string ma_sv, string ho_ten, string gioi_tinh)
	{
		this->ma_sv = ma_sv;
		this->ho_ten = ho_ten;
		this->gioi_tinh = gioi_tinh;
	}
	~STUDENT() {}
	friend istream &operator>>(istream &is, STUDENT &sv)
	{
		cout << "Nhap ma SV: "; cin.ignore(); getline(is, sv.ma_sv);
		cout << "Nhap ho ten: "; getline(is, sv.ho_ten);
		cout << "Nhap gioi tinh: "; getline(is, sv.gioi_tinh);
		return is;
	}
	friend ostream &operator<<(ostream &os, STUDENT sv)
	{
		os << "Ma SV: " << sv.ma_sv
			<< "\tHo ten: " << sv.ho_ten
			<< "\t\tGioi tinh: " << sv.gioi_tinh;
		return os;
	}
	string get_gioi_tinh()
	{
		return gioi_tinh;
	}
	string get_ho_ten()
	{
		return ho_ten;
	}
};
class MONHOC
{
protected:
	string ma_mon, ten_mon;
public:
	MONHOC()
	{
		this->ma_mon = "";
		this->ten_mon = "";
	}
	MONHOC(string ma_mon, string ten_mon)
	{
		this->ma_mon = ma_mon;
		this->ten_mon = ten_mon;
	}
	~MONHOC() {}
	friend istream &operator>>(istream &is, MONHOC &mh)
	{
		cout << "Nhap ma mon: "; cin.ignore(); getline(is, mh.ma_mon);
		cout << "Nhap ten mon: "; getline(is, mh.ten_mon);
		return is;
	}
	friend ostream &operator<<(ostream &os, MONHOC mh)
	{
		os << "Ma mon: " << mh.ma_mon
			<< "\tTen mon: " << mh.ten_mon;
		return os;
	}
	string get_ten_mon()
	{
		return ten_mon;
	}
};
class DIEMMH :public STUDENT, public MONHOC
{
	float diem_thi;
public:
	DIEMMH()
	{
		this->diem_thi = 0;
	}
	DIEMMH(string ma_sv, string ho_ten, string gioi_tinh, string ma_mon, string ten_mon,float diem_thi)
		:STUDENT( ma_sv,  ho_ten,  gioi_tinh), MONHOC( ma_mon,  ten_mon)
	{
		this->diem_thi = diem_thi;
	}
	~DIEMMH() {}
	friend istream &operator>>(istream &is, DIEMMH &dmh)
	{
		is >> (STUDENT&)dmh >> (MONHOC&)dmh;
		cout << "Nhap diem thi: "; is >> dmh.diem_thi;
		return is;
	}
	friend ostream &operator<<(ostream &os, DIEMMH dmh)
	{
		os << (STUDENT&)dmh << (MONHOC&)dmh << "\t\tDiem thi: " << dmh.diem_thi << endl;
		return os;
	}
	float get_diem()
	{
		return diem_thi;
	}
};
int main()
{
	int n; cout << "-----Nhap so sinh vien: "; cin >> n;
	DIEMMH *sv = new DIEMMH[n];
	//Nhap ds
	for (int i=0; i < n; i++)
	{
		cout << "\n-----Nhap thong tin sv thu " << i + 1 << ": " << endl;
		cin >> sv[i];
	}
	//xuat ds
	for (int i=0; i < n; i++)
	{
		cout << i + 1 << ". " << sv[i];
	}
	//tim sv nam
	cout << "\n-----Sinh vien nam: " << endl;
	for (int i=0; i < n; i++)
	{
		if (sv[i].get_gioi_tinh() == "nam")
			cout << sv[i];
	}
	//trung binh diem
	int idx = 0;
	float sum_diem = 0;
	for (int i=0; i < n; i++)
	{
		sum_diem += sv[i].get_diem();
		idx += i;
	}
	cout << "\n-----Diem trung binh: " << sum_diem / idx << endl;
	//Tim sv
	string tk_ho_ten;
	bool KT_ho_ten = false;
	cout << "\n-----Nhap ten SV can tim: "; cin.ignore(); getline(cin, tk_ho_ten);
	for (int i=0; i < n; i++)
	{
		if (sv[i].get_ho_ten() == tk_ho_ten)
		{
			cout << sv[i];
			KT_ho_ten = true;
		}
	}
	if (!KT_ho_ten)
		cout << "Khong tim thay SV!!!" << endl;
	//tim diem toan min
	float diem_toan_min=9999;
	for (int i=0; i < n; i++)
	{
		if (sv[i].get_ten_mon() == "Toan"&&sv[i].get_diem() < diem_toan_min)
		{
			diem_toan_min = sv[i].get_diem();
		}
	}
	cout << "\n-----Diem Toan nho nhat: " << diem_toan_min << endl;
	//Sap xep theo diem
	for (int i=0; i < n-1; i++)
	{
		if (sv[i].get_diem() < sv[i + 1].get_diem())
		{
			DIEMMH tg;
			tg = sv[i];
			sv[i] = sv[i + 1];
			sv[i + 1] = tg;
		}
	}
	cout << "\n-----DS sau khi sap xep theo diem giam: " << endl;
	for (int i=0; i < n; i++)
	{
		cout << i + 1 << ". " << sv[i];
	}
}