#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX 8
struct HangHoa {
	char mahang[10], tenhang[15], donvi[10];
	int soluong;
	double dongia;
	double tinhThanhTien(){
		return soluong * dongia;
	}
};

struct List {
	int count;
	HangHoa e[MAX];
};

void create(List &L); 	// khoi tao danh sach rong
int empty(List &L);		//kiem tra danh sach rong
int full(List &L);		//kiem tra danh sach day
int add(List &L, HangHoa hh); //them mot phan tu vao cuoi danh sach
HangHoa taoHH(char *maHang, char *tenHang, char* donvi, int soLuong, double donGia);	//tao mot hang hoa moi
void input(List &L);	//nhet hang hoa vao trong list
void inHangHoa(HangHoa hh);	//in du lieu cua mot hang hoa
void inDanhSach(List &L); // in du lieu cua danh sach hang hoa
void xoaPTThuBa(List &L);	//xoa phan tu thu ba trong danh sach
void chenHangHoa(List &L);	//chenvao vi tri dau tien trong danh sach
void sapXepHangHoa(List &L);	//sap xep giam dan bang noi bot


int main() {
	List L;
	create(L);
	input(L);
	cout << "DANH SACH HANG HOA: " << endl;
	inDanhSach(L);
	cout << "SAU KHI XOA PHAN TU THU BA: " << endl;
	xoaPTThuBa(L);
	inDanhSach(L);
	cout << "SAU KHI CHEN THEM HANG HOA MOI VAO DAU DANH SACH" << endl;
	chenHangHoa(L);
	inDanhSach(L);	
	cout << "SAP XEP GIAM DAN THEO THANH TIEN" << endl;
	sapXepHangHoa(L);
	inDanhSach(L);
	
}

void create(List &L) {	//khoi tao danh sach rong
	L.count = -1;
}

int empty(List &L) {	//kiem tra danh sach rong
	return L.count == -1;
}
	
int full(List &L) {		//kiem tra danh sach day
	return L.count == MAX - 1;
}

int add(List &L, HangHoa hh) {	//them mot phan tu vao cuoi danh sach
	if(full(L))
		return 0;
	else{
		L.count++;
		L.e[L.count] = hh;
		return 1;
	}
}

HangHoa taoHH(char *maHang, char *tenHang, char* donvi, int soLuong, double donGia) {
	HangHoa hh;
	strcpy(hh.mahang, maHang);
	strcpy(hh.tenhang, tenHang);
	strcpy(hh.donvi, donvi);
	hh.soluong = soLuong;
	hh.dongia = donGia;
	return hh;	
}

void input(List &L) {
	add(L, taoHH("H2001", "Vo", "Quyen", 20, 6500));
	add(L, taoHH("H2002", "But chi", "Cai", 50, 12000));
	add(L, taoHH("H2003", "Hop but", "Chiec", 15, 35000));
	add(L, taoHH("H2004", "Tay", "Cai", 50, 10000));
	add(L, taoHH("H2005", "Thuoc ke", "Cai", 55, 7000));
	add(L, taoHH("H2006", "Muc", "Lo", 28, 15000));
}

void inHangHoa(HangHoa hh) {
	printf("|%-15s|%-15s|%-15s|%-15d|%-15.1f|%-15.1f|\n", hh.mahang, 
	hh.tenhang, hh.donvi, hh.soluong, hh.dongia, hh.tinhThanhTien());
}

void inDanhSach(List &L) {
	
	printf("|%-15s|%-15s|%-15s|%-15s|%-15s|%-15s|\n", "MA HANG", "TEN HANG", 
	"DV TINH", "SO LUONG", "DON GIA", "THANH TIEN");
	for(int i = 0; i <= L.count; i++)
		inHangHoa(L.e[i]);
}

void xoaPTThuBa(List &L) {
	if(empty(L)){
		cout << "Danh sach rong";
		return;
		
	}
	for(int i = 3; i <= L.count; i++){
		L.e[i - 1] = L.e[i];
	}
	L.count--;
}

void chenHangHoa(List &L) {
	HangHoa hh = taoHH("H2007", "Phan", "Hop", 15, 3000);
	for(int i = L.count; i >= 0; i--)
		L.e[i + 1] = L.e[i];
	L.e[0] = hh;
	L.count++;
}

void sapXepHangHoa(List &L) {
	for(int i = 1; i < L.count + 1; i++)
		for(int j = L.count; j >= i; j--)
			if(L.e[j].tinhThanhTien() > L.e[j - 1].tinhThanhTien()){
				HangHoa tg = L.e[j];
				L.e[j] = L.e[j - 1];
				L.e[j - 1] = tg;
			}
	
	
}












































