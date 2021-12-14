#include<string>
#include <iostream>
using namespace std;
struct Date
{
	int dd, mm, yy;
};
class KhachHang
{
protected:
	string ma_kh, ho_ten;
	Date ngay_ra_hoa_don;
public:
	KhachHang()
	{
		this->ma_kh = "";
		this->ho_ten = "";
		this->ngay_ra_hoa_don.dd = 0;
		this->ngay_ra_hoa_don.mm = 0;
		this->ngay_ra_hoa_don.yy = 0;
	}
	KhachHang(string ma_kh, string ho_ten, Date ngay_ra_hoa_don)
	{
		this->ma_kh = ma_kh;
		this->ho_ten = ho_ten;
		this->ngay_ra_hoa_don = ngay_ra_hoa_don;
	}
	~KhachHang() {}
	virtual void nhap()
	{
		cin.ignore();
		cout << "\tNhap ma khach hang: "; getline(cin, ma_kh);
		cout << "\tNhap ho ten khach hang: "; getline(cin, ho_ten);
		cout << "\tNhap ngay ra hoa don (dd/mm/yyyy): " << endl;
		cin >> ngay_ra_hoa_don.dd
			>> ngay_ra_hoa_don.mm
			>> ngay_ra_hoa_don.yy;
	}
	virtual void xuat()
	{
		cout << "\tMa KH: " << ma_kh
			<< "\t\tHo ten: " << ho_ten
			<< "\t\tHoa don ngay: "
			<< ngay_ra_hoa_don.dd << "/"
			<< ngay_ra_hoa_don.mm << "/"
			<< ngay_ra_hoa_don.yy;
	}
	virtual float thanh_tien() = 0;
	virtual string loai_kh() = 0;
	int get_ngay()
	{ 
		return ngay_ra_hoa_don.dd; 
	}
	int get_thang()
	{
		return ngay_ra_hoa_don.mm;
	}
	int get_nam()
	{
		return ngay_ra_hoa_don.yy;
	}
};

class KHVietNam :public virtual KhachHang
{
	string doi_tuong_kh;
	float so_luong, don_gia, dinh_muc;
public:
	KHVietNam() 
	{
		this->doi_tuong_kh = "";
		this->so_luong = 0;
		this->don_gia = 0;
		this->dinh_muc = 0;
	}
	KHVietNam(string doi_tuong_kh, float so_luong, float don_gia, float dinh_muc)
		:KhachHang(ma_kh, ho_ten, ngay_ra_hoa_don)
	{
		this->doi_tuong_kh = doi_tuong_kh;
		this->so_luong = so_luong;
		this->don_gia = don_gia;
		this->dinh_muc = dinh_muc;
	}
	~KHVietNam() {}
	void nhap()
	{
		KhachHang::nhap();
		cin.ignore();
		cout << "\tNhap doi tuong khach hang (sinh hoat, kinh doanh, san xuat): "; getline(cin, doi_tuong_kh);
		cout << "\tNhap so luong: "; cin >> so_luong;
		cout << "\tNhap don gia: "; cin >> don_gia;
	}
	void xuat()
	{
		KhachHang::xuat();
		cout << "\t\tDoi tuong khach hang: " << doi_tuong_kh
			<< "\tSo luong: " << so_luong
			<< "\tDon gia: " << don_gia << endl;
	}
	float thanh_tien()
	{
		if (so_luong <= dinh_muc)
			return so_luong * don_gia;
		return don_gia * dinh_muc + (so_luong - don_gia) * don_gia * 2.5;
	}
	string loai_kh()
	{
		return "Viet Nam";
	}
};

class KHNuocNgoai :public virtual KhachHang
{
	string quoc_tich;
	float so_luong, don_gia;
public:
	KHNuocNgoai() 
	{
		this->quoc_tich = "";
		this->so_luong = 0;
		this->don_gia = 0;
	}
	KHNuocNgoai(string quoc_tich, float so_luong, float don_gia)
		:KhachHang(ma_kh, ho_ten, ngay_ra_hoa_don)
	{
		this->quoc_tich = quoc_tich;
		this->so_luong = so_luong;
		this->don_gia = don_gia;
	}
	~KHNuocNgoai() {}
	void nhap()
	{
		KhachHang::nhap();
		cin.ignore();
		cout << "\tNhap quoc tich: "; getline(cin, quoc_tich);
		cout << "\tNhap so luong: "; cin >> so_luong;
		cout << "\tNhap don gia: "; cin >> don_gia;
	}
	void xuat()
	{
		KhachHang::xuat();
		cout << "\t\tQuoc tich: " << quoc_tich
			<< "\tSo luong: " << so_luong
			<< "\tDon gia: " << don_gia << endl;
	}
	float thanh_tien()
	{
		return so_luong * don_gia;
	}
	string loai_kh()
	{
		return "nuoc ngoai";
	}
};

class MENU
{
	int n;
	KhachHang* kh[50];
public:	
	void nhap_ds()
	{
		int i = 0;
		int selecter;
		while (true)
		{
			cout << "\n1. KH Viet Nam"
				<< "\n2. KH nuoc ngoai"
				<< "\n3. Thoat"
				<< "\nNhap lua chon: ";
			cin >> selecter;
			if (selecter == 1)
				kh[i] = new KHVietNam;

			else if (selecter == 2)		
				kh[i] = new KHNuocNgoai;
			else if (selecter == 3)
				break;
			else
			{
				cout << " - Nhap khong hop le!!" << endl;
				continue;
			}
			kh[i]->nhap();
			i++;
			n = i;
		}
	}
	void xuat_ds()
	{
		for (int i = 0; i < n; i++)
		{
			cout << i + 1;
			kh[i]->xuat();
		}
	}
	//tinh so luong tung loai kh
	int so_luong_kh_VN()
	{
		int idx=0;
		for (int i = 0; i < n; i++)
		{			
			if (kh[i]->loai_kh() == "Viet Nam")
				idx++ ;
		}
		return idx;
	}
	int so_luong_kh_nn()
	{
		int idx = 0;
		for (int i = 0; i < n; i++)
		{
			if (kh[i]->loai_kh() == "nuoc ngoai")
				idx++;
		}
		return idx;
	}
	//trung binh thanh tien cua kh nuoc ngoai
	float tb_thanh_tien_kh_nuoc_ngoai()
	{
		float sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (kh[i]->loai_kh() == "nuoc ngoai")
				sum += kh[i]->thanh_tien();
		}
		return sum / so_luong_kh_nn();
	}
	//xuat hoa don thang 09/2013
	void xuat_hoa_don_09_2013()
	{
		for (int i = 0; i < n; i++)
		{
			if (kh[i]->get_thang() == 9 && kh[i]->get_nam() == 2013)
				kh[i]->xuat();
		}
	}
};
int main()
{
	MENU* p=new MENU;
	cout << "-----Nhap DS khach hang-----" << endl;
	p->nhap_ds();
	cout << "\n-----Xuat DS khach hang-----" << endl;
	p->xuat_ds();
	cout << "\n-----So luong KH Viet Nam: " 
		<< p->so_luong_kh_VN() << endl;
	cout << "\n-----So luong KH nuoc ngoai: "
		<< p->so_luong_kh_nn() << endl;
	cout << "\n-----Trung binh thanh tien cua KH nuoc ngoai: "
		<< p->tb_thanh_tien_kh_nuoc_ngoai() << endl;
	cout << "\n-----Hoa don thang 09/2013-----" << endl;
	p->xuat_hoa_don_09_2013();
}