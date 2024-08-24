#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX 8

struct SinhVien {
	char id[10], last_name[30], gioi_tinh[5], name[15];
	int yob;
	double gpa;
};

struct List {
	int count;
	SinhVien e[MAX];
};

void create(List &L);		 	// khoi tao danh sach rong
int empty(List &L); 			// kiem tra danh sach day
int full(List L); 				//kiem tra danh sach day
int add(List &L, SinhVien sv);	//them mot phan tu vao cuoi danh sach
SinhVien taoSV(char *id, char *lastName, char *name, char *gioitinh, int yob, double gpa);	//tao mot sinh vien moi
void input(List &L); 			// nhap du lieu sinh vien
void hien_thi_SV(SinhVien sv);	//hien thi thong tin cua mot sinh vien
void hien_thi_DS(List L);		//hien thi danh sach sinh vien
void xoa_Sv_dautien(List &L);	//xoa sinh vien dau tien
void chenvaoViTriThuBa(List &L);	//chen them mot sinh vien vao vi tri thu ba
void sap_xep_theo_ten(List &L);		//sap xep danh sach sinh vien tang dan theo ten

int main() {
	List L;
	create(L);
	input(L);
	cout << "=====================DANH SACH SINH VIEN=============================" << endl;
	hien_thi_DS(L);
	cout << "====================================================================" << endl;
	cout << "==============DANH SACH SAU KHI XOA PHAN TU DAU TIEN=================" << endl;
	xoa_Sv_dautien(L);
	hien_thi_DS(L);
	cout << "======================================================================" << endl; 
	cout << "===========CHEN THEM SINH VIEN VAO VI TRI THU BA=======================" << endl;
	chenvaoViTriThuBa(L);
	hien_thi_DS(L);
	cout << "============SAP XEP THEO TEN TANG DAN==================================" << endl;
	sap_xep_theo_ten(L);
	hien_thi_DS(L);
}


void create(List &L) {	//khoi tao danh sach rong
	L.count = -1;	
}

int empty(List &L) {	//kiem tra danh sach rong
	return L.count == -1;
}

int full(List L) {		//kiem tra danh sach day
	return L.count == MAX - 1;
}

int add(List &L, SinhVien sv) {	//them mot sinh vien vao cuoi danh sach
	if(full(L))
		return 0;
	else {
		L.count ++;
		L.e[L.count] = sv;
		return 1;
	}
}

SinhVien taoSV(char *id, char *lastName, char *name, char *gioitinh, int yob, double gpa) {	//tao moi mot sinh vien
	SinhVien sv;
	strcpy(sv.id, id);
	strcpy(sv.last_name, lastName);
	strcpy(sv.name, name);
	strcpy(sv.gioi_tinh, gioitinh);
	sv.yob = yob;
	sv.gpa = gpa;
	return sv;
}

void input(List &L) {
	add(L, taoSV("SV1001", "Tran Van", "Thanh", "Nam", 1999, 7.5));
	add(L, taoSV("SV1002", "Nguyen Thi", "Huong", "Nu", 2000, 7.3));
	add(L, taoSV("SV1003", "Nguyen Van", "Binh", "Nam", 1998, 6.4));
	add(L, taoSV("SV1004", "Bui Thi", "Hong", "Nu", 2000, 5.8));
	add(L, taoSV("SV1005", "Duong Van", "Giang", "Nam", 1998, 8.3));
}

void hien_thi_SV(SinhVien sv) {
	printf("|%-10s|%-10s|%-10s|%-10s|%-10d|%-15.1f|\n", sv.id
	, sv.last_name, sv.name, sv.gioi_tinh, sv.yob, sv.gpa);
	
}

void hien_thi_DS(List L) {
	printf("|%-10s|%-10s|%-10s|%-10s|%-10s|%-15s|\n", "MA SV"
	, "HO VA DEM", "TEN", "GIOI TINH", "NAM SINH", "DIEM TONG KET");
	for(int i = 0; i <= L.count; i++)
		hien_thi_SV(L.e[i]); 
}

void xoa_Sv_dautien(List &L) {
	if(empty(L)) {
		cout << "DS rong";
		return;
	}
	for(int i = 1; i <= L.count; i++){
		L.e[i - 1] = L.e[i];
	}
	L.count--;
}

void chenvaoViTriThuBa(List &L) {
	SinhVien sv = taoSV("SV1006", "Le Thi", "Doan", "Nu", 1998, 7.6);
	for(int i = L.count; i >= 2; i--)
		L.e[i + 1] = L.e[i];
	L.e[2] = sv;
	L.count++;
}

void sap_xep_theo_ten(List &L) {
	for(int i = 0; i < L.count; i++){
		int m = i;
		for(int j = i + 1; j <= L.count; j++)
			if(strcmpi(L.e[j].name, L.e[m].name) < 0)
				m = j;
		SinhVien tg = L.e[i];
		L.e[i] = L.e[m];
		L.e[m] = tg;
	}
		
}
















