#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct SinhVien {
	char hoDem[25], ten[9], gioitinh[5];
	int maSV, namsinh;
	double diemTK;
};
struct List {
	SinhVien info;
	Node *next
};
typedef Node *TRO;
TRO L; 

void creat(TRO &L) {	//khoi tao danh sach rong
	L = NULL;
}
int empty(TRO L) {
	return L == NULL;
}

void travel(TRO L) {
	TRO Q;
	if(!empty(L)) {
		Q = L;
		while(Q != NULL){
			Q = Q -> next;
		}
	}
}

int main() {
	
}
