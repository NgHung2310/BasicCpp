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
	friend istream &operator>>(istream &is, DaThuc3 &dt)
	{
		cout << "Nhap da thuc theo dang ax3+bx2+cx+d: ";
		is >> dt.a >> dt.b >> dt.c >> dt.d;
		return is;
	}
	friend ostream &operator<<(ostream &os, DaThuc3 dt)
	{
		os << "Da thuc: " << dt.a << "x3 + " <<dt. b << "x2 + " << dt.c << "x + " << dt.d << endl;
		return os;
	}
	friend DaThuc3 tong2dt(DaThuc3 dt1, DaThuc3 dt2)
	{
		DaThuc3 temp;
		temp.a = dt1.a + dt2.a;
		temp.b = dt1.b + dt2.b;
		temp.c = dt1.c + dt2.c;
		temp.d = dt1.d + dt2.d;
		return temp;
	}
	friend DaThuc3 hieu2dt(DaThuc3 dt1, DaThuc3 dt2)
	{
		DaThuc3 temp;
		temp.a = dt1.a - dt2.a;
		temp.b = dt1.b - dt2.b;
		temp.c = dt1.c - dt2.c;
		temp.d = dt1.d - dt2.d;
		return temp;

	}
};
int main()
{
	DaThuc3 dt1, dt2;
	cin >> dt1;
	cin >> dt2;
	cout << "Da thuc 1:" << dt1 << endl;
	cout << "Da thuc 2:" << dt2 << endl;

	DaThuc3 dt_tong=tong2dt(dt1, dt2);
	DaThuc3 dt_hieu=hieu2dt(dt1, dt2);
	cout << "Tong 2 da thuc: " << dt_tong << endl;
	cout << "Hieu 2 da thuc: " << dt_hieu << endl;
}
