#include<iostream>
#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<string>
using namespace std;
class PET
{
protected:
	int tuoi;
	float can_nang;
public:
	PET()
	{
		this->tuoi = 0;
		this->can_nang = 0;
	}
	PET(int tuoi, float can_nang)
	{
		this->tuoi = tuoi;
		this->can_nang = can_nang;
	}
	~PET() {}
};
class Dog:public PET
{
	string mau_mat, so_thich;
public:
	Dog()
	{
		this->mau_mat = this->so_thich = "";
	}
	Dog(int tuoi, float can_nang, string mau_mat, string so_thich) :PET(tuoi, can_nang)
	{
		this->mau_mat = mau_mat;
		this->so_thich = so_thich;
	}
	~Dog() {}
	friend istream &operator>>(istream &is, Dog &dog)
	{
		cout << "Nhap tuoi: "; is >> dog.tuoi;
		cout << "Nhap can nang: "; is >> dog.can_nang;
		cout << "Nhap mau mat: "; cin.ignore(); getline(cin, dog.mau_mat);
		cout << "Nhap so thich: "; getline(cin, dog.so_thich);
		return is;
	}
	friend ostream &operator<<(ostream &os, Dog dog)
	{
		os << "Tuoi: " << dog.tuoi
			<< "\t\tCan nang: " << dog.can_nang
			<< "\tMau mat: " << dog.mau_mat
			<< "\tSo thich: " << dog.so_thich << endl;
		return os;
	}
	bool operator>(Dog dog)
	{
		if (this->can_nang > dog.can_nang)
			return 1;
		else
			return 0;
	}
	int get_tuoi()
	{
		return tuoi;
	}
	float get_can_nang()
	{
		return can_nang;
	}
};
int main()
{
	int n; cout << "-----Nhap so con Dog: "; cin >> n;
	Dog *dog = new Dog[n];
//Nhap ds
	for (int i = 0; i < n; i++)
	{
		cout << "\n-----Thong tin Dog thu " << i + 1 << ": " << endl;
		cin >> dog[i];
	}
//Xuat ds
	cout << "\n-----DS vua nhap: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ". " << dog[i];
	}
//Sap xep theo can nang
	cout << "\n-----DS sau sap xep: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (dog[i]> dog[i+1])
		{
			Dog tg;
			tg = dog[i];
			dog[i] = dog[i + 1];
			dog[i + 1] = tg;
			/*swap(dog[i], dog[i+1]);*/
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << dog[i];
	}
//Tim Dog cos tuoi tu 2 den 5
	cout << "\n-----Dog co tuoi tu 2 den 5: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (dog[i].get_tuoi() >= 2 && dog[i].get_tuoi() <= 5)
		{
			cout << dog[i];
		}
	}
//Tong can nang cua cac dog
	float sum=0;
	for (int i = 0; i < n; i++)
	{
		sum += dog[i].get_can_nang();
	}
	cout << "\n-----Tong can nang cua cac chiec Dog: " << sum << endl;
	return 0;
}