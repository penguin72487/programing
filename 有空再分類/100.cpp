#include<iostream>
#include<vector>//vector�}�C 
#include<algorithm>//reverse
using namespace std;
int main()
{

 vector<int> a;//�ŧi�@�ӦW��a���}�C�A�w�]�S�����t�O���� 
 a.push_back(1);// �W�[�@�Ӥ�����1�b�̫᭱ 
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
    if (a.size()==i+1)//a.size()�Oa�}�C�������ӼơA�]�N�O���X��ƪ��N�� 
     a.push_back(a[i]/10);// �W�[�@�Ӥ�����(a[i]/10)�b�̫᭱ �A�N��i�� 
    else
     a[i+1]+=a[i]/10;
    a[i]=a[i]%10;
   }
  }
 }
 	//�`�N�o�Ӽg�k�O�˹L�Ӽg���A�ҥH 123�A1 �O�Ӧ�ơA2�O�Q��ơA3�O�ʦ�� 
 reverse(a.begin(),a.end());//½��q�Ĥ@�����쵲�������� 
 for (i=0;i<a.size();i++)
 {
  cout << a[i];
 }
 return 0;
}
