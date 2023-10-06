#include<iostream>
#include<algorithm>
using namespace std;

void qsort(int* arr,int* arr_end);
int* sort_sol(int* arr,int* arr_end);
int main()
{
	int a[] = {1, 3, 7, 0, 4};
	int n=5;
	qsort(a,a+n);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
void qsort(int* arr,int* arr_end)
{
	
	if(arr<arr_end)
	{
		int* p_index =sort_sol(arr,arr_end);

		qsort(arr,p_index-1);
		qsort(p_index+1,arr_end);
			
	}
	
}
int* sort_sol(int* arr,int* arr_end)
{
		
		int* i=arr;
		for(int* j=arr;j<arr_end;j++)
		{
			if(*j<=*arr_end)
			{
				swap(i,j);
				i++;
 
			}
		}
		swap(i,arr_end);
		return i;
		
}
