#include<iostream>
#include<math.h>

using namespace std;

void nhapSo(int &n);
void hello();
long tinhGT(int n);				//tinh n!
long tinhFibonaci(int n);		// tim so fibonaci thu n
void giaiBaiToanThapHaNoi(int n, char A, char B, char C); // n la so dia can chuyen
float tinhAcker(int m, int n);


int main() {
	//hello();
	int n, m;
	//nhapSo(n);
	//cout << n << "! = " << tinhGT(n);
	//cout << tinhFibonaci(n);
	//giaiBaiToanThapHaNoi(n, 'A', 'B', 'C');
	cout << "Acker = " << tinhAcker(3, 5);
	
}

void nhapSo(int &n) {
	cout << "n = ";
	cin >> n;
}

void hello() {
	cout << "Hello world";
	hello();
}

long tinhGT(int n) {
	if(n == 0)
		return 1;
	else	
		return n * tinhGT(n - 1);
}

long tinhFibonaci(int n) {
	if(n <= 2)
		return 1;
	else
		return tinhFibonaci(n - 2) + tinhFibonaci(n - 1);
}

void giaiBaiToanThapHaNoi(int n, char A, char B, char C) {
	if(n == 1)
		cout << "Chuyen 1 dia tu " << A << " sang " << C << endl;
	else {
		giaiBaiToanThapHaNoi(n - 1, A, C, B);
		giaiBaiToanThapHaNoi(1, A, B, C);
		giaiBaiToanThapHaNoi(n - 1, B, A, C);
	}
		
}

float tinhAcker(int m, int n) {
	if(m == 0)
		return (n + 1);
	else if(n == 0)
		return tinhAcker(m - 1, 1);
	else
		return tinhAcker(m - 1, tinhAcker(m, n - 1));
}





















