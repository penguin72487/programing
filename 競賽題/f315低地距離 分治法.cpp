#include <iostream>

using namespace std;
unsigned long long  ans=0;
void merge_sort(int arr[],int op,int ed);
void mg(int arr[],int op,int mid,int ed);
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
   int n;
   cin>>n;
   n<<=1; 
   int line[n];
   for(int i=0;i<n;i++)
   {
       cin>>line[i];
   }
   int line2[n];
   for(int i=0;i<n;i++)
   {
       line2[i]=line[i];
   }
   merge_sort(line,0,n-1);
   cout<<ans<<endl;

}
void merge_sort(int arr[],int op,int ed)
{
    if(op<ed)
    {
        int mid=((op+ed)>>1);
        merge_sort(arr,op,mid);
        merge_sort(arr,mid+1,ed);
        mg(arr,op,mid,ed);
    }
}
void mg(int arr[],int op,int mid,int ed)
{

    int nl=mid-op+1;
    int nr=ed-mid;
    int* l=new int [nl+1];
    int* r=new int [nr+1];
    for(int i=0;i<nl;i++)
    {
        l[i]=arr[op+i];
    }
    for(int i=0;i<nr;i++)
    {
        r[i]=arr[mid+i+1];
    }
    l[nl]=2147483647;
    r[nr]=2147483647;
    int i=0,j=0;
    for(int k=op;k<ed;k++)
    {
        if(l[i]<r[j])
        {
            arr[k]=l[i];
            i++;
        }
        else if(l[i]==r[j])
        {
        	ans+=j+1;
        	arr[k]=l[i];
            i++;
		}
        else
        {
            arr[k]=r[j];
            j++;
        }
    }
    delete [] l;
    delete [] r;
}
