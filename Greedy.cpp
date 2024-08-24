#include<iostream>

using namespace std;

void nhapSoPT(int &n);
void nhapMang(int* a, int n);
void sapGiamDan(int* a, int n);	
int giaiBaiToanTinhTong(int* a, int n, int s);
int doiTien(int m);
int tinhSoManhBia(int m);

int main() {
//	int* a;
//	int n;
//	nhapSoPT(n);
//	a = new int[n];
//	nhapMang(a, n);
//	if(giaiBaiToanTinhTong(a, n, 10) != -1)
//		cout << "Can it nhat " << giaiBaiToanTinhTong(a, n, 10) << " so";
//	else
//		cout << "Tong cua day nho hon 10";
//	delete[] a;
//	cout << doiTien(50000);
	cout << tinhSoManhBia(2 * 3);
	
	
}

void nhapSoPT(int &n) {
	cout << "Nhap so PT mang: ";
	cin >> n;
}

void nhapMang(int* a, int n) {
	for(int i = 0; i < n; i++) {
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}


void sapGiamDan(int* a, int n) {		//Bubble sort
	for(int i = 1; i < n; i++)
		for(int j = n - 1; j >= i; j--)
			if(a[j] > a[j - 1]) {
				int tg = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tg;
			}
}

int giaiBaiToanTinhTong(int* a, int n, int s) {
	sapGiamDan(a, n);
	int i = 0;
	int sum = 0;
	while(i < n && sum <= s) {
		sum += a[i];
		i++;
	}
	if(sum > s)
		return i;
	else
		return -1;
}

int doiTien(int m) {
	int menhgia[] = {10000, 5000, 2000, 1000, 500};
	int n = 5; //so menh gia tien
	int dem = 0; // bien dem
	for (int i = 0; i < n; i++){
		int num = m / menhgia[i];
		m %= menhgia[i];
		dem += num;
		if (m == 0)
			break;
	}
	return dem;
}

int tinhSoManhBia(int m) {	//m: dien tich tam bia lam khuon ghep
	int manhbia[] = {4, 2, 1};
	int sum = 0; 	//tinh tong dien tich 3 tam bia
	int dem = 0;
	for (int i = 0; i < 3; i++){
		sum += manhbia[i];
		dem++;
		if(sum == m)
			break;
	}
	return dem;                                                
}

