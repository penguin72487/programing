#include<iostream>
using namespace std;
void merge_sort(int arr[],int arr_begin,int arr_end);//¶Çindex 
void merge(int arr[],int arr_begin,int arr_mid,int arr_end);
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void merge_sort(int arr[],int arr_begin,int arr_end)
{
	if(arr_begin<arr_end)
	{
		int arr_mid=(arr_begin+arr_end)/2;
		merge_sort(arr,arr_begin,arr_mid);
		merge_sort(arr,arr_mid+1,arr_end);
		merge(arr,arr_begin,arr_mid,arr_end);
	}	
}
void merge(int arr[],int arr_begin,int arr_mid,int arr_end)
{
	int nL=arr_mid-arr_begin+1;
	int nR=arr_end-arr_mid;
	int* l= new int[nL+1];
	int* r= new int[nR+1];
	for(int i=0;i<nL;i++)
	{
		l[i]=arr[arr_begin+i];
	}
	for(int i=0;i<nL;i++)
	{
		r[i]=arr[arr_mid+1+i];
	} 
	l[nL] = 2147483647;
	r[nR] = 2147483647;
	int i = 0, j = 0;
	for (int k = arr_begin; k <= arr_end; k++)
	{
		if (l[i] <= r[j]) {
			arr[k] = l[i];
			i++;
		}
		else {
			arr[k] = r[j];
			j++;
		}
	}
	 delete [] l;
     delete [] r;
}
