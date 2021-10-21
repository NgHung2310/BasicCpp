#include<math.h>
#include <iostream>
using namespace std;
class SP
{
	float pt, pa;
public:
	//SP(){}
	//SP(float pt, float pa)
	//{
	//	this->pt = pt;
	//	this->pa = pa;
	//}
	//~SP() {}
	friend istream &operator>> (istream &is, SP &a)
	{
		cout << "Nhap phan thuc: ";
		is >> a.pt;
		cout << "Nhap phan ao: ";
		is >> a.pa;
		return is;
	}

	friend ostream &operator<<(ostream &os, SP a)
	{
		os << a.pt << " + " << a.pa << "*j" << endl;
		return os;
	}

};

int main()
{
	SP A, B;
	cout << "Nhap so phuc A: " << endl;
	cin >> A;
	cout << "Nhap so phuc B: " << endl;
	cin >> B;
	cout << "2 so phuc:" << endl;
	cout << A << B;
}

