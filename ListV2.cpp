#include <bits/stdc++.h>

using namespace std;

struct HangHoa {
	char tenHang[10], donVi[5];
	int maHang, soLuong;
	double donGia;
	double tinThanhTien() {
		return soLuong * donGia;
	}
};

struct Node {
	HangHoa infor;
	Node* next;
};

typedef Node* Tro;

void creat(Tro &L);	//tao danh sach rong
int empty(Tro L); // kiem tra danh sach rong
HangHoa taoHH(int mh, char* th, char* dv, double dg, int sl);
void add(Tro &L, HangHoa hh);	//them hang hoa vao cuoi danh sach
void taoDS(Tro &L);	//tao danh sach hang hoa
void hienThiHangHoa(HangHoa hh);	//hien thi thong tin hang hoa
void hienthiDanhSach(Tro L);		//hien thi danh sach thong tin hang hoa
Tro searh_k(Tro L, int k); // tim den vi tri thu k - 1
void chenVaoDauDanhSach(Tro &L, HangHoa hh);
void xoaPTThuBa(Tro &L);
void sapXepGiamDanNoiBot(Tro &L);

Tro timkiemTheoTen(Tro L, char* ten);


int main() {
	Tro L;
	creat(L);
	taoDS(L);
	cout << "__________DANH SACH HANG HOA__________" << endl;
	hienthiDanhSach(L);
	cout << "___DANH SACH HANG HOA SAU KHI XOA PHAN TU THU 3_______" << endl;
	xoaPTThuBa(L);
	hienthiDanhSach(L);
	cout << "__________DANH SACH HANG HOA SAU KHI CHEN__________" << endl;
	chenVaoDauDanhSach(L, taoHH(2007, "Phan", "Hop", 15, 3000));
	hienthiDanhSach(L);
	
	cout << "__________TIM KIEM HANG HOA THEO TEN (VO)__________" << endl;
	hienThiHangHoa((timkiemTheoTen(L, "Vo") -> infor));
}

void creat(Tro &L) {
	L = NULL;
}

int empty(Tro L) {
	return L == NULL;
}

HangHoa taoHH(int mh, char* th, char* dv, double dg, int sl) {
	HangHoa hh;
	hh.maHang = mh;
	strcpy(hh.tenHang, th);
	strcpy(hh.donVi, dv);
	hh.soLuong = sl;
	hh.donGia = dg;
	return hh;
}

void add(Tro &L, HangHoa hh) {
	Tro P, Q;
	Q = L;
	P = new Node;
	P -> infor = hh;
	P -> next = NULL;
	if(empty(L))
		L = P;
	else {
		while(Q -> next != NULL)
			Q = Q -> next;
		Q -> next = P;
	}
	
}

void taoDS(Tro &L) {
	add(L, taoHH(2001, "Vo", "Quyen", 6500, 20));
	add(L, taoHH(2002, "But Chi", "Cai", 12000, 50));
	add(L, taoHH(2003, "Hop But", "Chiec", 35000, 15));
	add(L, taoHH(2004, "Tay", "Cai", 10000, 50));
	add(L, taoHH(2005, "Thuoc Ke", "Cai", 7000, 55));
	add(L, taoHH(2006, "Muc", "Lo", 15000, 28));

}

void hienThiHangHoa(HangHoa hh) {
	printf("|%-10d|%-10s|%-10s|%-10.1f|%-10d|%-10.1f|\n", 
	hh.maHang, hh.tenHang, hh.donVi, hh.donGia, hh.soLuong, hh.tinThanhTien());
}

void hienthiDanhSach(Tro L) {
	printf("|%-10s|%-10s|%-10s|%-10s|%-10s|%-10s|\n", 
	"MA HANG", "TEN HANG", "DV TINH", "DON GIA", "SO LUONG", "THANH TIEN");
	Tro Q = L;
	while(Q != NULL){
		hienThiHangHoa(Q -> infor);
		Q = Q -> next;
	}			
}

Tro searh_k(Tro L, int k) {
	int d = 1;
	Tro Q = L;
	while(d < k - 1 && Q -> next != NULL){
		d++;
		Q = Q -> next;
	}
	if(d < k - 1)
		return NULL;
	return Q;
}

void chenVaoDauDanhSach(Tro &L, HangHoa hh) {
	Tro P = new Node;
	P -> infor = hh;
	P -> next = L;
	L = P;
}

void xoaPTThuBa(Tro &L) {
	Tro Q = searh_k(L, 3);
	Tro P = Q -> next;
	Q -> next = P -> next;
	delete P;
}

Tro timkiemTheoTen(Tro L, char* ten) {
	Tro Q; 
	Q = L; 
	while(Q != NULL){
		if((strcmp((Q -> infor).tenHang, ten) == 0))
			return Q;
		Q = Q -> next;
	}
	return NULL;
} 

void sapXepGiamDanNoiBot(Tro &L) {
	Tro P, Q;
	
}
