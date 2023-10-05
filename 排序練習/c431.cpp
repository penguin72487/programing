#include<stdio.h>
#include<algorithm>
using namespace std;
void swap(int& a,int& b)
{
	int t;
	t=a;
	a=b;
	b=t;
}
void qsort(int* arr,int arr_begin,int arr_end);
int sort_sol(int* arr,int arr_begin,int arr_end);
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
void qsort(int* arr,int arr_begin,int arr_end)
{
	
	if(arr_begin<arr_end)
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
		for(int j=arr_begin;j<arr_end;j++)
		{
			if(arr[j]<pivot)
			{
				i++;

				swap(arr[i],arr[j]);
 
			}
		}

		i++;
		swap(arr[i],arr[arr_end]);
		return i;
		
}
