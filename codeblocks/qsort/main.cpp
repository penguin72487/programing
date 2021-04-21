#include<iostream>
using namespace std;

void qsort(int arr[],int arr_begin,int arr_end);
int sort_sol(int arr[],int arr_begin,int arr_end);
int main()
{
	int a[5] = {1, 3, 7, 0, 4};
	int n=5;
	qsort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void qsort(int arr[],int arr_begin,int arr_end)
{
	if(arr_begin<arr_end)
	{
		int p_index =sort_sol(arr,arr_begin,arr_end);
		qsort(arr,arr_begin,p_index-1);
		qsort(arr,p_index+1,arr_end);

	}

}
int sort_sol(int arr[],int arr_begin,int arr_end)
{
		int pivot=arr[arr_end];
		int i=arr_begin;
		for(int j=arr_begin;j<arr_end;j++)
		{
			if(arr[j]<=pivot)
			{

				arr[i]^=arr[j]^=arr[i]^=arr[j];
				i++;
			}
		}

		arr[i]^=arr[arr_end]^=arr[i]^=arr[arr_end];
		return i;

}
