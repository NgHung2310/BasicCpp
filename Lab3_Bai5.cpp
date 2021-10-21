#include<iostream>
#include<math.h>
#include<iomanip>
#include<conio.h>
using namespace std;
int UCLN(int ts, int ms)
{
	for (int i = ts; i > 0; i--)
	{
		if (ts%i == 0 && ms%i == 0)
			return i;
	}
}

class PS
{
	int ts, ms;
public:
	PS(int ts=0,int ms=0)
	{
		this->ts = ts;
		this->ms = ms;
	}
	~PS() {}
	friend istream &operator>>(istream &nhap, PS &ps)
	{
		cout << "Nhap tu so: "; nhap >> ps.ts;
		cout << "Nhap mau so: "; nhap >> ps.ms;
		return nhap;
	}
	friend ostream &operator<<(ostream &xuat, PS ps)
	{
		xuat << "Phan so: " << ps.ts << "/" << ps.ms << endl;
		return xuat;
	}
	PS toigian()
	{
		PS temp;
		temp.ms = ms / UCLN(ms, ts);
		temp.ts = ts / UCLN(ms, ts);
		return temp;
	}
	PS operator+(PS &ps)
	{
		PS temp;
		temp.ts = ps.ts*this->ms + ps.ms*this->ts;
		temp.ms = ps.ms*this->ms;
		return temp.toigian();
	}
	PS operator-(PS &ps)
	{
		PS temp;
		temp.ts = ps.ts*this->ms - ps.ms*this->ts;
		temp.ms = ps.ms*this->ms;
		return temp.toigian();
	}
	PS operator*(PS &ps)
	{
		PS temp;
		temp.ts = ps.ts*this->ts;
		temp.ms = ps.ms*this->ms;
		return temp.toigian();
	}
	PS operator/(PS &ps)
	{
		PS temp;
		temp.ts = ps.ts*this->ms;
		temp.ms = ps.ms*this->ts;
		return temp.toigian();
	}
};
int main()
{
	PS ps, ps1, ps2;
	cin >> ps1 >> ps2;
	ps = ps1 + ps2;
	cout <<"Cong: "<< ps<<endl;
	ps = ps1 - ps2;
	cout << "Tru: " << ps << endl;
	ps = ps1 * ps2;
	cout << "Nhan: " << ps << endl;
	ps = ps1 / ps2;
	cout << "Chia: " << ps << endl;
	return 0;
}