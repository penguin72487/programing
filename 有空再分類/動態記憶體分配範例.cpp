#include<iostream>
using namespace std;
int main()
{
	int* p = new int ;//�@�� 
	delete p;
	
	
	
	int* it= new int [1000000000];//�@���}�C 
	delete [] it;
	
	
	
	int** jt= new int* [10];//�G���}�C10*10
	for(int i=0;i<10;i++)
	{
		*(jt+i)=new int [10];
	} 
	for(int i=0;i<10;i++)
	{
		delete [] *(jt+i);
	} 
	delete [] jt;
}

