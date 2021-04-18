#include <iostream>
using namespace std;

void Merge_Sort(int A[],int p,int q);
void Merge(int A[], int p, int q, int m);

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	Merge_Sort(a, 0, 10);
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	return 0;
}


void Merge_Sort(int A[], int p, int q) {
	if (p < q) {
		int m = (p + q) / 2;
		Merge_Sort(A, p, m);  //���j�ƧǤl�}�C A[p...m]
		Merge_Sort(A, m + 1, q); //���j�ƧǤl�}�C A[m+1...q]
		Merge(A, p, q, m);  //�N���k��ӥH�ƧǦn���l�}�C�X��
	}
}
void Merge(int A[], int p, int q, int m) {
	int n1 = m - p + 1;
	int n2 = q - m;
	/*Let L[0...n1] and R[0...n2] be new arrays
	and copy A[p...m] to L[0...n1] 
	and copy A[m+1...q] to R[0...n2] */
	int* L = new int[n1+1];
	int* R = new int[n2+1];

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
	delete [] L;
     delete [] R;
}
