#include<iostream>

using namespace std;

int searchTT(int a[], int n, int m);	//m la phan tu muon search

int main() {
	int a[] = {7, 5, 2005, 28, 11, 2005};
	if(searchTT(a, 6, 14) == -1)
		cout << "Khong tim thay";
	else
	{
		cout << "Co tim thay" << endl;
		cout << "o vi tri: " << searchTT(a, 6, 14);
	}
		
	
	
	
}

int searchTT(int a[], int n, int m) {
	for (int i = 0; i < n; i++){
		if(a[i] == m)
			return i  + 1;
	}
	return -1;
}
