#include <iostream>
#include<math.h>
using namespace std;
class DaThuc3
{
	int a, b, c, d;
public:
	DaThuc3()
	{
		this->a = this->b = this->c = this->d = 0;
	}	
	//DaThuc3(int a=0,int b=0,int c =0,int d=0)
	//{
	//	this->a = a;
	//	this->b = b;
	//	this->c = c;
	//	this->d = d;
	//}

	friend istream &operator>>(istream &is, DaThuc3 &dt)
	{
		cout << " theo dang ax3+bx2+cx+d: ";
		is >> dt.a >> dt.b >> dt.c >> dt.d;
		return is;
	}
	friend ostream &operator<<(ostream &os, DaThuc3 dt)
	{
		os << "Da thuc: " << dt.a << "x3 + " << dt.b << "x2 + " << dt.c << "x + " << dt.d << endl;
		return os;
	}
	DaThuc3 operator+(DaThuc3 &ps)
	{
		DaThuc3 temp;
		temp.a = this->a + ps.a;
		temp.b = this->b + ps.b;
		temp.c = this->c + ps.c;
		temp.d = this->d + ps.d;
		return temp;
	}
	DaThuc3 operator-(DaThuc3 &ps)
	{
		DaThuc3 temp;
		temp.a = this->a - ps.a;
		temp.b = this->b - ps.b;
		temp.c = this->c - ps.c;
		temp.d = this->d - ps.d;
		return temp;

	}
};
int main()
{
	DaThuc3 dt, dt1, dt2;
	cout << "Da thuc 1"; cin >> dt1;
	cout << "Da thuc 2"; cin >> dt2;
	cout << "Da thuc vua nhap: " << endl;
	cout << dt1 << endl;
	cout << dt2 << endl;
	dt = dt1 + dt2;
	cout << "Tong: " << dt << endl;
	dt = dt1 - dt2;
	cout << "Hieu: " << dt << endl;
}

