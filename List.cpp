#include <bits/stdc++.h>


using namespace std;

struct SinhVien {
	char hoDem[25], ten[15], gt[5];
	int maSV, yob;
	double gpa;
};

struct Node {
	SinhVien infor;
	Node *next;
};

typedef Node* tro;

void creat(tro &L);	//tao danh sach rong
int empty(tro L);	//kiem tra danh sach day
SinhVien taoSV(int ma, char *hodem, char *ten, char *gt, int yob, double gpa);	//tao sinh vien theo khuon
void add(tro &L, SinhVien sv);
void taoDS(tro &L);
void hienthiSinhVien(SinhVien sv);
void hienthidanhSach(tro L);
void xoaPTdautien(tro &L);
tro search_k(tro L, int k);	//tim den vi tri thu k - 1
void insert(tro &L, tro Q, SinhVien sv);
void chenVaoViTriThuBa(tro &L);
void sapxepchon(tro &L);

void xoaViTriThu3(tro &L);

int main() {
	tro L;
	creat(L);
	taoDS(L);
	hienthidanhSach(L);
	cout << "--------------------" << endl;
	xoaPTdautien(L);
	hienthidanhSach(L);
	cout << "--------------------" << endl;
	chenVaoViTriThuBa(L);
	hienthidanhSach(L);
	cout << "--------------------" << endl;
//	cout << "Sinh vien vi tri thu Ba: " << endl;
////	hienthiSinhVien(search_k(L, 4)->infor);
	cout << "Sap xep: " << endl;
	sapxepchon(L);
	hienthidanhSach(L);
	cout << "Xoa vi tri thu ba: " << endl;
	xoaViTriThu3(L);
	hienthidanhSach(L);
}

void creat(tro &L) {
	L = NULL;
}

int empty(tro L) {
	return L == NULL;
}

SinhVien taoSV(int ma, char *hodem, char *ten, char *gt, int yob, double gpa) {
	SinhVien sv;
	sv.maSV = ma;
	strcpy(sv.hoDem, hodem);
	strcpy(sv.ten, ten);
	strcpy(sv.gt, gt);
	sv.yob = yob;
	sv.gpa = gpa;
	return sv;
}

void add(tro &L, SinhVien sv) {
	tro Q = L, P = new Node;
	P -> infor = sv;
	P -> next = NULL;
	if(empty(L))
		L = P;
	else{
		while(Q -> next != NULL)
			Q = Q -> next;
		Q -> next = P;
	}
}

void taoDS(tro &L) {
	add(L, taoSV(1001, "Tran Van", "Thanh", "Nam", 1999, 7.5));
	add(L, taoSV(1002, "Nguyen Thi", "Huong", "Nu", 2000, 7.3));
	add(L, taoSV(1003, "Nguyen Van", "Binh", "Nam", 1998, 6.4));
	add(L, taoSV(1004, "Bui Thi", "Hong", "Nu", 2000, 5.8));
	add(L, taoSV(1005, "Duong Van", "Giang", "Nam", 1998, 8.3));
}

void hienthiSinhVien(SinhVien sv) {
	printf("|%-15d|%-15s|%-15s|%-15s|%-15d|%-15.1f|\n", sv.maSV, sv.hoDem, sv.ten, sv.gt, sv.yob, sv.gpa);
}

void hienthidanhSach(tro L) {
	printf("|%-15s|%-15s|%-15s|%-15s|%-15s|%-15s|\n", "MA SV", "HO DEM", "TEN", "GIOI TINH", "NAM SINH", "DIEM TONG KET");
	tro Q = L;
	while(Q != NULL){
		hienthiSinhVien(Q -> infor);
		Q = Q -> next;
	}

}

void xoaPTdautien(tro &L){
	if(empty(L)){
		cout << "Danh sach rong" << endl;
		return;
	}
	tro Q = L;
	L = L -> next;
	delete Q;
//	tro Q = search_k(L, 3);
//	tro M = Q -> next;
//	Q -> next = M -> next;
//	delete M;	
}

tro search_k(tro L, int k) {
	int d = 1;
	tro Q = L;
	while(d < k - 1 && Q -> next != NULL){
		d++;
		Q = Q -> next;
	}
	if(d < k - 1){
		return NULL;
	}
	return Q;
}

void insert(tro &L, tro Q, SinhVien sv){
	tro P;
	P = new Node;
	P -> infor = sv;
	P -> next = Q -> next;
	Q -> next = P;
}

void chenVaoViTriThuBa(tro &L){
	tro Q = search_k(L, 3);
	if(Q == NULL){
		cout << "Khong tim thay vi tri chen" << endl;
		return;
	}
	insert(L, Q, taoSV(1006, "Le Thi", "Doan", "Nu", 1998, 7.6));
}

void sapxepchon(tro &L){
	tro P, Q, M;
	P = L;
	while(P -> next != NULL){
		M = P;
		Q = P -> next;
		while(Q != NULL){
			if(strcmp(Q -> infor.ten, M -> infor.ten) < 0)
				M = Q;
		
		Q = Q -> next;
	}
	SinhVien tg = P -> infor;
	P -> infor = M -> infor;
	M -> infor = tg;
	P = P -> next;
	
		
}
}

void xoaViTriThu3(tro &L) {
	tro P, Q;
	Q = L -> next;
	P = Q -> next;
	Q -> next = P -> next;
	delete P;
}


