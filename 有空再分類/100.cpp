#include<iostream>
#include<vector>//vector皚 
#include<algorithm>//reverse
using namespace std;
int main()
{

 vector<int> a;//a皚箇砞⊿Τだ皌癘拘砰 
 a.push_back(1);// 糤じ1程 
 int b,i;
 for (b=1;b<=100;b++)
 {
  for (i=0;i<a.size();i++)
  {
   a[i]*=b;
  }
  for (i=0;i<a.size();i++)
  {
   if (a[i]>9)
   {
    if (a.size()==i+1)//a.size()琌a皚じ计碞琌Τ碭计種 
     a.push_back(a[i]/10);// 糤じ(a[i]/10)程 秈 
    else
     a[i+1]+=a[i]/10;
    a[i]=a[i]%10;
   }
  }
 }
 	//猔種硂糶猭琌筁ㄓ糶┮ 1231 琌计2琌计3琌κ计 
 reverse(a.begin(),a.end());//陆锣眖材じ挡Юじ 
 for (i=0;i<a.size();i++)
 {
  cout << a[i];
 }
 return 0;
}
