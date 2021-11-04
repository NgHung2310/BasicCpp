#include<iostream>
#include<string>
#include<math.h>
using namespace std;
class MayIn
{
protected:
	string so_hieu;
	int so_luong;
public:
	MayIn() 
	{
		this->so_hieu = "";
		this->so_luong = 0;
	}
	MayIn(string so_hieu) :so_luong(0)
	{
		this->so_hieu = so_hieu;
	}
	~MayIn() {}
	void nhapkho(int p)
	{
		so_luong += p;
	}
	void xuatkho(int p)
	{
		so_luong -= p;
	}
	void print()
	{
		cout << "So hieu: " << so_hieu 
			<< "\t\tSo luong: " << so_luong << endl;
	}
};
class MayInLaser :public virtual MayIn
{
protected:
	int dpi;
public:
	MayInLaser()
	{
		this->dpi = 0;
	}
	MayInLaser(string so_hieu, int dpi) :MayIn(so_hieu)
	{
		this->dpi = dpi;
	}
	~MayInLaser() {}
	void print()
	{
		cout << "So hieu: " << so_hieu
			<< "\tDPI: " << dpi 
			<< "\tSo luong: "<<so_luong
			<< endl;
	}
};
class MayInMau :public virtual MayIn
{
protected:
	int bang_mau;
public:
	MayInMau()
	{
		this->bang_mau = 0;
	}
	MayInMau(string so_hieu, int bang_mau) :MayIn(so_hieu)
	{
		this->bang_mau = bang_mau;
	}
	~MayInMau() {}
	void print()
	{
		cout << "So hieu: " << so_hieu 
			<< "\tBang mau: " << bang_mau
			<< "\tSo luong: " << so_luong
			<< endl;
	}
};
class MayInLaserMau :public MayInLaser, public MayInMau
{
public:
	MayInLaserMau(string so_hieu, int dpi, int bang_mau):MayIn(so_hieu),MayInLaser(so_hieu, dpi), MayInMau( so_hieu,  bang_mau)
	{}
	void print()
	{
		cout << "So hieu: " << so_hieu
			<< "\tDPI: " << dpi
			<< "\tBang mau: " << bang_mau
			<< "\tSo luong: " << so_luong
			<< endl;
	}
};
int main()
{
	MayIn may_in("Canon");
	MayInLaser may_in_laser("Panasonic",400);
	MayInMau may_in_mau("LG",20);
	MayInLaserMau may_in_laser_mau("Samsung",500,30);
	may_in.nhapkho(10);
	may_in.xuatkho(5);

	may_in_laser.nhapkho(20);
	may_in_laser.xuatkho(2);

	may_in_mau.nhapkho(15);
	may_in_mau.xuatkho(15);

	may_in_laser_mau.nhapkho(30);
	may_in_laser_mau.xuatkho(31);

	may_in.print(); cout << endl;
	may_in_laser.print(); cout << endl;
	may_in_mau.print(); cout << endl;
	may_in_laser_mau.print(); cout << endl;
}


