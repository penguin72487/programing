#include<iostream>
using namespace std;
void swap(int a,int b)
{
	a^=b^=a^=b;
}
void qsort(int* arr,int arr_begin,int arr_end);
int sort_sol(int* arr,int arr_begin,int arr_end);
int main()
{
	int a[] = {10, 7, 8, 9, 1, 5};
	int n=6;
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void qsort(int* arr,int arr_begin,int arr_end)
{
	if(arr_end<arr_begin)
	{
		int p_index =sort_sol(arr,arr_begin,arr_end);
		qsort(arr,arr_begin,p_index-1);
		qsort(arr,p_index+1,arr_end);
			
	}
	
}
int sort_sol(int* arr,int arr_begin,int arr_end)
{
		int pivot=arr[arr_end];
		int i=arr_begin-1;
		for(int j=0;j<arr_end;j++)
		{
			if(arr[j]<=pivot)
			{
				i++;
				swap(arr[j],arr[i]);
			}
		}
		swap(arr[arr_end],arr[i+1]);
		return i+1;
		
}
