 
 #include<iostream>
using namespace std;
int pow_mod(int a,int b,int c);
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<pow_mod(a,b,10007)<<endl; 
}
int pow_mod(int a,int b,int c)
  {
      int ans=1;  
    a=a%c;   
     while(b!=0)
     {
         if(b&1) 
         {
            ans=(ans*a)%c; 
         }
         b>>=1;    
         a=(a*a)%c;  
     }
     return ans;
}
