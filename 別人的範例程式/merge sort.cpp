#include <iostream>
using namespace std;

void Merge_Sort(int A[],int p,int q);
void Merge(int A[], int p, int q, int m);

int main() {
	int A[11] = {23,3,5,7,9,8,10,20,31,2,15};
	cout << "排序前...";
	for (int i = 0; i < 11; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	Merge_Sort(A, 0, 10);
	cout << "排序後...";
	for (int i = 0; i < 11; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}


void Merge_Sort(int A[], int p, int q) {
	if (p < q) {
		int m = (p + q) / 2;
		Merge_Sort(A, p, m);  //遞迴排序子陣列 A[p...m]
		Merge_Sort(A, m + 1, q); //遞迴排序子陣列 A[m+1...q]
		Merge(A, p, q, m);  //將左右兩個以排序好的子陣列合併
	}
}
void Merge(int A[], int p, int q, int m) {
	int n1 = m - p + 1;
	int n2 = q - m;
	/*Let L[0...n1] and R[0...n2] be new arrays
	and copy A[p...m] to L[0...n1] 
	and copy A[m+1...q] to R[0...n2] */
	int* L = new int[n1];
	int* R = new int[n2];

	for (int i = 0; i < n1; i++) {
		L[i] = A[p+i]; 
	}
	for (int i = 0; i < n2; i++) {
		R[i] = A[i+m+1]; 
	}
	L[n1] = 2147483647;
	R[n2] = 2147483647;
	int i = 0, j = 0;
	for (int k = p; k <= q; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
}
