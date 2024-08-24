#include<iostream>

using namespace std;

void BubbleSort(int a[], int n);
void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
void xuatMang(int a[], int n);
int main() {
	int a[] = {34, 74, 94, 84, 54, 24};
	BubbleSort(a, 6);
	xuatMang(a, 6);
	int b[] = {50, 8, 34, 6, 98, 17, 83, 25, 66, 42, 21, 59, 63, 71, 85};
	SelectionSort(b, 15);
	xuatMang(b , 15);
	int c[] = {34, 14, 24, 54, 84, 64, 94, 74, 4};
	InsertionSort(c, 9);
	xuatMang(c, 9);
	
}

void xuatMang(int a[], int n) {
	for (int i = 0; i < n; i++)
		cout << "\t" << a[i];
	cout << endl;
}



void InsertionSort(int a[], int n) {
	for (int i = 1; i < n; i++){
		int tam = a[i];
		int j = i - 1;
		while(j > -1 && a[j] < tam){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tam;
	}
		
			
	}
		
		
	

void SelectionSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++){
		int m = i;
		for(int j = i + 1; j < n; j++)
			if(a[m] < a[j])
				m = j;
		int tg = a[m];
		a[m] = a[i];
		a[i] = tg;
		
	}
					
	
				
	
	
}




void BubbleSort(int a[], int n) {
	for(int i = 1; i < n; i++)
		for(int j = n - 1; j >= i; j--)
			if(a[j - 1] < a[j]){
				int tg = a[j];
				a[j] = a[j - 1];
				a[j - 1] = tg;
			}										
	
}


